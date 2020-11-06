int sensor01 = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);

  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  Serial.print("Distancia em cm (fora da condicao): ");
  Serial.println(0.01723 * readUltrasonicDistance(5, 4));
  if (0.01723 * readUltrasonicDistance(5, 4) > 3) {
    delay(2000); // Wait for 3000 millisecond(s)
    if (0.01723 * readUltrasonicDistance(5, 4) > 3) {
      while (0.01723 * readUltrasonicDistance(5, 4) > 3) {
        digitalWrite(9, HIGH);
        tone(12, 440, 1000); 
        Serial.print("Distancia em (dentro da condicao): ");
        Serial.println(0.01723 * readUltrasonicDistance(5, 4));
        delay(500);
      }
    }
  }
digitalWrite(9, LOW);
delay(500);
}
