/******************************************************************************
 *  ファイル名：Walker.h
 *　　　　内容：Walkerクラスの定義
 *  　　作成日：2024/8/3
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#include "Motor.h"

class Walker {
private:
    ev3api::Motor& mLeftMotor;
    ev3api::Motor& mRightMotor;

public:
    Walker(ev3api::Motor& leftmotor, 3v3api::Motor& rightmotor);

    void Run(int turn);
};