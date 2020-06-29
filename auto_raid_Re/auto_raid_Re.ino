/**
* レイドバトル→ポケモンを捕獲→ボックスに預ける→願いの塊を投げ入れるを繰り返すスケッチ
* ボックスに空きがある限り、レイドバトルを続ける
*
* 初期条件は以下の通り
* 1. 願いの塊を投げ入れた巣穴の前にいること
* 2. 手持ちが1体のみのこと
* 3. Aボタン連打でレイドバトルで勝てるようにすること
* 4. ボックスが空のこと
* 5. 願いの塊を大量に持っていること
*/
#include <auto_command_util.h>

// レイドバトルが終わるまでの時間
const int BATTLE_FINISH_SEC = 180;

// 巣穴の前からひとりレイドを始め、レイドポケモンを倒し、捕まえる
void startRaidBattle(){
    // ひとりではじめる
    pushButton(Button::A, 1500);
    pushHatButton(Hat::DOWN, 500);
    // レイドバトル中はA連打
    for(int i=0; i<BATTLE_FINISH_SEC; i++){
        pushButton(Button::A, 500, 2);
    }
}

// レイドバトル後もしばらく続くAボタン連打の後の画面から、
// 巣穴の前の最初のポジションに戻す
void resetState(){
    tiltJoystick(0,0,0,0,100);
    pushButton(Button::B, 1000, 4);
    delay(1000);
    pushButton(Button::A, 1000, 2);
    pushButton(Button::B, 1000, 3);
}


// 自動ボックス処理機能削除
void execRaidBattleSequence(){
    startRaidBattle();
    resetState();
}


void setup(){
    pushButton(Button::B, 500, 5);
}

void loop(){
    execRaidBattleSequence();
}
