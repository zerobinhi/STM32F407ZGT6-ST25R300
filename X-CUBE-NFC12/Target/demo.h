/**
  ******************************************************************************
  * @file           : demo.h
  * @brief          : Header for polling tag detect
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef DEMO_H
#define DEMO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include "st_errno.h"

/** @addtogroup X-CUBE-NFC12_Applications
  *  @{
  */

/** @addtogroup PollingTagDetect
  *  @{
  */

/** @defgroup PTD_Demo
  *  @brief Demo functions containing the example code
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */
/** @defgroup PTD_Demo_Exported_Functions
  *  @{
  */
bool demoIni(void);
void demoCycle(void);
void demoStop(void);
uint16_t demoGetDiscoverTechs2Find(void);
uint16_t demoGetDiscoverTotalDuration(void);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* DEMO_H */

