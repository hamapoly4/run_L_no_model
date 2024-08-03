/******************************************************************************
 *  ファイル名：app.cpp
 *　　　　内容：タスクであるmain_taskの実施
 *  　　作成日：2024/8/3
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#include "app.h"
#include "Runner.h"

#include "ColorSensor.h"
#include "SonarSensor.h"
#include "Motor.h"

/* 名前空間ev3apiを使用する */
using namespace ev3api;

/*----------------------------
* オブジェクトを静的に確保する
*-----------------------------*/
ColorSensor gColorSensor(PORT_2);
SonarSensor gSonarSensor(PORT_3);
Motor       gLeftWheel(PORT_C);
Motor       gRightWheel(PORT_B);

Calculation gCalculation(gColorSensor);
Walker gWalker(gLeftWheel, gRightWheel);
Runner gRunner(gSonarSensor, gCalculation, gWalker);

/*----------------------------------------------------
*                      内部結合
*-----------------------------------------------------*/
namespace {
    /* システムの破棄 */
    void user_system_destroy()
    {
        /* 左右のモータをリセット */
        gLeftWheel.reset();
        gRightWheel.reset();
    }
}

/*----------------------------------------------------
*                    メインタスク
*-----------------------------------------------------*/
void main_task(intptr_t unused)
{
    /* 周期ハンドラ開始 */
    sta_cyc(CYC_RUNNER);

    slp_tsk();  /* メインタスクの起床待ち */

    /* 周期ハンドラ停止 */
    stp_cyc(CYC_RUNNER);

    user_system_destroy();  /* 終了処理 */

    ext_tsk();  /* タスクの終了 */
}

/*----------------------------------------------------
*                    ランナータスク
*-----------------------------------------------------*/
void runner_tsk(intptr_t exinf)
{
    gRunner.runL();

    ext_tsk();
}
