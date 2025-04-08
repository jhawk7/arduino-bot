const int trigPin = 14;
const int echoPin = 15;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW); //initializse trigger to low
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // trigger is high for 10us
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH); //gets duration that echoPin was high - echo pin goes high when the receiver receives a sound wave
  float distance = (duration * .0343) / 2; // d = v*t; our velocity is the speed of sound (cm/us) and the time is the duration /2 in us - sound travels to the object and back
  Serial.print("Distance(cm): ");
  Serial.println(distance);
  delay(100);
}