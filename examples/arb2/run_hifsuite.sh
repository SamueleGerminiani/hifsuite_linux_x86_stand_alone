verilog2hif rtl/arb2.v --output arb2.hif.xml

ddt arb2.hif.xml --toplevel arb2 --output arb2.ddt.hif.xml

a2tool arb2.ddt.hif.xml --protocol CPP --toplevel arb2 --output arb2.ddt.a2t.hif.xml

muffin arb2.ddt.a2t.hif.xml --fault STUCK_AT --clock clk --toplevel arb2 --output arb2.ddt.a2t.muffin.hif.xml

hif2sc arb2.ddt.a2t.muffin.hif.xml --extensions cpp_hpp --directory injected


