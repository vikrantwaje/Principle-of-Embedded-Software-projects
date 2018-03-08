 /*-----------------------------------------------------------------------------------------------------------------------------------*/
 /* 0.Documentation section
  -----------------------------------------------------------------------------------------------------------------------------------

  @file-project2.c

 @brief:This file intilises all the buffers, generates buffer report and
 	 	- takes care of displaying required elements through UART.

 @author: Vikrant Waje and Kiran Hegde

 @date:29 October 2017


 */
/*--------------------------------------------------------------------------------------------------------------------------------*/
/*1. Preprocessor Directives*/

#include "MKL25Z4.h"
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include"uart.h"
#include"cb.h"
#include "project2.h"

/*---------------------------------------------------------------------------------------------------------------------*/
/* Global declaration */
uint8_t ki;
uint8_t *pointer=&ki;
CB_t *tx;
CB_t *rx;
uint8_t  *loc;
uint8_t c;
uint8_t f;
uint8_t alphacount=0;
uint8_t numericcount=0;
uint8_t count=0;
uint8_t b;
uint8_t *receive=&b;
uint8_t s1=10;
uint8_t s2=10;
uint8_t e;
uint8_t *receivea=&e;
/*---------------------------------------------------------------------------------------------------------------------*/

/* Function declaration */
/*
  @brief: Calling of all initialise function and displaying the report

  This function calls all the initialization functions and takes care of displaying the required
  elements on the serial terminal

 @param: None

 @return: None
 */

/*----------------------------------------------------------------------------------------------------------------------------*/
void project2()
{
	tx=malloc(sizeof(CB_t));
	rx=malloc(sizeof(CB_t));
	CB_init(tx,18);					/*Initialing the circular buffer for storing character*/
	CB_init(rx,9);					/*Initialising the buffer for transmitting character to terminal*/
	UART_configure();				/* Configuring UART*/
	UART_send_n("\n\r",2);
	UART_send_n("\n\rWelcome to ECEN5813 Project2\n\r",32);
	while(1)
	{
		if(*pointer==0x1B)			/* Check if its a escape key*/
		{
			*pointer='\0';
			int numb=10;
			UART_send_n("\n\r", 2);
			volatile uint8_t countbackup = tx->count;
			//UART_send_n("hello \n\r", 8);
			while(countbackup!=0)						/* for all elements of circular buffer*/
			{
				s2=CB_buffer__buffer_remove_item( tx, receive);
				//if(s2!=empty)
				if((*receive>=0x41 && *receive <=0x5A)||(*receive>=0x61 && *receive<=0x7A))  /*check if alphabet*/
				{
					alphacount++;
					count++;
				}
				else if(*receive>=0x30 && *receive <=0x39)			/*check if its a number*/
				{
					numericcount++;
					count++;
				}
				else
				{
					count++;										/*total count*/
				}
				countbackup--;
			}

			uint8_t *n=&f;
			my_itoa(alphacount, n, 10);						/* Convert alphacount from integerto ASCII*/
			UART_send_n("ALPHABETIC COUNT IS\t",20);
			UART_send_str(&f);
			UART_send_n("\n\r",2);
			my_itoa(numericcount, n, 10);					/* Convert numericcount from integerto ASCII*/
			UART_send_n("NUMERIC COUNT IS\t",17);
			UART_send_str(&f);
			UART_send_n("\n\r",2);
			uint8_t othercount = (count-(alphacount+numericcount)); /*symbol count*/
			my_itoa(othercount, n, 10);						/* Convert othercount from integerto ASCII*/
			UART_send_n("OTHER COUNT IS\t\t",16);
			UART_send_str(&f);
			UART_send_n("\n\r",2);
			my_itoa(count, n, 10);							/* Convert total count from integerto ASCII*/
			UART_send_n("TOTAL COUNT IS\t\t",16);
			UART_send_str(&f);
			UART_send_n("\n\r",2);
			UART_send_n("Done",4);
			UART_send_n("\n\r",2);
			alphacount=0;									/* Reset all the number to zero once done*/
			numericcount=0;
			count=0;
			othercount=0;
		}
	}
}
/*--------------------------------------------------------------------------------------------------------------------------------*/



////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
