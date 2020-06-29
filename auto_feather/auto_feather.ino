#include <SwitchControlLibrary.h>
//      SwitchControlLibrary().MoveLeftStick(255,128); // 右  
//      SwitchControlLibrary().MoveLeftStick(0,128);   // 左
//      SwitchControlLibrary().MoveLeftStick(128,0);   // 上
//      SwitchControlLibrary().MoveLeftStick(128,255); // 下
int timecnt = 0;
int cnt = 0;
int LRflg = 1; // 0:左 1:右

// エンジンシティの左ポケセン前からスタート

// 初期処理　マイコン接続後1番に動きます
void setup(){
  // LRボタン押下でコントローラーとして認識させる
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
  MoveBridge();
  SwitchControlLibrary().MoveLeftStick(255,128); // 右
  delay(50);
  LRflg = 1;
}

// 繰り返し処理　マイコンの接続をやめるまで{}内を繰り返します
void loop() {
  // 開始
  ButtonA();
  delay(50);
  timecnt++;
  if (timecnt > 140){
    timecnt = 0;
    cnt++;
    SwitchControlLibrary().MoveLeftStick(128,0);   // 上
    delay(400);
    if(cnt > 2){
      cnt = 0;
      LRflg = 0;
      SwitchControlLibrary().MoveLeftStick(128,128); // 中央
      delay(50);
      DateChange();
      Reload();     // ポケセンへタクシー 
      MoveBridge(); // 橋まで移動
    }
    if(LRflg == 1){
      LRflg = 0;
      SwitchControlLibrary().MoveLeftStick(0,128);   // 左
      delay(50);
    }else{
      LRflg = 1;
      SwitchControlLibrary().MoveLeftStick(255,128); // 右  
      delay(50);
    }
  }
}

//Aボタンを押下して離すまで
void ButtonA(){
  SwitchControlLibrary().PressButtonA();
  delay(50);
  SwitchControlLibrary().ReleaseButtonA();
}

//Bボタンを押下して離すまで
void ButtonB(){
  SwitchControlLibrary().PressButtonB();
  delay(50);
  SwitchControlLibrary().ReleaseButtonB();
}

//Xボタンを押下して離すまで
void ButtonX(){
  SwitchControlLibrary().PressButtonX();
  delay(50);
  SwitchControlLibrary().ReleaseButtonX();
}

//ホームボタンを押下して離すまで
void ButtonHome(){
  SwitchControlLibrary().PressButtonHome();
  delay(50);
  SwitchControlLibrary().ReleaseButtonHome();
}

//+ボタンを押下して離すまで
void ButtonPlus(){
  SwitchControlLibrary().PressButtonPlus();
  delay(50);
  SwitchControlLibrary().ReleaseButtonPlus();
}

//下を入力して離すまで
void MoveHatDown(){
  SwitchControlLibrary().MoveHat(4); // down
  delay(50);
  SwitchControlLibrary().MoveHat(8); // center
}

//右を入力して離すまで
void MoveHatRight(){
  SwitchControlLibrary().MoveHat(2); // right
  delay(50);
  SwitchControlLibrary().MoveHat(8); // center
}

//左を入力して離すまで
void MoveHatLeft(){
  SwitchControlLibrary().MoveHat(6); // left
  delay(50);
  SwitchControlLibrary().MoveHat(8); // center
}

//上を入力して離すまで
void MoveHatUp(){
  SwitchControlLibrary().MoveHat(0); // up
  delay(50);
  SwitchControlLibrary().MoveHat(8); // center
}

int MAXMONTH = 11; //月最大値(1月から11回更新で12月となるため)
int MAXDAY = 27;   //日最大値(1日から27回更新で28日となるため)
// ※このプログラムでは、ひと月を27日とみなす(ひと月の最短日数が28日のため)
int month = MAXMONTH; // 月
int day = MAXDAY;     // 日

//日付変更処理
void DateChange(){
  // 日付変更
  ButtonHome();
  delay(1000);
  MoveHatDown();
  delay(100);
  MoveHatRight();
  delay(100);
  MoveHatRight();
  delay(100);
  MoveHatRight();
  delay(100);
  MoveHatRight();
  delay(100);
  ButtonA();
  delay(1500);
  // 設定画面
  SwitchControlLibrary().MoveHat(4); // down
  delay(2000);
  SwitchControlLibrary().MoveHat(8); // center
  delay(50);
  MoveHatRight();
  delay(50);
  MoveHatDown();
  delay(50);
  MoveHatDown();
  delay(50);
  MoveHatDown();
  delay(50);
  MoveHatDown();
  delay(50);
  ButtonA();
  delay(500);
  // 時間設定
  MoveHatDown();
  delay(50);
  MoveHatDown();
  delay(50);
  ButtonA();
  delay(500);
  // 時間の変更

  // 年の処理 日を28回変更し、月を12回変更していたら
  if (month == 0 & day == 0) {
    MoveHatUp(); // 年を変更
    delay(200);
    MoveHatRight();  // 月の項目へ移動
    delay(50);
    MoveHatUp();     // 月を変更
    delay(200);
    month = MAXMONTH;  // 月をリセット
    MoveHatRight();  // 日の項目へ移動
    delay(50);
    DayReset();      // 日をリセット
    delay(200);
  }else{  
    // 月の処理 日を28回変更したいたら
    if (day == 0) {
      MoveHatRight();  // 月の項目へ移動
      delay(50);
      MoveHatUp();     // 月を変更
      delay(200);
      MoveHatRight();  // 日の項目へ移動
      delay(50);
      DayReset();      // 日をリセット
      delay(200);
      --month;     // 月をカウントダウン
    }else{      
      // 日の処理 日を28回変更していないなら
      MoveHatRight(); // 月の項目へ移動
      delay(50);
      MoveHatRight(); // 日の項目へ移動
      delay(50);
      MoveHatUp(); // 日を変更
      delay(200);
      --day;       // 日をカウントダウン
    }
  }  
  ButtonA();
  delay(50);
  ButtonA();
  delay(50);
  ButtonA();
  delay(50);
  ButtonA();
  delay(100);

  ButtonHome();
  delay(1000);
  ButtonA();
  delay(1000);  
}

//日をリセット
void DayReset(){
  for (day ; day < MAXDAY ; day++){
    MoveHatDown();
    delay(50);
  }
}

//Mapを再読み込み
void Reload(){
  ButtonX();
  delay(900);
  ButtonA();
  delay(2000);
  SwitchControlLibrary().MoveHat(6); // left
  delay(300);
  SwitchControlLibrary().MoveHat(8); // center
  delay(500);
  ButtonA();
  delay(600);
  ButtonA();
  delay(4300);
}

//橋まで移動
void MoveBridge(){
  ButtonPlus();
  delay(500);
  SwitchControlLibrary().MoveLeftStick(128,255); // 下
  delay(485);
  SwitchControlLibrary().MoveLeftStick(255,128); // 右
  delay(13600);
  SwitchControlLibrary().MoveLeftStick(128,128); // 中央
  delay(500);
  ButtonPlus();
  delay(1000);
}
