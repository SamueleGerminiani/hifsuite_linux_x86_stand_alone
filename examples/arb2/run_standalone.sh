hifsuite_bin/verilog2hif rtl/arb2.v --output arb2.hif.xml

hifsuite_bin/ddt arb2.hif.xml --toplevel arb2 --output arb2.ddt.hif.xml

hifsuite_bin/a2tool arb2.ddt.hif.xml --protocol CPP --toplevel arb2 --output arb2.ddt.a2t.hif.xml

hifsuite_bin/muffin arb2.ddt.a2t.hif.xml --fault STUCK_AT --clock clk --toplevel arb2 --output arb2.ddt.a2t.muffin.hif.xml

hifsuite_bin/hif2sc arb2.ddt.a2t.muffin.hif.xml --extensions cpp_hpp --directory injected

