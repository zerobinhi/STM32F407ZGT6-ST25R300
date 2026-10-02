/**
  ******************************************************************************
  * @file    timer.c
  * @brief   SW Timer implementation
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

/* Includes ------------------------------------------------------------------*/
#include "timer.h"
#include "rfal_platform.h"

/*
******************************************************************************
* LOCAL DEFINES
******************************************************************************
*/

/*
******************************************************************************
* LOCAL VARIABLES
******************************************************************************
*/

static uint32_t timerStopwatchTick;

/*
******************************************************************************
* LOCAL FUNCTIONS
******************************************************************************
*/

static int32_t timerCalcDiff(uint32_t timer)
{
  uint32_t uDiff;
  int32_t  sDiff;

  uDiff = (timer - platformGetSysTick());   /* Calculate the diff between the timers */
  sDiff = (int32_t)uDiff;                   /* Convert the diff to a signed var      */

  /* Having done this has two side effects:
  * 1) all differences smaller than -(2^31) ms (~25d) will become positive
  *    Signaling not expired: acceptable!
  * 2) Time roll-over case will be handled correctly: super!
  */
  return sDiff;
}

/*
******************************************************************************
* GLOBAL FUNCTIONS
******************************************************************************
*/

/*******************************************************************************/
uint32_t timerCalculateTimer(uint16_t tOut)
{
  return (platformGetSysTick() + tOut);
}

/*******************************************************************************/
bool timerIsExpired(uint32_t timer)
{
  return ( timerCalcDiff(timer) < 0 );
}

/*******************************************************************************/
uint16_t timerGetRemaining(uint32_t timer)
{
  int32_t diff;

  diff = timerCalcDiff( timer );
  return (( diff > 0) ? ((uint16_t)diff) : 0U);
}

/*******************************************************************************/
void timerDelay(uint16_t tOut)
{
  uint32_t t;

  /* Calculate the timer and wait blocking until is running */
  t = timerCalculateTimer(tOut);
  while (timerIsRunning(t)){};
}

/*******************************************************************************/
void timerStopwatchStart(void)
{
  timerStopwatchTick = platformGetSysTick();
}

/*******************************************************************************/
uint32_t timerStopwatchMeasure(void)
{
  return (uint32_t)(platformGetSysTick() - timerStopwatchTick);
}

