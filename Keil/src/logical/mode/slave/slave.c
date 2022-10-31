// #INDEX# ======================================================================================================
// Title .........: slave - Логика ведомого режима.
// Arch ..........: GD32F130C8C6, GD32F130C6C6
// Author ........: GreenBytes ( https://vk.com/greenbytes )
// Version .......: 3.5.0.0
// ==============================================================================================================

#include "gd32f1x0.h"
#include "slave.h"
#include "../../../framework/board/board.h"
#include "../../../framework/framework.h"
#include "../../../device/device.h"
#include "../../../config/config.h"
#include "../../../BLDC/bldc.h"
#include "../../../logical/logical.h"

extern config_t config;

void slave_init(void) {
	enginePhase (config.phase);
    engineHall  (config.hall);
    engineTable (config.pwm);
    engineEnable(FALSE);
}

void slave_loop(void) {
	/* Проверка АКБ */
    logicVoltageControl();
	/* Выключение устройства */
    logicTurnigOff();
} 