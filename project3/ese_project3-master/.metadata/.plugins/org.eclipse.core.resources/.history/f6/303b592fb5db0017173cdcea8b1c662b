 /*-----------------------------------------------------------------------------------------------------------------------------------*/
 /* 0.Documentation section
  -----------------------------------------------------------------------------------------------------------------------------------

  @file-spi.h

 @brief:This file includes various SPI operations

 @author: Vikrant Waje and Kiran Hegde

 @date:23 November 2017


 */
/*--------------------------------------------------------------------------------------------------------------------------------*/
/* Guard section*/
#ifndef INCLUDES_SPI_H_
#define INCLUDES_SPI_H_

/*Function declaration*/
/*
  @brief: To configure SPI

  Configure the SPI by setting its appropriate register

 @param: None


 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void SPI_init();
/*--------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Reads a single character from SPI0_D register

  This basically reads a given byte from SPI0_D register

 @param: Variable into which value is to be read


 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/

void SPI_read_byte(uint8_t byte);
/*--------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Send a single character into SPI0_D register

  This basically transfers a given byte into SPI0_D register

 @param: Value that is to be sent


 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void SPI_write_byte(uint8_t byte);
/*--------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Send a given packet using SPI0_D register

  This basically transfers a given packet via SPI0_D register

 @param: Values that are to be sent, length of packet


 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void SPI_send_packet(uint8_t *ptr,size_t length);
/*--------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Flush the SPI0_S register

  This basically waits until the SPI0_D register getts empty

 @param: None


 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void SPI_flush();





#endif /* INCLUDES_SPI_H_ */
