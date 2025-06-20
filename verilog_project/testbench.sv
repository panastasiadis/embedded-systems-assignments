module ClientService_tb;
  
  reg btnNew, btnDone, btnReset;
  wire [7:0] current_client, total_clients;
  wire full;
  
  // Instantiate the module under test
  ClientService dut (
    .btnNew(btnNew),
    .btnDone(btnDone),
    .btnReset(btnReset),
    .current_client(current_client),
    .total_clients(total_clients),
    .full(full)
  );
  
  // Clock generation
  reg clk;
  always #5 clk = ~clk;
  
  // Stimulus generation
  initial begin
    clk = 0;
    btnNew = 0;
    btnDone = 0;
    btnReset = 0;
    
    // Press the "New" button 20 times
    repeat (20) begin
      #10 btnNew = 1;
      #10 btnNew = 0;
    end
    
    // Press the "Done" button 30 times
    repeat (30) begin
      #10 btnDone = 1;
      #10 btnDone = 0;
    end
    
    // Press the "New" button 5 times
    repeat (50) begin
      #10 btnNew = 1;
      #10 btnNew = 0;
    end
    
    // Press the "Done" button 5 times
    repeat (50) begin
      #10 btnDone = 1;
      #10 btnDone = 0;
    end
    
    // Press the "New" button 4 times
    repeat (40) begin
      #10 btnNew = 1;
      #10 btnNew = 0;
    end
    
     // Press the "Done" button 3 times
    repeat (40) begin
      #10 btnDone = 1;
      #10 btnDone = 0;
    end
    
    // Press the "Reset" button
    #10 btnReset = 1;
    #10 btnReset = 0;
    
    // Press the "New" button 5 times
    repeat (50) begin
      #10 btnNew = 1;
      #10 btnNew = 0;
    end
    
    // Press the "Done" button 5 times
    repeat (50) begin
      #10 btnDone = 1;
      #10 btnDone = 0;
    end
    
    // Press the "New" button 5 times
    repeat (50) begin
      #10 btnNew = 1;
      #10 btnNew = 0;
    end
    
    // Press the "Done" button 5 times
    repeat (50) begin
      #10 btnDone = 1;
      #10 btnDone = 0;
    end
    
    // Stop simulation
    #10 $finish;
  end
  
endmodule
