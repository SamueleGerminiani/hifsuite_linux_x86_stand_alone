#include <stdlib.h>

#include <cstdio>
#include <fstream>
#include <utility>
#include <vector>
#include <filesystem>

#include "arb2.hpp"
#include "colors.hpp"
#include "cpptracer/tracer.hpp"
#include "muffin_dataTypes.hpp"

struct Internals {
  Internals() : state(0) {}
  Internals(bool state_) : state(state_) {}
  bool state;
};
using Sample = std::pair<arb2::arb2_iostruct, Internals>;
using Trace = std::vector<Sample>;

void setRandomInputs(arb2::arb2_iostruct& in) {
  in.req1 = rand() % 2;
  in.req2 = rand() % 2;
}
void setInputsFromTraceSample(arb2::arb2_iostruct& in,
                              const arb2::arb2_iostruct& dump) {
  in.req1 = dump.req1;
  in.req2 = dump.req2;
}

// returns true if two samples are equivalent
bool checkOutput(const arb2::arb2_iostruct& golden,
                 const arb2::arb2_iostruct& faulty) {
  if (golden.gnt1 != faulty.gnt1 || golden.gnt2 != faulty.gnt2) {
    return 0;
  }
  return 1;
}
void printSample(arb2::arb2_iostruct& in) {
  printf("req1: %d\n", in.req1);
  printf("req2: %d\n", in.req2);
  printf("gnt1: %d\n", in.gnt1);
  printf("gnt2: %d\n", in.gnt2);
}
static std::vector<bool> vcd_clk = {0};
static std::vector<bool> vcd_req1 = {0};
static std::vector<bool> vcd_req2 = {0};
static std::vector<bool> vcd_gnt1 = {0};
static std::vector<bool> vcd_gnt2 = {0};
static std::vector<bool> vcd_rst = {0};
static std::vector<bool> vcd_state = {0};

static cpptracer::TimeScale timeStep(1, cpptracer::TimeUnit::NS);

cpptracer::Tracer initVCDTrace(const std::string& name) {
  cpptracer::Tracer tracer(name, timeStep, "arb2_bench");
  tracer.addScope("arb2_");

  tracer.addTrace(vcd_clk, "clk");
  tracer.addTrace(vcd_req1, "req1");
  tracer.addTrace(vcd_req2, "req2");
  tracer.addTrace(vcd_gnt1, "gnt1");
  tracer.addTrace(vcd_gnt2, "gnt2");
  tracer.addTrace(vcd_rst, "rst");
  tracer.addTrace(vcd_state, "state");

  tracer.closeScope();
  tracer.createTrace();
  return tracer;
}

void updateVCDVariables(const Sample& sample) {
  auto in = sample.first;
  auto state = sample.second.state;

  vcd_clk[0] = in.clk;
  vcd_req1[0] = in.req1;
  vcd_req2[0] = in.req2;
  vcd_gnt1[0] = in.gnt1;
  vcd_gnt2[0] = in.gnt2;
  vcd_rst[0] = in.rst;
  vcd_state[0] = state;
}
bool areEquivalent(const Trace& t1, const Trace& t2) {
  if (t1.size() != t2.size()) {
    return false;
  }
  for (size_t i = 0; i < t1.size(); ++i) {
    const Sample& s1 = t1[i];
    const Sample& s2 = t2[i];
    if (s1.first.gnt1 != s2.first.gnt1 || s1.first.gnt2 != s2.first.gnt2 ||
        s1.second.state != s2.second.state || s1.first.req1 != s2.first.req1 ||
        s1.first.req2 != s2.first.req2) {
      return false;
    }
  }
  return true;
}

