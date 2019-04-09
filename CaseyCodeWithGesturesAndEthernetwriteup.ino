//////////////////////////////////////////////////////////////////////////
// Programmer: Casey Davis, Sara Pandian
// Project name: Clean Up Interactive Game (Iot Project)
// Date: 09/04/2019
// Copyright: Casey Davis and Saravanan Pandian 2019
/////////////////////////////////////////////////////////////////////////

////////// header files///////////////////////////////////////////////////
#include <SPI.h>
#include <Ethernet.h>
#include <PubNub.h>
#include <HCSR04.h>
//////////////////////////////////////////////////////////////////////////

/////////// variables ///////////////////////////////////////////////////
#define LDRpin A0    // Pin A0 used as analog input for LDR(light dependent resistor) sensor

byte mac[] = {0x00, 0x0E, 0xEF, 0x00, 0x00, 0x34}; // ethernet address

const int trigPin = 5; // pin 5 and 4 are used for the right ultrasonic sensor
const int echoPin = 4;
const int trig1Pin = 7; // pin 7 and 6 are used for the left ultrasonic sensor
const int echo1Pin = 6;
const int led1Pin = 3;   //pin 2 and 3 are used for the blue LEDs (Light Emitting Diode)
const int led2Pin = 2;  



int ldrvalue = 0; // LDR digital value
int start = 0;   //  Variable 1= start game, 0= Pause
long duration, counter; // Duration is the time for the ultrasonic signal to come back and counter holds the gestures (1= up, 2=left, 3=right)
int distanceCm, distanceCm1; //Where Users hand is with respect to the ultrasonic sensor 
unsigned int inL, inR, outL, outR;  //variable to indiciate if the user's hands are in range (in) or not (out).

char pubkey[] = "pub-c-77e55fe1-b562-423d-b74e-9cf40a46a0ea";  //pubnub publish key
char subkey[] = "sub-c-69f33614-4c85-11e9-bfba-22653a49d911";  //pubnub subscribe key
char channel [] = "project";                                   // pubnub channel


////////////// Configuring the Ardiuno Board//////////////////////////////////
void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(trig1Pin, OUTPUT);
pinMode(echo1Pin, INPUT);
pinMode(led1Pin, OUTPUT);
pinMode(led2Pin, OUTPUT);


counter = 0; //Gesture to be sent to the game
inL = 0;
inR = 0;
outL = 0;
outR = 0;

  Serial.begin(9600);                                                     // Starts the serial communication
  Serial.println("Serial Setup");
  while(!Ethernet.begin(mac)){                                            // Configure the Ethernet Shield
    Serial.println("Ethernet setup error!");
  }
  Serial.println("Ethernet set up success");
  PubNub.begin(pubkey, subkey);                                          // Instantiate pubub server
  Serial.println("Pubnub set up");  

  Serial.println("Put your hand on the LDR sensor to start the game!");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////// Main Code ///////////////////////////////////////////////////
void loop() {
  // put your main code here, to run repeatedly:
  if(start == 0)                                                         // Check if the game must be paused
  {
  while(ldrvalue < 700){                                                // If the LDR sensor value is greater than 700, then do not start the game
    ldrvalue = analogRead(LDRpin);
    Serial.println(ldrvalue);
    delay(100);

  }

  // Exited from the while loop to begin the game
  Serial.println("You are ready to play the game");
  start = 10;
  }


//// Get data from the ultrasonic sensors///////
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Ultrasonic sensor 1 sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= (duration*0.034/2); 

// Ultrasonic sensor 2 sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trig1Pin, LOW);
delayMicroseconds(2);
digitalWrite(trig1Pin, HIGH);
delayMicroseconds(10);
digitalWrite(trig1Pin, LOW);
duration = pulseIn(echo1Pin, HIGH);
distanceCm1= (duration*0.034/2); 
 
///////////Check Range of User's Right Hand/////////////////////////////
if(distanceCm < 50){
if(distanceCm < 20){ 
   inR = 1;
   outR = 0;
}
}else{
     inR = 0;
     outR = 0;
}

///////////Check Range of User's Left Hand/////////////////////////////
if(distanceCm1 < 50){
if(distanceCm1 < 20){
   inL = 1;
   outL = 0;
}
}else{
     inL = 0;
     outL = 0;
}


///////////Check Range of both User's Hands/////////////////////////////
if(inL == 1 && inR == 0  && outL == 0 && outR == 0){
  digitalWrite(led1Pin, HIGH);  // Left LED on, Right LED off
  digitalWrite(led2Pin, LOW);
}else if(inL == 0 && inR == 1  && outL == 0 && outR == 0){
  digitalWrite(led1Pin, LOW);  // Turn right LED on and left LED off
  digitalWrite(led2Pin, HIGH);
}else if(inL == 1 && inR == 1  && outL == 0 && outR == 0){
  digitalWrite(led1Pin, HIGH); // Turn both LEDs on
  digitalWrite(led2Pin, HIGH);
}else { 
  digitalWrite(led1Pin, LOW);  //Turn both LEDs off
  digitalWrite(led2Pin, LOW);
}  

/////////////////////////////////////////////////////////

  
  delay(50); // Makes sure that pubnub and ethernet shield has initalised
  
  Ethernet.maintain(); //Checking to make sure that ethernet connection is still available 

  EthernetClient *client; //Instantiate a network client for the game


  //// Checking the gesture from the user and formatting it to be sent to pubnub and printing to ardiuno console

  if(inL == 1 && inR == 1){      //Both hands
    counter = 1;
    Serial.print("Gesture: ");
    Serial.print("up\n");
    char msg[64] = "{\"eon\":{\"sensor\":";
    sprintf(msg + strlen(msg), "%d", counter);
    strcat(msg, "}}");

    Serial.print("publishing message: ");
    Serial.println(msg);
    client = PubNub.publish(channel, msg);
  }else if(inL == 1 && inR == 0){ //Left Hand only
    counter = 2;
    Serial.print("Gesture: ");
    Serial.print("right\n");
    char msg[64] = "{\"eon\":{\"sensor\":";
    sprintf(msg + strlen(msg), "%d", counter);
    strcat(msg, "}}");

    Serial.print("publishing message: ");
    Serial.println(msg);
    client = PubNub.publish(channel, msg);
  }else if(inL == 0 && inR == 1){ // Right Hand only
    counter = 3;
    Serial.print("Gesture: ");
    Serial.print("left\n");
    char msg[64] = "{\"eon\":{\"sensor\":";
    sprintf(msg + strlen(msg), "%d", counter);
    strcat(msg, "}}");

    Serial.print("publishing message: ");
    Serial.println(msg);
    client = PubNub.publish(channel, msg);
  }

 
inL = 0;   //Set variable inLeft and inRight to 0 to get new gesture from the user
inR = 0;
 
}
