/*-----------------------------------------------------------------------------------------------------------------------------------*/
 /* 0.Documentation section
  -----------------------------------------------------------------------------------------------------------------------------------

  @file-nrf.h

 @brief:This file includes various nrf initialisation operations

 @author: Vikrant Waje and Kiran Hegde

 @date:23 November 2017


 */
/*--------------------------------------------------------------------------------------------------------------------------------*/

/* Guard section*/
#ifndef INCLUDES_NRF_H_
#define INCLUDES_NRF_H_

/*------------------------------------------------------------------------------------------------------------*/
/*------------------------Macros*-------------------------------------------------------------------------*/
//PA18 AS CHIP SELECT

/*---------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Chip enable

  This macro basically enables chip select

 @param:None


 @return: None.
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/

__inline__ void nrf_chip_enable();
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Chip disable

  This macro basically disables chip select

 @param:None


 @return: None.
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/

__inline__ void nrf_chip_disable();
/*------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: NRF read register

  This function basically reads register

 @param:Address of register that is to be read


 @return: Value that is to be returned after being read.
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/


uint8_t nrf_read_register(uint8_t registeraddress);
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: NRF write register

  This function basically writes register

 @param:Address of register that is to be written


 @return:None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/

void nrf_write_register(uint8_t registeraddress,uint8_t value);
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: NRF read status

  This function reads status from status register

 @param:None


 @return:None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
uint8_t nrf_read_status();
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: NRF write configuration

  This function writes into configuration register

 @param:configuration that is to be set


 @return:None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void nrf_write_config(uint8_t config);
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: NRF read configuration

  This function reads from configuration register

 @param:None


 @return:None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
uint8_t read_config();
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: NRF read rf setup

  This function reads from configuration register

 @param:None


 @return:None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
uint8_t nrf_read_rf_setup();
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: NRF write rf setup

  This function write to configuration register

 @param:Configuration that is to be written


 @return:None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/

void nrf_write_rf_setup(uint8_t config);
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: NRF read rf channel

  This function reads from RF channel register

 @param:None


 @return:Returns value that is read
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
uint8_t nrf_read_rf_ch();
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: NRF write rf channel register

  This function write to rf channel register

 @param:Channel that is to be written


 @return:None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void nrf_write_rf_ch(uint8_t channel);
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: NRF read TX ADDR channel

  This function reads from TX ADDR register

 @param: Address of TX addr register


 @return:None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void nrf_read_TX_ADDR(uint8_t *address);
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: NRF write TX ADDR channel

  This function writes into TX ADDR register

 @param: Address of TX addr register


 @return:None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void nrf_write_TX_ADDR(uint8_t *tx_addr);
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: NRF read rf_fifo status channel

  This function reads from fifo status register

 @param:None


 @return:Returns status that is read
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
uint8_t nrf_read_fifo_status();
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: NRF flush tx fifo

  This function flushes the tx fifo register

 @param:None


 @return:None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void nrf_flush_tx_fifo();
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: NRF flush rx fifp

  This function flushes the rx fifo register

 @param:None


 @return:None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void nrf_flush_rx_fifo();




#endif /* INCLUDES_NRF_H_ */
