using namespace std;

//MIDI messages format
class MIDImsg{
public:
 union{
  struct{uint8_t x,y,z;}mesg;
  uint8_t r[3];
 };
 
MIDImsg (uint8_t cmd, uint8_t num, uint8_t val){
  mesg.x=cmd;
  mesg.y=num;
  mesg.z=val;
}
};

//Switches
class Switch{
public:
int pin;
int State;
int LastState;  
unsigned long LastDebDelay;
Switch (int p, int s, int ls, unsigned long usl){
  pin=p;
  State=s;
  LastState=ls;
  LastDebDelay=usl;
}
};

//change this if DeBouncing isn`t efficient.
unsigned long DebDelay = 50;


//function for sending MIDI messgaes when button is released 
void MIDI_CC_But(Switch &S, MIDImsg &message){
 int reading = digitalRead(S.pin); 
 if (reading != S.LastState){
  S.LastDebDelay = millis();
  } 
 if(millis()-S.LastDebDelay > DebDelay){
  if(reading != S.State){
    S.State = reading;
    if(reading == LOW){
    Serial.write(message.r, sizeof(message.r)); 
       }
    }
 } 
 S.LastState = reading;
 return;
}


//Declare switches here
Switch S1(3, 0, 0, 0);
Switch S2(4, 0, 0, 0);
Switch S3(5, 0, 0, 0);
//Declare MIDImessages here
MIDImsg msg1(0xB0, 0x15, 0x01);
MIDImsg msg2(0xB0, 0x16, 0x01);
MIDImsg msg3(0xB0, 0x17, 0x01);

void setup() {
  //for sending MIDI signals
  Serial.begin(115200);
}
//main function
void loop() {
//Add more MIDI commands here
 MIDI_CC_But(S1, msg1);
 MIDI_CC_But(S2, msg2);
 MIDI_CC_But(S3, msg3);
}
