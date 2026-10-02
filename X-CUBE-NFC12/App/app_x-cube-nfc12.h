/**
  ******************************************************************************
  * File Name          :  stmicroelectronics_x-cube-nfc12_1_0_0.h
  * Description        : This file provides code for the configuration
  *                      of the STMicroelectronics.X-CUBE-NFC12.1.0.0 instances.
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
#ifndef APP_X_CUBE_NFCX_H
#define APP_X_CUBE_NFCX_H
#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "nfc_conf.h"
/* Exported Functions --------------------------------------------------------*/

void _Error_Handler(char *file, int line);
void MX_X_CUBE_NFC12_Init(void);
void MX_X_CUBE_NFC12_Process(void);
void BSP_NFC0XCOMM_IRQ_Callback(void);

#ifdef __cplusplus
}
#endif
#endif /* __INIT_H */

