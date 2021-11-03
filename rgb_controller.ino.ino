String incomingString = "aa"; // for incoming serial data
String temp = "aa";

int index1 = 0;
int index2 = 0;

int red = 0;
int green = 0;
int blue = 0;

int red_pin = 9;
int green_pin = 10;
int blue_pin = 11;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingString = Serial.readString();
    Serial.println(incomingString);
    
    index1 = incomingString.indexOf(',');
    temp = incomingString.substring(0, index1);
    red = temp.toInt();

    index2 = incomingString.indexOf(',', index1+1);
    temp = incomingString.substring(index1+1, index2);
    green = temp.toInt();

    index1 = incomingString.indexOf(',', index2+1);
    temp = incomingString.substring(index2+1, index1);
    blue = temp.toInt();

    setRGB(red, green, blue);
    Serial.print(red);
    Serial.print(", ");
    Serial.print(green);
    Serial.print(", ");
    Serial.print(blue);
    Serial.println();
  }
}

void setRGB(int r, int g, int b){
  analogWrite(red_pin, 255-r);
  analogWrite(green_pin, 255-g);
  analogWrite(blue_pin, 255-b);
}
