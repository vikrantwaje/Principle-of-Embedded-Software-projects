/*
 * gpio.c
/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*-----------------------------------------------------------------------------------------------------------------------------------*/
 /* 0.Documentation section
  -----------------------------------------------------------------------------------------------------------------------------------
  @file-gpio.c
 @brief:This file includes various nrf initialisation operations
 @author: Vikrant Waje and Kiran Hegde
 @date:23 November 2017
 */
/*--------------------------------------------------------------------------------------------------------------------------------*/

#include "MKL25Z4.h"
#include<stddef.h>

/*---------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Chip enable
  This macro basically enables chip select
 @param:None
 @return: None.
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/

void nrf_chip_enable(){
	SIM->SCGC5|=(1<<9);
		PORTA->PCR[12]|=(1<<8);
		GPIOA_PDDR|=(1<<12);
		GPIOA_PDOR|=(0<<12);


}

/*---------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Chip disable
  This macro basically disables chip select
 @param:None
 @return: None.
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void nrf_chip_disable(){
	SIM->SCGC5|=(1<<9);
		PORTA->PCR[12]|=(1<<8);
		GPIOA_PDDR|=(1<<12);
		GPIOA_PDOR|=(1<<12);


}
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Chip enable
  This macro basically disables chip select
 @param:None
 @return: None.
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void CE_enable(){

	SIM->SCGC5|=(1<<11);
				PORTC->PCR[11]|=(1<<8);
				GPIOC_PDDR|=(1<<11);
				GPIOC_PSOR|=(1<<11);
}
