/*-----------------------------------------------------------------------------------------------------------------------------------*/
 /* 0.Documentation section
  -----------------------------------------------------------------------------------------------------------------------------------

  @file-profiler.h

 @brief:This file includes various Systick timer initialisation operations and handler to service the underflow

 @author: Vikrant Waje and Kiran Hegde

 @date:22 November 2017


 */
/*--------------------------------------------------------------------------------------------------------------------------------*/
/*Guard section*/
#ifndef INCLUDES_PROFILER_H_
#define INCLUDES_PROFILER_H_

/*---------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief:IRQ handler for Systick timer operations

  This handler gets invoked when a underflow occurs(transition from 1 to zero)

 @param:None


 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void SysTick_Handler();
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Initialise Systick timer

  Configuring various registers of Systick timer along with its MOD register

 @param:None


 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void SysTick_init();


#endif /* INCLUDES_PROFILER_H_ */
