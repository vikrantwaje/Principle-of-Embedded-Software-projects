/*0.Documentation section
 Title: Main function that calls other test functions
 Author: a) Vikrant Waje
	b) Kiran Hegde
 Date:1 October 2017
 Tools used: Linux command line, GCC, Host machine, Beaglebone black board, FRDM KL25Z*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/
/*1. Preprocessor directives*/

#include<stdint.h>
#include<stdio.h>
/*------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* User defined header files*/


#include"project1.h"
/*--------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* Main function: The main part of function starts from here*/

int main()
{
#ifdef VERBOSE

#endif
/*test_data1(); // Checks for int to ascii conversion and viceversa
test_data2();	//Checks for int to ascii conversion and viceversa
test_memmove1(); //Checks for memory move with overlap avoidance
test_memmove2(); //Checks for memory move with overlap avoidance
test_memmove3();// Checks for memory move with overlap avoidance
test_memcpy();	//checks for memory copy
test_memset(); //Sets given block of memory to given value
test_reverse();// Reverses a string in memory location
*/

#ifdef PROJECT1
	project1();
#endif
 

}
