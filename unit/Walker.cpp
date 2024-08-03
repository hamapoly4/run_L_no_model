/******************************************************************************
 *  ファイル名：Walker.cpp
 *　　　　内容：Walkerクラスの実施
 *  　　作成日：2024/8/3
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#include "Walker.h"

using namespace ev3api;

Walker::Walker(Walker& leftmotor, Walker& rightmotor)
    : mLeftMotor(leftmotor), mRightMotor(rightmotor)
{
    ;
}

void Walker::Run(int turn)
{
    mLeftWheel.setPWM(PWM + turn);
    mRightWheel.setPWM(PWM - turn);
}