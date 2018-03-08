// 	0. Documentation section

// Title: a)To perform integer to binary,hex,octal,decimal conversion.
//	  b)To perform ascii string(binary,hex,octal,decimal) to integer conversion.
//	  c) To perform big to little endian conversion on given data.
//	  d)To perform little to big endian conversion on given data

//Author: a) Vikrant Waje
//        b)Kiran Hegde

//Date:	  1 October 2017

//Tools used: Linux command line, GNU make, Beaglebone black, Host machine, FRDM KL25Z.
/*-----------------------------------------------------------------------------------------------------------------*/

// 1. Preprocessor directives 

#include<stdint.h>
#include<stdio.h>
/*----------------------------------------------------------------------------------------------------------------*/

// 2. User defined header files

#include "conversion.h"

/*----------------------------------------------------------------------------------------------------------------*/

// User defined function to handle recursive multiplication.

int32_t convert(uint8_t size,int32_t u,uint8_t overall){
uint32_t o=1;

// Perform repetitive multiplication to handle signed integer in ASCII to integer conversion

while(size!=0){
o*=overall;
	    
	size--;
	}
	u=(-(o)+u);

		return(u);
}
/*---------------------------------------------------------------------------------------------------------------*/
//3.Function definition

/*----------------------------------------------------------------------------------------------------------------------*/




/*---------------------------------------------------------------------------------------------------------------------------------------*/


//					BIG TO LITTLE ENDIAN CONVERSION
			
/*---------------------------------------------------------------------------------------------------------------------------------------*/

uint32_t big_to_little32(uint32_t *data,uint32_t length){
if(data==NULL){
return(1);//Check for null
}
  else{  //uint32_t *little;
    while(length!=0){

// Masking byte and then shifting the values to coreesponding position
        *data=((*data &0X000000FF)<<24)|((*data &0X0000FF00)<<8)|((*data &0X00FF0000)>>8)|((*data &0XFF000000)>>24);
	#ifdef DEBUG
         /*printf("Littleendian convention of 0X%X is 0X%X\n",*data,little);
	 printf("\n");*/
	#endif
         length--;
         data++;
}



    }
    return 0;



}
/*--------------------------------------------------------------------------------------------------------------------------------------------*/

//					LITTLE TO BIG ENDIAN


/*----------------------------------------------------------------------------------------------------------------------------------------------*/
uint32_t little_to_big32(uint32_t *data,uint32_t length){
if(data==NULL){
return(1);//Check for null
}
else{
    //uint32_t little;
    while(length!=0){

// Masking and then shifting values to corresponding position
       *data=((*data &0X000000FF)<<24)|((*data &0X0000FF00)<<8)|((*data &0X00FF0000)>>8)|((*data &0XFF000000)>>24);
	#ifdef DEBUG
         printf("Bigendian convention of 0X%X is 0X%X\n",*data,little);
	 printf("\n");
	#endif
         length--;
         data++;
}



    }
    return 0;
} 


