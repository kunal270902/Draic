/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp-now-esp32-arduino-ide/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

#include <esp_now.h>
#include <WiFi.h>
int fwd = 23;
int rev = 18;
int right = 21;
int left = 4;
int sd = 15;
int su = 12;
int il = 34;
int ir = 32;
int bl = 25;
int br = 27;
// REPLACE WITH YOUR RECEIVER MAC Address
uint8_t broadcastAddress[] = {0xA4,0xE5,0x7C,0xBC,0x9C,0xCD};

// Structure example to send data
// Must match the receiver structure
typedef struct struct_message {
 int BTS,BTS1,FWD,REV,LEFT,RIGHT,BWD_LEFT,BWD_RIGHT,IR,IL;
} struct_message;

// Create a struct_message called myData
struct_message myData;

esp_now_peer_info_t peerInfo;

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
 int potValue ; 
void setup() {
  Serial.begin(115200);
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);
   pinMode(34,INPUT); //BTS
   pinMode(32,INPUT); //BTS1
   pinMode(25,INPUT); //FWD
   pinMode(27,INPUT); //REV
   pinMode(12,INPUT); //LEFT
   pinMode(23,INPUT); //RIGHT
   pinMode(21,INPUT); //BWD_LEFT
   pinMode(18,INPUT); //BWD_RIGHT
   pinMode(4,INPUT); //IR
   pinMode(15,INPUT); //IL
  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
}

   


void loop() {
  // Set values to send
  myData.BTS = digitalRead(su);
  //Serial.print("|  BTS : ");
  //Serial.print(myData.BTS);
  myData.BTS1 = digitalRead(sd);
 // Serial.print("|  BTS1: ");
 // Serial.print(myData.BTS1);
  myData.FWD = digitalRead(fwd);
  //Serial.print("|  FWD :");
 // Serial.print(myData.FWD);
  myData.REV = digitalRead(rev);
 // Serial.print("|  REV :");
 // Serial.print(myData.REV);
  myData.LEFT = digitalRead(left);
 // Serial.print("|  LEFT:");
 // Serial.print(myData.LEFT);
  myData.RIGHT = digitalRead(right);
 // Serial.print("|  RIGHT:");
 // Serial.print(myData.RIGHT);
  myData.BWD_LEFT = digitalRead(bl);
 // Serial.print("|  BWD_LEFT:");
 // Serial.print(myData.BWD_LEFT);
  myData.BWD_RIGHT = digitalRead(br);
 // Serial.print("|  BWD_RIGHT:");
 // Serial.print(myData.BWD_RIGHT);
  myData.IR = digitalRead(ir);
 // Serial.print("|  IR  :");
 // Serial.print(myData.IR);
  myData.IL = digitalRead(il);
 // Serial.print("|  IL  :");
 // Serial.print(myData.IL);
//delay(1);

  
  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
   
 /* if (result == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }
  //delay(1);*/
}
