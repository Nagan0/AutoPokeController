/**
* 穴掘り兄弟に採掘させ続けるスケッチ
*
* 初期条件は以下の通り
* 1. 穴掘り兄弟の前にいること
*/
#include <auto_command_util.h>

// 採掘させ続けるシーケンス
void execWattGainSequence()
{
    // 開始
    pushButton(Button::A, 500);
}

// 穴掘り兄弟の目の前でスタート
void setup(){
    pushButton(Button::B, 500, 4);  // 最初の数回の入力はswitchが認識しない場合があるので、無駄打ちをしておく
    pushButton(Button::A, 1000);
}

void loop(){
    execWattGainSequence();
}
