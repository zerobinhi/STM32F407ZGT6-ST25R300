/**
  ******************************************************************************
  * @file    timer.h
  * @brief   Header for timer module
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
#ifndef TIMER_H
#define TIMER_H

#ifdef __cplusplus
extern "C" {
#endif

/*
******************************************************************************
* INCLUDES
******************************************************************************
*/
#include <stdint.h>
#include <stdbool.h>

/*
******************************************************************************
* GLOBAL MACROS
******************************************************************************
*/
#define timerIsRunning(t)            (!timerIsExpired(t))

/*
******************************************************************************
* GLOBAL DEFINES
******************************************************************************
*/

/*!
*****************************************************************************
* \brief  Calculate Timer
*
* This method calculates when the timer will be expired given the amount
* time in milliseconds /a tOut.
* Once the timer has been calculated it will then be used to check when
* it expires.
*
* \see timersIsExpired
*
* \param[in]  tOut : time/duration in Milliseconds for the timer
*
* \return u32 : The new timer calculated based on the given time
*****************************************************************************
*/
uint32_t timerCalculateTimer(uint16_t tOut);

/*!
 *****************************************************************************
 * \brief  Checks if a Timer is Expired
 *
 * This method checks if a timer has already expired.
 * Based on the given timer previously calculated it checks if this timer
 * has already elapsed
 *
 * \see timersCalculateTimer
 *
 * \param[in]  timer : the timer to check
 *
 * \return true  : timer has already expired
 * \return false : timer is still running
 *****************************************************************************
 */
bool timerIsExpired(uint32_t timer);

/*!
 *****************************************************************************
 * \brief  Gets the remaining time
 *
 * This method gets the remaining time until the given timer expires.
 * In case the timer it has expired already, it will return zero.
 *
 * \see timerIsExpired
 *
 * \param[in]  timer : the timer to check
 *
 * \return u32 : The time remaining until timer expiration
 *****************************************************************************
 */
uint16_t timerGetRemaining(uint32_t timer);

/*!
*****************************************************************************
* \brief  Performs a Delay
*
* This method performs a delay for the given amount of time in Milliseconds
*
* \param[in]  tOut : time/duration in Milliseconds of the delay
*
*****************************************************************************
*/
void timerDelay(uint16_t tOut);

/*!
 *****************************************************************************
 * \brief  Stopwatch start
 *
 * This method initiates the stopwatch to later measure the time in ms
 *
 *****************************************************************************
 */
void timerStopwatchStart(void);

/*!
 *****************************************************************************
 * \brief  Stopwatch Measure
 *
 * This method returns the elapsed time in ms since the stopwatch was initiated
 *
 * \return The time in ms since the stopwatch was started
 *****************************************************************************
 */
uint32_t timerStopwatchMeasure(void);

#endif /* TIMER_H */
