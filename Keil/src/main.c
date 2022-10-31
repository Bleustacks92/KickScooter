// #INDEX# ======================================================================================================
// Title .........: KickScooter
// Arch ..........: GD32F130C8C6, GD32F130C6C6
// Author ........: GreenBytes ( https://vk.com/greenbytes )
// Version .......: 3.5.0.0
// Date ..........: (27.04.2022) (10.01.2022) (29.08.2021)
// Comment .......: Железо расчитанно на 8 кГц, но необходимо 16 кГц для достижения максимального КПД двигателя. _
// ...............: АЦП процессора не способно получить информацию с датчика тока при 16 кГц, не хватает скорости. _
// ...............: По этому решено НЕ использовать фазные датчики тока.
// Instruction ...:  
// ==============================================================================================================

# define ARM_MATH_CM3

# include "gd32f1x0.h"
# include "framework/framework.h"
# include "device/device.h"
# include "config/config.h"
# include "BLDC/bldc.h"
# include "logical/logical.h"

/* Точка входа в программу */
int main(void) {
	/* Инициализация функций процессора */
	fw_init();
	/* Инициализация функций платы */
	dev_init();
	/* Инициализация конфигурации */
	conf_init();
	/* Инициализация двигателя */
	engine_init();
	/* Инициализация логики */
	logic_init();
	/* Инициализация протокола */
	datap_init();
	/* Основной цикл программы */
  	while (1) {
		/* Цикл логики */
		logic_loop();
		/* Цикл Device */
		dev_loop();
	}
}
