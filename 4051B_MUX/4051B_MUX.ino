/*

 * codeexample for useing a 4051 * analog multiplexer / demultiplexer
 * by david c. and tomek n.* for k3 / malm� h�gskola
 *

 * edited by Ross R.
 * edited by Igor de Oliveira Sá.
 * http://playground.arduino.cc/Learning/4051
 */   

#define s0 2      // pin for select input 0 (s0:2)
#define s1 3      // pin for select input 1 (s1:3)     
#define s2 4      // pin for select input 2 (s2:4)
#define z 0       // pin for analog common input/output (z:A0)

int r0 = 0;      //value of select pin at the 4051 (s0)
int r1 = 0;      //value of select pin at the 4051 (s1)
int r2 = 0;      //value of select pin at the 4051 (s2)


int count = 0;   // which y pin we are selecting
int value = 0;   // value of selected y pin

 

void setup(){  
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);

  Serial.begin(9600);
}

 

void loop () {
  for (count=0; count<=7; count++) {
    // select the bit  
    r0 = bitRead(count,0);    // use this with arduino 0013 (and newer versions)     
    r1 = bitRead(count,1);    // use this with arduino 0013 (and newer versions)     
    r2 = bitRead(count,2);    // use this with arduino 0013 (and newer versions)     

    //r0 = count & 0x01;      // old version of setting the bits
    //r1 = (count>>1) & 0x01;      // old version of setting the bits
    //r2 = (count>>2) & 0x01;      // old version of setting the bits

    digitalWrite(s0, r0);
    digitalWrite(s1, r1);
    digitalWrite(s2, r2);

    //Either read or write the multiplexed pin here
    value = analogRead(z);
    Serial.print(count);
    Serial.print("\t");
    Serial.print(value);
    Serial.print("\t");
  }  
  Serial.println("");
  delay (500);
}
