/* INITIALIZATION */


int latch = 2; // set the latch pin   White wire
int clock = 3; // set the clock pin   Green wire off female
int datin = 4;// set the data in pin  Yellow wire
byte controller_data = 0;
int ledpinA = 13;
int ledpinB = 12;
int ledpinStart = 11;
int ledpinSelect = 10;
int ledpinUp = 9;
int ledpinDown = 8;
int ledpinLeft =7;
int ledpinRight = 6;

/* SETUP */
void setup() {
Serial.begin(9600);
pinMode(latch,OUTPUT);
pinMode(clock,OUTPUT);
pinMode(datin,INPUT);
pinMode(ledpinA, OUTPUT);
pinMode(ledpinB, OUTPUT);
pinMode(ledpinStart, OUTPUT);
pinMode(ledpinSelect, OUTPUT);
pinMode(ledpinUp, OUTPUT);
pinMode(ledpinDown, OUTPUT);
pinMode(ledpinLeft, OUTPUT);
pinMode(ledpinRight, OUTPUT);

digitalWrite(latch,HIGH);
digitalWrite(clock,HIGH);


}

/* THIS READS DATA FROM THE CONTROLLER */
void controllerRead() {
controller_data = 0;
digitalWrite(latch,LOW);
digitalWrite(clock,LOW);

digitalWrite(latch,HIGH);
delayMicroseconds(2);
digitalWrite(latch,LOW);

controller_data = digitalRead(datin);

for (int i = 1; i <= 7; i ++) {
digitalWrite(clock,HIGH);
delayMicroseconds(2);
controller_data = controller_data << 1;
controller_data = controller_data + digitalRead(datin) ;
delayMicroseconds(2);
digitalWrite(clock,LOW);
}

}

/* THE LED, SERVO, AND SERIAL MONITOR PROGRAM */
void loop() {
controllerRead();
digitalWrite(ledpinA, LOW);
digitalWrite(ledpinB, LOW);
digitalWrite(ledpinStart, LOW);
digitalWrite(ledpinSelect, LOW);
digitalWrite(ledpinUp, LOW);
digitalWrite(ledpinDown, LOW);
digitalWrite(ledpinLeft, LOW);
digitalWrite(ledpinRight, LOW);

Serial.println("Binary: ");
Serial.println(controller_data, BIN);

 if (controller_data==B11101111){
   Serial.println("Start has been Pressed"); 
   digitalWrite(ledpinStart, HIGH);
   Serial.println("LED lit, sucka!!");   
   }  else {
   Serial.println("");
   }

 if (controller_data==B11011111){
   Serial.println("Select has been Pressed");
   digitalWrite(ledpinSelect, HIGH);
   Serial.println("LED lit, sucka!!");   
   }  else {
   Serial.println("");
   }
   
 if (controller_data==B11110111){
   Serial.println("Up has been Pressed");
   digitalWrite(ledpinUp, HIGH);
   Serial.println("LED lit, sucka!!");    
   }  else {
   Serial.println("");
   } 
 
 if (controller_data==B11111011){
   Serial.println("Down has been Pressed"); 
   digitalWrite(ledpinDown, HIGH);
   Serial.println("LED lit, sucka!!");  
   }  else {
   Serial.println("");
   }  
  
 if (controller_data==B11111101){
   Serial.println("Left has been Pressed"); 
   digitalWrite(ledpinLeft, HIGH);
   Serial.println("LED lit, sucka!!");  
   }  else {
   Serial.println("");
   }  

 if (controller_data==B11111110){
   Serial.println("Right has been Pressed");
   digitalWrite(ledpinRight, HIGH);
   Serial.println("LED lit, sucka!!");   
   }  else {
   Serial.println("");
   }  
  
 if (controller_data==B01111111){
   Serial.println("A has been Pressed");
   digitalWrite(ledpinA, HIGH);  
   Serial.println("LED lit, sucka!!"); 
   }  else {
   Serial.println("");
   }   
   
 if (controller_data==B10111111){
   Serial.println("B has been Pressed"); 
   digitalWrite(ledpinB, HIGH);  
   Serial.println("LED lit, sucka!!"); 
   }  else {
   Serial.println("");
   }
 


//delayMicroseconds(1000);
//digitalWrite(ledpin, LOW);    
//digitalWrite(ledpin, LOW);   
//for REFERENCE:  
//UP = 11110111
//DOWN=11111011
//LEFT=11111101
//RIGHT=11111110
//SELECT=11011111
//START=11101111
//A=01111111
//B=10111111

//if (controller_data==B01111111){
 //digitalWrite(ledpin, HIGH);   
// }
 
//if (controller_data==B10111111){
 //digitalWrite(ledpin, LOW);
//}
 
delay(200);
} 










