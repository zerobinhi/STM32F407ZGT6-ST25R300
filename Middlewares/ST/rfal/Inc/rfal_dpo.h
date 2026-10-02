
/**
  ******************************************************************************
  * @file           : rfal_dpo.h
  * @brief          : Dynamic Power Output
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
 

#ifndef RFAL_DPO_H
#define RFAL_DPO_H

/*
 ******************************************************************************
 * INCLUDES
 ******************************************************************************
 */
#include "rfal_platform.h"
#include "rfal_utils.h"

/*
 ******************************************************************************
 * GLOBAL DEFINES
 ******************************************************************************
 */

#define RFAL_DPO_TABLE_MAX_ENTRIES   4U                                                        /*!< Max DPO table entries */
#define RFAL_DPO_TABLE_PARAM_LEN     sizeof(rfalDpoEntry)                                      /*!< DPO Parameter length  */
#define RFAL_DPO_TABLE_SIZE_MAX      (RFAL_DPO_TABLE_MAX_ENTRIES * RFAL_DPO_TABLE_PARAM_LEN)   /*!< Max DPO table size    */

/*
******************************************************************************
* GLOBAL TYPES
******************************************************************************
*/

/*! Function pointer to the reference Measurement method */
typedef ReturnCode (*rfalDpoMeasureFunc)(uint8_t* res);

/*! Function pointer to the Adjustment method */
typedef ReturnCode (*rfalDpoAdjustFunc)(uint8_t res);


/*! DPO table entry struct */
typedef struct 
{
    uint8_t rfoRes;                      /*!< Setting for the resistance level of the RFO */
    uint8_t inc;                         /*!< Threshold for incrementing the output power */ 
    uint8_t dec;                         /*!< Threshold for decrementing the output power */
}rfalDpoEntry;


/*! DPO information struct */
typedef struct
{
    bool               enabled;           /*!< Enabled state                   */
    uint8_t            tableEntries;      /*!< Number of entries used          */
    uint8_t            tableEntry;        /*!< Current entry used              */
    uint8_t            refMeasurement;    /*!< Last measurement used to adjust */
    rfalDpoAdjustFunc  adjustCallback;    /*!< Pointer to the adjust callback  */
    rfalDpoMeasureFunc measureCallback;   /*!< Pointer to the measure callback */
} rfalDpoInfo;


/*
******************************************************************************
* GLOBAL FUNCTION PROTOTYPES
******************************************************************************
*/


/*! 
 *****************************************************************************
 * \brief  Initialize dynamic power table
 *  
 *  This function sets the internal dynamic power table to the default 
 *  values stored in rfal_DpoTbl.h
 *  
 *****************************************************************************
 */
void rfalDpoInitialize( void );


/*! 
 *****************************************************************************
 * \brief  Set the Measurement method
 *  
 * This function sets the measurement method used for reference measurement.
 * Based on the measurement the power will then be adjusted
 *  
 * \param[in]  pFunc: callback of measurement function
 *
 *****************************************************************************
 */
void rfalDpoSetMeasureCallback( rfalDpoMeasureFunc pFunc );


/*! 
 *****************************************************************************
 * \brief  Set the Adjust method
 *  
 * This function sets the Adjust method used during DPO adjust 
 *  
 * \param[in]  pFunc: callback of adjust function
 *
 *****************************************************************************
 */
void rfalDpoSetAdjustCallback( rfalDpoAdjustFunc pFunc );


/*! 
 *****************************************************************************
 * \brief  Write dynamic power table
 *  
 * Load the dynamic power table  
 *
 * \param[in]  powerTbl        :  location of power Table to be loaded
 * \param[in]  powerTblEntries : number of entries of the power Table to be loaded
 * 
 * \return RFAL_ERR_NONE    : No error
 * \return RFAL_ERR_PARAM   : if configTbl is invalid
 * \return RFAL_ERR_NOMEM   : if the given Table is bigger exceeds the max size
 *****************************************************************************
 */
ReturnCode rfalDpoTableWrite( const rfalDpoEntry* powerTbl, uint8_t powerTblEntries );

/*! 
 *****************************************************************************
 * \brief  Dynamic power table Read
 *  
 * Read the dynamic power table  
 *
 * \param[out]   tblBuf        : location to the rfalDpoEntry[] to place the Table 
 * \param[in]    tblBufEntries : number of entries available in tblBuf to place the power Table
 * \param[out]   tableEntries  : returned number of entries actually written into tblBuf
 * 
 * \return RFAL_ERR_NONE    : No error
 * \return RFAL_ERR_PARAM   : if configTbl is invalid or parameters are invalid
 *****************************************************************************
 */
ReturnCode rfalDpoTableRead( rfalDpoEntry* tblBuf, uint8_t tblBufEntries, uint8_t* tableEntries );


/*! 
 *****************************************************************************
 * \brief  Dynamic power adjust
 *  
 * It measures the current output and adjusts the power accordingly to 
 * the dynamic power table.
 * This method | The adjustment shall be performed when the device 
 * is already emiting RF field
 * 
 * \return RFAL_ERR_NONE        : No error
 * \return RFAL_ERR_PARAM       : if configTbl is invalid or parameters are invalid
 * \return RFAL_ERR_WRONG_STATE : if the current state is valid for DPO Adjustment
 *****************************************************************************
 */
ReturnCode rfalDpoAdjust( void );


/*! 
 *****************************************************************************
 * \brief  Dynamic power set enabled state
 *  
 * \param[in] enable : new active state
 *
 * Set state to enable or disable the Dynamic power adjustment 
 * 
 *****************************************************************************
 */
void rfalDpoSetEnabled( bool enable );


/*! 
 *****************************************************************************
 * \brief  Get the Dynamic power enabled state
 *  
 * Get state of the Dynamic power adjustment 
 * 
 * \return true   : DPO is enabled
 * \return false  : DPO is disabled
 *****************************************************************************
 */
bool rfalDpoIsEnabled( void );


/*! 
 *****************************************************************************
 * \brief  Request DPO adjust
 *  
 *  Flags the DPO module to perform the adjustment on the next round, even
 *  if no change has been perceived from previous measurement|state
 
 *****************************************************************************
 */
void rfalDpoReqAdj( void );


/*!
 *****************************************************************************
 * \brief  Get DPO information
 *  
 * Get the DPO information|status
 *
 * \param[out] info       : pointer where DPO info is to be stored
 * 
 * \return RFAL_ERR_PARAM : Invalid parameters
 * \return RFAL_ERR_NONE  : No Error
 *****************************************************************************
 */
ReturnCode rfalDpoGetInfo( rfalDpoInfo* info );

#endif /* RFAL_DPO_H */

/**
  * @}
  *
  * @}
  *
  * @}
  */
