#include <MecanumRobot.h>

MecanumRobot robot(4,3,6,5,10,9,12,11);
const int trigPin = 7;
const int echoPin = 8;
  int rturnCount;
  int lturnCount;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  robot.begin();
robot.setTurnTime(800);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration;
  int distance;



  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin,HIGH);

  distance = duration * 0.034 /2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");


if(distance <10) {
  if (rturnCount < 4) {
    robot.stop();
    delay(100);
    robot.right(90);
    delay(100);
    robot.stop();
    rturnCount++;
  }
  else if (lturnCount < 2) {
    robot.stop();
    delay(100);
    robot.left(90);
    delay(100);
    robot.stop();
    lturnCount++;
  }
}
else if (distance > 10 && lturnCount < 2) {
  robot.forwardStart();
  delay(100);
}
else {
  robot.forwardStart();
  delay(3000);
  robot.stop();
  delay(10000);

}


  Serial.print(rturnCount);
  Serial.print(lturnCount);

delay (200);
}