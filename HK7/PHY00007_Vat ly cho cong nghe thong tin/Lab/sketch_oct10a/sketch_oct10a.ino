int button = 12;

void setup() {
  // put your setup code here, to run once:
  // Serial.begin(9600);

  // // green
  // pinMode(4, OUTPUT);
  // // yellow
  // pinMode(2, OUTPUT);
  // // red
  // pinMode(8, OUTPUT);

  pinMode(button, INPUT);
  Serial.begin(9600);
}

bool flag = false;
bool last = LOW;

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println("Hello World");
  // delay(1000);

  // cho cổng digital, HIGH -> 1, LOW -> 0
  // digitalWrite(8, HIGH);
  // delay(1000);
  // digitalWrite(8, LOW);
  // delay(1000);

  // // green
  // digitalWrite(4, HIGH);
  // delay(5000);
  // digitalWrite(4, LOW);
  // // yellow
  // digitalWrite(2, HIGH);
  // delay(2000);
  // digitalWrite(2, LOW);
  // // red
  // digitalWrite(8, HIGH);
  // delay(3000);
  // digitalWrite(8, LOW);

  int buttonState = digitalRead(button);
  if (buttonState == HIGH) {
    while(digitalRead(button) == HIGH){
      Serial.println("Button presseddddd");
      flag = !flag;
    }
    delay(100);
  }

  last = buttonState;

  if (flag == false) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }
}
