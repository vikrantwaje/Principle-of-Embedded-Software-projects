/*
 * project3.c
/*-----------------------------------------------------------------------------------------------------------------------------*/
/* 0.Documentation section
  -----------------------------------------------------------------------------------------------------------------------------------

  @file-project3.c

 @brief: Calls spi function and comunicates with nrf module

 @author: Vikrant Waje and Kiran Hegde

 @date:28 November 2017


 */
/*-----------------------------------------------------------------------------------------------------------*/
// 1.Preprocessor directives

#include "MKL25Z4.h"
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include"profiler.h"
#include"spi.h"
#include"nrf.h"
#include"gpio.h"

/*----------------------------------------------------------------------------------------------------------------------*/
/* Function declaration */
/*
  @brief: Calling of all initialise function of spi and nrf module

  This function calls all the initialization functions of spi and nrf module , also includes function

 @param: None

 @return: None
 */
/*----------------------------------------------------------------------------------------------------------------*/
void project3(){
uint8_t temp;
        CE_enable();
		SPI_init();
		nrf_write_rf_ch(0x89);
			temp=nrf_read_rf_ch();
}
