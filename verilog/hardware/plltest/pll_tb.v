

module top();
	reg clk = 0;
    reg signalOut;

    main_pll pll_inst(.REFERENCECLK(clk),

					  .PLLOUTCORE(),
					  .PLLOUTGLOBAL(signalOut))
    
	always
		#0.5 clk = ~clk;
	
	initial begin
		$dumpfile ("pll.vcd");
		$dumpvars;

		#20

		$finish
	end

endmodule

