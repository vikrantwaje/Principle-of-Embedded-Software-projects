/*0. Documentation section
Title: Debug.c ,enabling print memory when Verbose is defined
Author:	a) Vikrant Waje
	b)Kiran Hegde
Date:30 September 2017
Tools used: Linux command line, GCC, Host machine, Beaglebone board, KL25z*/
/*---------------------------------------------------------------------------------------------------------------------*/
/*1. Preprocessor directives*/

#include<stdio.h>
#include <stdlib.h>
#include<stdint.h>

/*-------------------------------------------------------------------------------------------------------------------------*/
/*2. Guard*/

#ifdef VERBOSE




void print_memory(uint8_t *start,uint32_t length) 	//If VERBOSE is defined
{

while(length!=0){	
	
	#ifdef DEBUG
    printf("%x",*start);
	#endif
    start++;
    length--;

}
printf("\n");
}


#else
void print_memory(uint8_t *start,uint32_t length)
{
   
}

#endif
