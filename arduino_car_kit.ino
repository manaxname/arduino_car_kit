int MoveRightSideForward, MoveRightSideBack, MoveLeftSideBack, MoveLeftSideForward;

void setup() {
  // put your setup code here, to run once:
  MoveRightSideForward = 2;
  MoveRightSideBack = 3;
  MoveLeftSideForward = 5;
  MoveLeftSideBack = 4;
  pinMode(MoveRightSideForward, OUTPUT);
  pinMode(MoveRightSideBack, OUTPUT);
  pinMode(MoveLeftSideBack, OUTPUT);
  pinMode(MoveLeftSideForward, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(5000);

  MoveForward();
  delay(1000);
  MoveStop();
  delay(1000);

  MoveBack();
  delay(1000);
  MoveStop();
  delay(1000);

  TurnRight();
  delay(1000);
  MoveStop();
  delay(1000);

  TurnLeft();
  delay(1000);
  MoveStop();
  delay(1000);
}





//  ---------------- MOVING -------------------------
void MoveForward() {
  MoveStop();
  digitalWrite(MoveRightSideForward, HIGH);
  digitalWrite(MoveLeftSideForward, HIGH);
}

void MoveBack() {
  MoveStop();
  digitalWrite(MoveRightSideBack, HIGH);
  digitalWrite(MoveLeftSideBack, HIGH);
}

void TurnRight() {
  MoveStop();
  digitalWrite(MoveRightSideBack, HIGH);
  digitalWrite(MoveLeftSideForward, HIGH);
}

void TurnLeft() {
  MoveStop();
  digitalWrite(MoveRightSideForward, HIGH);
  digitalWrite(MoveLeftSideBack, HIGH);
}

void MoveStop() {
  digitalWrite(MoveRightSideForward, LOW);
  digitalWrite(MoveRightSideBack, LOW);
  digitalWrite(MoveLeftSideForward, LOW);
  digitalWrite(MoveLeftSideBack, LOW);
}
//  ================= MOVING ========================
