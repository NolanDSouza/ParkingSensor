int echo = 7; // becomes high when sound pulse returns
int trigger = 8; // transmits sound pulse when pin 8 is high
int buzzer = 9;

void setup() 
{
  Serial.begin(9600); // displays result on serial monitor
  pinMode(echo, INPUT); // allows echo pin to read high or low result
  pinMode(trigger, OUTPUT); // allows trigger pin to be turned on/off 
  pinMode(buzzer, OUTPUT);
}

double distanceCentimetres()
{
  digitalWrite(trigger, LOW); // turns pin off
  delayMicroseconds(5); // slight delay for the pin to settle
  digitalWrite(trigger, HIGH); // sends pulse
  delayMicroseconds(5);
  digitalWrite(trigger, LOW);

  double time = (pulseIn(echo, HIGH))/2000000.0; // time taken for echo pin to silence, converted to seconds, divided by 2 to obtain one-way time.
  double distance = 343.2 * time; // 343.2 m/s is the speed of sound at 20°C, distance * 100 converts to centimetres
  return distance * 100; //converts distance to centimetres
}

void loop() 
{
  int distance = distanceCentimetres();
  Serial.println(distance, DEC);
  digitalWrite(buzzer, HIGH);
  delay(10 * distance);
  digitalWrite(buzzer, LOW);
  delay(250.0000); // prevents 100% CPU usage
}
