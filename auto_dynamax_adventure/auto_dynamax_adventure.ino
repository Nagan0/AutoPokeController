#include <SwitchControlLibrary.h>

#define HOLDTIME (95) // 1回のキー入力の長押し時間

void PushRL(int delay_time_ms);
int PushKey(char* keyname, int holdtime, int delaytime);

void setup() {
  // コントローラーとして認識されるためにRLを7回ほどカチャカチャする
  for(int i=0;i<7;i++)PushRL(300);
  delay(1000);
}

void loop() {
  // ↓ここに繰り返すコマンド列を入れよう

  PushKey("down", HOLDTIME, 2000); // 1  ↓ 2秒待機
  PushKey("A",    HOLDTIME, 2000); // 2  A  2秒待機
  PushKey("A",    HOLDTIME, 2000); // 3  A  2秒待機
  PushKey("A",    HOLDTIME, 2000); // 4  A  2秒待機
  PushKey("A",    HOLDTIME, 2000); // 5  A  2秒待機
  PushKey("A",    HOLDTIME, 4000); // 6  A  4秒待機
  PushKey("down", HOLDTIME, 2000); // 7  ↓ 2秒待機
  PushKey("A",    HOLDTIME, 2000); // 8  A  2秒待機
  PushKey("down", HOLDTIME, 2000); // 9  ↓ 2秒待機
  PushKey("A",    HOLDTIME, 2000); // 10 A  2秒待機
  PushKey("A",    HOLDTIME, 2000); // 11 A  2秒待機
  PushKey("down", HOLDTIME, 2000); // 12 ↓ 2秒待機
  PushKey("A",    HOLDTIME, 2000); // 13 A  2秒待機
  PushKey("A",    HOLDTIME, 2000); // 14 A  2秒待機
  PushKey("B",    HOLDTIME, 3000); // 15 B  3秒待機　
  PushKey("B",    1500    , 2000); // 16 B【1.5秒長押し】2秒待機　
  
  // ↑ここに繰り返すコマンド列を入れよう
}

void PushRL(int delay_time_ms){
  SwitchControlLibrary().PressButtonR();
  SwitchControlLibrary().PressButtonL();
  delay(HOLDTIME);
  SwitchControlLibrary().ReleaseButtonR();
  SwitchControlLibrary().ReleaseButtonL();
  delay(delay_time_ms);
  return;
}
int PushKey(char* keyname, int holdtime, int delaytime){
  // ホームボタン・方向キーはRight, Left, Up, Down, Homeなど2文字以上で入力。
  // その他ボタン入力は1文字（A,B,X,Y,R,L,+,-）ZR・ZLにも対応
  // 同時押しは非対応
  
  if(strlen(keyname)==1){
    switch(keyname[0]){
      case 'A': case 'a': // A
        SwitchControlLibrary().PressButtonA(); delay(holdtime);
        SwitchControlLibrary().ReleaseButtonA(); delay(delaytime);
      break;
      case 'B': case 'b': // B
        SwitchControlLibrary().PressButtonB(); delay(holdtime);
        SwitchControlLibrary().ReleaseButtonB(); delay(delaytime);
      break;
      case 'X': case 'x': // X
        SwitchControlLibrary().PressButtonX(); delay(holdtime);
        SwitchControlLibrary().ReleaseButtonX(); delay(delaytime);
      break;
      case 'Y': case 'y': // Y
        SwitchControlLibrary().PressButtonY(); delay(holdtime);
        SwitchControlLibrary().ReleaseButtonY(); delay(delaytime);
      break;
      case 'L': case 'l': // L
        SwitchControlLibrary().PressButtonL(); delay(holdtime);
        SwitchControlLibrary().ReleaseButtonL(); delay(delaytime);
      break;
      case 'R': case 'r': // R
        SwitchControlLibrary().PressButtonR(); delay(holdtime);
        SwitchControlLibrary().ReleaseButtonR(); delay(delaytime);
      break;
      case 'H': case 'h': // Home
        SwitchControlLibrary().PressButtonHome(); delay(holdtime);
        SwitchControlLibrary().ReleaseButtonHome(); delay(delaytime);
      break;
      case '+': case 'p': case 'P': // Plus
        SwitchControlLibrary().PressButtonPlus(); delay(holdtime);
        SwitchControlLibrary().ReleaseButtonPlus(); delay(delaytime);
      break;
      case '-': case 'm': case 'M': // Minus
        SwitchControlLibrary().PressButtonMinus(); delay(holdtime);
        SwitchControlLibrary().ReleaseButtonMinus(); delay(delaytime);
      break;
      default:
      break;
    }
  }else if(strlen(keyname)>=2){
    switch(keyname[0]){
      case 'z': case 'Z': // ZR/ZL
        if(keyname[1]=='R'||keyname[1]=='r'){
          SwitchControlLibrary().PressButtonZR(); delay(holdtime);
          SwitchControlLibrary().ReleaseButtonZR(); delay(delaytime);
        }
        if(keyname[1]=='L'||keyname[1]=='l'){
          SwitchControlLibrary().PressButtonZL(); delay(holdtime);
          SwitchControlLibrary().ReleaseButtonZL(); delay(delaytime);
        }
      break;
      case 'r': case 'R': // right
        SwitchControlLibrary().MoveHat(2); delay(holdtime);
        SwitchControlLibrary().MoveHat(8); delay(delaytime);
      break;
      case 'l': case 'L': // left
        SwitchControlLibrary().MoveHat(6); delay(holdtime);
        SwitchControlLibrary().MoveHat(8); delay(delaytime);
      break;
      case 'u': case 'U': // up
        SwitchControlLibrary().MoveHat(0); delay(holdtime);
        SwitchControlLibrary().MoveHat(8); delay(delaytime);
      break;
      case 'd': case 'D': // down
        SwitchControlLibrary().MoveHat(4); delay(holdtime);
        SwitchControlLibrary().MoveHat(8); delay(delaytime);
      break;
      case 'H': case 'h': // Home
        SwitchControlLibrary().PressButtonHome(); delay(holdtime);
        SwitchControlLibrary().ReleaseButtonHome(); delay(delaytime);
      default:
      break;  
    }
  }else{
    return -1;
  }
  strlen(keyname);
}
