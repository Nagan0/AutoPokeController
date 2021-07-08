#include <SwitchControlLibrary.h>

void setup() {
  //recognize the micro controller
  SwitchControlLibrary().PressButtonR();
  delay(50);
  SwitchControlLibrary().ReleaseButtonR();
  delay(500);
  SwitchControlLibrary().PressButtonL();
  delay(50);
  SwitchControlLibrary().ReleaseButtonL();
  delay(500);
  SwitchControlLibrary().PressButtonR();
  delay(50);
  SwitchControlLibrary().ReleaseButtonR();
  delay(500);
  SwitchControlLibrary().PressButtonR();
  delay(50);
  SwitchControlLibrary().ReleaseButtonR();
  delay(2000);
}

void loop() {
  //main program
  GetBerry();
  ChangeDate();
}

//press & release A button
void PressA() {
  SwitchControlLibrary().PressButtonA();
  delay(50);
  SwitchControlLibrary().ReleaseButtonA();
}

//press & release B button
void PressB() {
  SwitchControlLibrary().PressButtonB();
  delay(50);
  SwitchControlLibrary().ReleaseButtonB();
}

//press & release Home button
void PressHome() {
  SwitchControlLibrary().PressButtonHome();
  delay(50);
  SwitchControlLibrary().ReleaseButtonHome();
}

//press & release Down button
void MoveHatDown() {
  SwitchControlLibrary().MoveHat(4); // down
  delay(50);
  SwitchControlLibrary().MoveHat(8); // center
}

//press & release Right button
void MoveHatRight() {
  SwitchControlLibrary().MoveHat(2); // right
  delay(50);
  SwitchControlLibrary().MoveHat(8); // center
}

//press & release Left button
void MoveHatLeft() {
  SwitchControlLibrary().MoveHat(6); // left
  delay(50);
  SwitchControlLibrary().MoveHat(8); // center
}

//press & release Up button
void MoveHatUp() {
  SwitchControlLibrary().MoveHat(0); // up
  delay(50);
  SwitchControlLibrary().MoveHat(8); // center
}

//player get berry
void GetBerry() {
  PressA();
  delay(500);
  PressA();
  delay(800);
  PressA();
  delay(3000);
  for (int i = 0; i < 15; i++) {
  PressB();
  delay(500);
  }
}

void ChangeDate() {
  //home
  PressHome();
  delay(500);
  MoveHatDown();
  delay(30);
  MoveHatRight();
  delay(30);
  MoveHatRight();
  delay(30);
  MoveHatRight();
  delay(30);
  MoveHatRight();
  delay(30);
  MoveHatRight();
  delay(30);
  PressA();
  delay(1000);

  //system setting
  SwitchControlLibrary().MoveHat(4); // down
  delay(1500);
  SwitchControlLibrary().MoveHat(8); // center
  delay(50);
  MoveHatRight();
  delay(30);
  MoveHatDown();
  delay(30);
  MoveHatDown();
  delay(30);
  MoveHatDown();
  delay(30);
  MoveHatDown();
  delay(30);
  PressA();
  delay(500);

  //date and time
  MoveHatDown();
  delay(30);
  MoveHatDown();
  delay(30);
  PressA();
  delay(300);

  //change date
  MoveHatDown();  //year - 1
  delay(30);
  MoveHatRight();
  delay(30);
  MoveHatRight();
  delay(30);
  MoveHatRight();
  delay(30);
  MoveHatRight();
  delay(30);
  MoveHatRight();
  delay(30);
  PressA(); //ok
  delay(300);

  PressA(); //change date
  delay(300);

  MoveHatLeft();  //year + 1
  delay(30);
  MoveHatLeft();
  delay(30);
  MoveHatLeft();
  delay(30);
  MoveHatLeft();
  delay(30);
  MoveHatLeft();
  delay(30);
  MoveHatUp();
  delay(30);
  MoveHatRight();
  delay(30);
  MoveHatRight();
  delay(30);
  MoveHatRight();
  delay(30);
  MoveHatRight();
  delay(30);
  MoveHatRight();
  delay(30);
  PressA();
  delay(300);

  //return
  PressHome();
  delay(500);
  PressA();
  delay(2000);
}
