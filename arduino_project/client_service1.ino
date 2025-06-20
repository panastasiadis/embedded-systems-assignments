const int buttonPinNew = A2;
const int buttonPinDone = A1; 
const int buttonPinReset = A0;

const int ledPin = A3; 

const int totalClientsPins[] = {6, 5, 4, 3, 2, A5, A4};
const int currentClientPins[] = {7, 8, 9, 10, 11, 12, 13};

int buttonStateNew = 0;  
int buttonStateDone = 0;
int buttonStateReset = 0;

const int max_clients = 10;

unsigned char current_client = 0;
unsigned char total_clients = 0;
bool full = false;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  
  // Initialize LED pins as outputs
  for (int i = 0; i < 8; i++) {
    pinMode(totalClientsPins[i], OUTPUT);   
  }
  for (int i = 0; i < 8; i++) {
    pinMode(currentClientPins[i], OUTPUT);   
  }
  
  // initialize the pushbutton pins as an input:
  pinMode(buttonPinNew, INPUT);
  pinMode(buttonPinDone, INPUT);
  pinMode(buttonPinReset, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonStateNew = digitalRead(buttonPinNew);
  buttonStateDone = digitalRead(buttonPinDone);
  buttonStateReset = digitalRead(buttonPinReset);

  if (buttonStateNew == HIGH)
  {
    Serial.println("NEW_CLIENT button pressed..");
    NewClientState();
  }
  else if (buttonStateDone == HIGH)
  {
    Serial.println("DONE button pressed..");
    ClientIsDoneState();
  }
  else if (buttonStateReset == HIGH)
  {
    Serial.println("RESET button pressed..");
    ResetState();
  }
}

void NewClientState(){
  Serial.println("New client is waiting in line..");
  
  if(total_clients+1 > max_clients)
  {
    SetFullState();
  }
  else
  {
    total_clients++;
  }
  
  PrintClients();
}

void ClientIsDoneState(){
  Serial.println("Client is done, getting next one..");
  
  if(current_client+1 > total_clients)
  {
    Serial.println("No client waiting in line!");
  }
  else
  {
    current_client++;
  }
  
  PrintClients();
}

void ResetState(){	
  Serial.println("Resetting..");
  
  current_client = 0;
  total_clients = 0;
  full = false;
  digitalWrite(ledPin, LOW);
  
  Serial.println("Reset is complete..");
  
  PrintClients();
}

void SetFullState(){
  if(full)
  {
    Serial.println("Reached maximum amount of clients, come back tomorrow!");
    return;
  }
  
  full = true;
  digitalWrite(ledPin, HIGH);
  Serial.println("Reached maximum amount of clients, come back tomorrow!");
}

void PrintClients(){
  
  SetTotalClientsLEDs();
  SetCurrentClientLEDs();
  
  Serial.println("-----------------------------------");
  Serial.print("Current client: ");
  Serial.println(current_client);
  
  Serial.print("Total clients: ");
  Serial.println(total_clients);
  Serial.println("-----------------------------------");
}

void SetTotalClientsLEDs(){
  
  for (int i = 0; i < 8; i++) {
    // Turn on or off the LED based on the bit value
    bool bit = (total_clients >> i) & 1;
    if (bit == 1 && totalClientsPins[i] != HIGH) {
    	digitalWrite(totalClientsPins[i], HIGH);  // Turn on the LED
    } 
    else if (bit == 0 && totalClientsPins[i] != LOW) {
      	digitalWrite(totalClientsPins[i], LOW);   // Turn off the LED
    }
  }
  
}

void SetCurrentClientLEDs(){
  
  for (int i = 0; i < 8; i++) {
    // Turn on or off the LED based on the bit value
    bool bit = (current_client >> i) & 1;
    if (bit == 1 && currentClientPins[i] != HIGH) {
    	digitalWrite(currentClientPins[i], HIGH);  // Turn on the LED
    } 
    else if (bit == 0 && currentClientPins[i] != LOW) {
      	digitalWrite(currentClientPins[i], LOW);   // Turn off the LED
    }
  }
  
}