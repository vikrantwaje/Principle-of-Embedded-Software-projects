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
#include<string.h>
//#include"profiler.h"


/*---------------------------------------------------------------------------------------------------------------------*/
/* Global declaration */
uint8_t ki;
uint8_t *pointer=&ki;
CB_t *Logger_q;
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
char array[1]={"LEDINIT"};

void led_init(){

	 SIM->SCGC5|=(1<<10);//Enables clock to PORTB
	PORTB->PCR[18]|=(1<<8);//Selects PORTB pin 18 as general purpose I/O
	GPIOB_PDDR|=(1<<18);//Sets the direction of PORTB pin 18 as output pin
	log_data("\n\r",2);
	strncpy(LB_t.id,"ID:",3);
	LB_t.LOG_ID=1;
	strncpy(LB_t.Rtc,"TIME:",5);
	LB_t.timestamp=3;
	strncpy(LB_t.loglen,"LENGTH:",7);
	LB_t.loglength=17;
	strncpy(LB_t. check,"CHECKSUM:",9);
	LB_t.checksum=8;
	strncpy(LB_t.overhead,"PAYLOAD:",8);
	strncpy(LB_t.payload,"LEDinitialised",14);

	log_item(&LB_t,51);
}
/*----------------------------------------------------------------------------------------------------------------------------*/
void project2()
{
	Logger_q=malloc(sizeof(CB_t));
	rx=malloc(sizeof(CB_t));
	CB_init(Logger_q,500);					/*Initialing the circular buffer for storing character*/
	CB_init(rx,9);					/*Initialising the buffer for transmitting character to terminal*/
	UART_configure();				/* Configuring UART*/
	led_init();
	SYSTEM_INITIALISED();
	//SysTick_init();
	PROFILING_STARTED();


	PROFILING_COMPLETED();
	//SysTick->CTRL=0;
	//PROFILING_RESULT();
	log_flush(338);
}
/*--------------------------------------------------------------------------------------------------------------------------------*/



////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
