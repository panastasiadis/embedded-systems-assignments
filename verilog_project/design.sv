module ClientService(

  input wire btnNew,
  input wire btnDone,
  input wire btnReset,
  
  output reg [7:0] current_client = 0,
  output reg [7:0] total_clients = 0,
  
  output reg full = 1'b0
);
  
  parameter max_clients = 100;
  
  always @(posedge btnNew) begin
    
    $display("NEW_CLIENT button pressed..");
    
    if (total_clients < max_clients) begin
      total_clients <= total_clients + 1;
    end
    else begin
      $display("Reached maximum amount of clients, come back tomorrow!");
    end
    
    if (total_clients == max_clients  && full == 1'b0) begin
      full <= 1'b1;
      $display("-----------------------------------");
      $display("The light is turned on!");
      $display("Reached maximum amount of clients, come back tomorrow!");
      $display("-----------------------------------");
    end
    
    #1;
    $display("Current client: %d", current_client);
    $display("Total clients: %d", total_clients);
    $display("-----------------------------------");
    
  end
  
  always @(posedge btnDone) begin
    
    $display("DONE button pressed..");
    
    if (current_client + 1 > total_clients) begin
      $display("No client waiting in line!");
    end
    else begin
      current_client <= current_client + 1;
    end
    
    #1;
    $display("Current client: %d", current_client);
    $display("Total clients: %d", total_clients);
    $display("-----------------------------------");
    
  end
  
  always @(posedge btnReset) begin
    
    $display("RESET button pressed..");
    
    current_client = 0;
    total_clients = 0;
    full = 1'b0;
    
    #1;
    $display("The light is turned off!");
    $display("Current client: %d", current_client);
    $display("Total clients: %d", total_clients);
    $display("-----------------------------------");
    
  end
  
endmodule