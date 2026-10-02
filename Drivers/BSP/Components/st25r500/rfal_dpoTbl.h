/**
  ******************************************************************************
  * @file           : rfal_dpo.h
  * @brief          :  RF Dynamic Power Table default values
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#ifndef ST25R500_DPO_H
#define ST25R500_DPO_H

/*
 ******************************************************************************
 * INCLUDES
 ******************************************************************************
 */
#include "rfal_dpo.h"


/*
 ******************************************************************************
 * GLOBAL DATA TYPES
 ******************************************************************************
 */
 
/*! Default DPO table */
/*  PRQA S 3674 2 # CERT ARR02 - Flexible array will be used with sizeof, on adding elements error-prone manual update of size would be required */
/*  PRQA S 3406 1 # MISRA 8.6 - Externally generated table included by the library */   /*  PRQA S 1514 1 # MISRA 8.9 - Externally generated table included by the library */ /*  PRQA S 1502 1 # MISRA 2.8 - Object usage dependent on feature switch (DPO vs DPO CR) */
const rfalDpoEntry rfalDpoDefaultSettings [] = { 
    { 0x00, 150, 100 },
    { 0x09, 110, 50  },
    { 0x0A, 60,  0   }
};

#endif /* ST25R500_DPO_H */