int main() {
  muffin::stuck_at = 0;
  muffin::hif_global_instance_counter = 0;

  // number of faulted instances created with muffin, 0 is the original design
  // without faults
  muffin::instance_number = 0;

  // faults
  int32_t cycles_number = 0;
  size_t traceLength = 1000 * 2;

  printf("Simulate golden\n");
  Trace golden_trace;

  bool clk = 0;

  arb2 arb2_instance;
  arb2_instance.initialize();
  arb2::arb2_iostruct in_rst_on(0, 1, 0, 0, 0, 0);
  arb2_instance.simulate(&in_rst_on, cycles_number);

  srand(0);

  std::vector<arb2::arb2_iostruct> trace;

  arb2::arb2_iostruct in;
  in.rst = 0;

  for (size_t k = 0; k < traceLength; ++k) {
    clk = !clk;
    in.clk = clk;

    // in
    if (!clk) {
      setRandomInputs(in);
    }

    arb2_instance.simulate(&in, cycles_number);
    golden_trace.push_back(std::make_pair(in, Internals(arb2_instance.state)));
  }

  // Simulate the design with faults (instance 1), we need to reuse the same
  // input trace
  muffin::instance_number = 1;
  size_t faultObserved = 0;
  std::vector<size_t> uncoveredFaults;
  std::vector<Trace> faultyTraces;
  std::cout << "Number of faults: " << arb2_instance.hif_fault_node.number
            << "\n";

  arb2::arb2_iostruct in_rst_on_f(clk, 1, 0, 0, 0, 0);
  for (muffin::fault_number = 0;
       muffin::fault_number < arb2_instance.hif_fault_node.number;
       ++muffin::fault_number) {
    Trace faulty_trace;
    muffin::hif_global_instance_counter = 0;
    printf("Simulating fault number '%ld:%ld'\n", muffin::instance_number,
           muffin::fault_number);

    clk = 0;
    arb2_instance.simulate(&in_rst_on_f, cycles_number);
    arb2 arb2_instance;
    arb2_instance.initialize();
    in.rst = 0;

    bool faultFound = 0;
    for (size_t k = 0; k < traceLength; ++k) {
      clk = !clk;
      in.clk = clk;

      // in
      if (!clk) {
        setInputsFromTraceSample(in, golden_trace[k].first);
      }

      arb2_instance.simulate(&in, cycles_number);

      faulty_trace.push_back(
          std::make_pair(in, Internals(arb2_instance.state)));

      // get the output
      if (clk) {
        if (!checkOutput(golden_trace[k].first, in)) {
          faultFound = 1;
        }
      }
    }

    if (faultFound) {
      faultyTraces.push_back(faulty_trace);
      ++faultObserved;
    } else {
      uncoveredFaults.push_back(muffin::fault_number);
    }
  }

  // remove redundant faulty traces
  for (auto it = faultyTraces.begin(); it != faultyTraces.end(); ++it) {
    for (auto it2 = it + 1; it2 != faultyTraces.end(); ++it2) {
      if (areEquivalent(*it, *it2)) {
        faultyTraces.erase(it2);
        --it2;
      }
    }
  }

  printf("Faults observed: %ld\n", faultObserved);
  for (auto fault : uncoveredFaults) {
    printf("Fault %ld not observed\n", fault);
  }

  //-------------------------------------------------------------------------
  // Dump traces to VCD
  // make traces directory if it does not exist
  if (!std::filesystem::exists("traces")) {
    std::filesystem::create_directory("traces");
  }

  auto tracer = initVCDTrace("traces/golden.vcd");
  double time = 0;
  for (auto& sample : golden_trace) {
    updateVCDVariables(sample);
    tracer.updateTrace(time);
    time += timeStep;
  }
  tracer.closeTrace();

  for (size_t i = 0; i < faultyTraces.size(); ++i) {
    time = 0;
    auto tracer = initVCDTrace("traces/fault_" + std::to_string(i) + ".vcd");
    for (auto& sample : faultyTraces[i]) {
      updateVCDVariables(sample);
      tracer.updateTrace(time);
      time += timeStep;
    }
    tracer.closeTrace();
  }

  return 0;
}
