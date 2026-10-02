/**
  ******************************************************************************
  * @file    logger.h
  * @brief   Header for logger module
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
#ifndef LOGGER_H
#define LOGGER_H

#ifdef __cplusplus
extern "C" {
#endif /* CPLUSPLUS */

/* Includes ------------------------------------------------------------------*/
#include "rfal_platform.h"

#if (USE_LOGGER == LOGGER_OFF && !defined(HAL_UART_MODULE_ENABLED))
#define UART_HandleTypeDef void
#endif /* LOGGER and HAL_UART_MODULE_ENABLED*/

/*
******************************************************************************
* DEFINES
******************************************************************************
*/
#define LOGGER_ON   1
#define LOGGER_OFF  0

/*!
 *****************************************************************************
 *  \brief  Writes out a formatted string via UART interface
 *
 *  This function is used to write a formatted string via the UART interface.
 *
 *****************************************************************************
 */
extern void logUsartInit(UART_HandleTypeDef *husart);

/*!
 *****************************************************************************
 *  \brief  Writes out a formatted string via UART interface
 *
 *  This function is used to write a formatted string via the UART interface.
 *
 *****************************************************************************
 */
extern int logUsart(const char *format, ...);

/*!
 *****************************************************************************
 *  \brief  helper to convert hex data into formatted string
 *
 *  \param[in] data : pointer to buffer to be dumped.
 *
 *  \param[in] dataLen : buffer length
 *
 *  \return hex formatted string
 *
 *****************************************************************************
 */
extern char *hex2Str(unsigned char *data, size_t dataLen);

#endif /* LOGGER_H */

