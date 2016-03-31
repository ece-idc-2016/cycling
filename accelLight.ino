//Accelerometer Sensor
//Matt @ http://antipastohw.blogspot.com/
//Author of original code base: Marcos Yarza, Malmo University - Sweden, http://www.0j0.org
//edits by david betancourt and patricia torvalds

//Pin definitions
int ledPin = 13;
int ledPin2 = 12;
int xaccPin = 8;
int yaccPin = 49;

//Global variables
long xacc = 0;
long yacc = 0;

void setup() {
Serial.begin(9600); // Sets the baud rate to 9600
pinMode(ledPin, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(xaccPin, INPUT);
pinMode(yaccPin, INPUT);

//clear the initial pin readouts
pinMode(13, OUTPUT);pinMode(12, OUTPUT);
digitalWrite(13, LOW);digitalWrite(12, LOW);
}

long readAcceleration(int axe){
int count = 0;
long accel = 0;
int value = 0;

value = digitalRead(axe);
while(value == HIGH) { // Loop until pin reads a low
value = digitalRead(axe);
}

while(value == LOW) { // Loop until pin reads a high
value = digitalRead(axe);
}

while(value == HIGH) { // Loop until pin reads a low and count
value = digitalRead(axe);
count = count + 1;
}

//accel = abs(8 * (count * 18 / 10 - 500)); //this was the original function
accel = count;

return accel;
}

void loop() {
   // variables to read the pulse widths:
  int pulseX, pulseY;
  // variables to contain the resulting accelerations
  int accX, accY;

  // read pulse from x- and y-axes:
  pulseX = pulseIn(xaccPin, HIGH);
  pulseY = pulseIn(yaccPin, HIGH);

  // convert the pulse width into acceleration
  // accelerationX and accelerationY are in milli-g's:
  // earth's gravity is 1000 milli-g's, or 1g.
  accX = ((pulseX / 10) - 500) * 8;
  accY = ((pulseY / 10) - 500) * 8;
//Grab the accelerometer readings:
//xacc = readAcceleration(xaccPin); //reads and represents acceleration X
//yacc = readAcceleration(yaccPin); //reads and represents acceleration Y

//Print the output to the serial port:
Serial.print("X:");
Serial.print(accX);
Serial.print(" Y:");
Serial.print(accY);
Serial.print("\n\r");

//Change the status of the LEDs depending on which direction the board is facing
if (accX < -450) {
digitalWrite(12, HIGH);
digitalWrite(13, LOW);
}
else if (accX < -250) {
digitalWrite(12, LOW);
digitalWrite(13, HIGH);
} 
else if (accX < -75) {
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);
}
//if (yacc > 1200) {
//digitalWrite(5, HIGH);
//} else {
//digitalWrite(5, LOW);
//}

delay(100);
}
