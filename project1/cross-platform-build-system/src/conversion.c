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

//				INTEGER TO ASCII CONVERSION

/*-----------------------------------------------------------------------------------------------------------------------*/



/*----------------------------Integer to Integer (base 10) conversion-----------------------------------------*/


uint8_t my_itoa(int32_t data,uint8_t*ptr,uint32_t base){
//Check for base
if(base==10){
	int8_t sign=0;
//Check for positive or negative value	
	if(data<0){
		data=-1*data;
		
		sign='-';
		}
int32_t q,r;
int8_t length=0;
q=r=data;
// Perform repetitive division until quotient is greater than base value
while(q>=base){
	q=q/10;
	r=data%10;
	*ptr=r;
	ptr++;
	data=data/10;
	length++;
	}

length++;
*ptr=q;
ptr++;
*ptr=0;
ptr--;


//Take backup of variable length in another variable
int8_t size=length;
int8_t len=length;

// Print the value of remainder obtained during division process
while(length>0){
  	printf("%d",(*ptr));
   	 ptr--;
    	length--;
	}
ptr=ptr+1;
// Process to handle signed integer
if(sign=='-'){
	ptr=ptr+size;
	*ptr=1;
      	printf("-");
	ptr--;

// Printing the negative value
    	while(size!=0){

    		printf("%d",*ptr);
    		ptr--;
    		size--;
		}

	}
ptr++;
return(len);
}

/*------------------Integer to Binary conversion by repetitive division by base 2--------------------------------------*/

//Check for base value
else if (base==2){
int8_t sign=0;

//Check whether data is positive or negative
if(data<0)
	{
	data=-1*data;
	sign='-';
	}


int32_t q,r;

int8_t length=0;
q=r=data;

// Perform repetitive division until quotient is greater than base value
while(q>=base){
	q=q/2;

	r=data%2;

	*ptr=r;
	ptr++;

	data=data/2;
	length++;
	}

length++;
#ifdef DEBUG
printf("%d\n",1);
#endif
*ptr=1;
ptr++;
*ptr=0;
ptr--;

//Take backup of variable length in another variable
int8_t size=length;
int8_t len=length;
int32_t s=length;


// Printing the remainder value obtained during division process
while(length!=0){
	#ifdef DEBUG
    printf("%d",*ptr);
	#endif    
	ptr--;
    length--;
	}

// Process to handle signed integer(performing two's complement to handle the signed integer)
if(sign=='-'){
	ptr++;
	while(size!=0){

	    while(*ptr==0){
	        ptr++;
	     size=size-1;
	    }
    *ptr=1;
    ptr++;
    size=size-1;
	    while(size!=0){
	       if(*ptr==1){
	        *ptr=0;
	        size=size-1;
	        ptr++;
	       }
	       else{

	        *ptr=1;
	        ptr++;
	        size=size-1;;

		       }
		}


	    }

*ptr=1;

}
printf("\n");
ptr=ptr-1;

//Returning pointer to point to MSB value
while(len!=0){
    
    ptr--;
    len--;
	}
return(s);
    }
/*----------------------------Integer to Hexadecimal number conversion----------------------------------------------*/
// Check for base
else if(base==16){
        int32_t back=data;

//Check whether number is positive or negative        
	if(data<0){
	data=-1*data;
	}
int8_t length=0;
int32_t q,r;
q=r=data;

//Perform repetitive division until quotient is greater than base
while(q>=base){
	q=q/16;
	r=data%16;
	*ptr=r;
	ptr++;
data=data/16;
length++;
	}
*ptr=q;
length++;
ptr++;
*ptr=0;
ptr--;

// Take backup of variable length in another variable
int32_t size=length;
int32_t len=length;
int32_t s=length;
uint32_t u;

//Print the value of remainder obtained during division process
while(length!=0){
    printf("%x",u=(*ptr));

    ptr--;
    length--;
	}
int32_t sub=0;
ptr=ptr+1;

//Process to handle signed integer
if(back<0)
{
ptr=ptr+s;
*ptr=1;
ptr=ptr-s;
while(size!=0){
	*ptr=(*ptr^0xF);
	*ptr=*ptr +0x1;
	*ptr = *ptr&0x0F;
	if(sub==1){
	    *ptr=*ptr-0x1;
	}
size--;
if(*ptr>0x00){ 
sub=1;
}
ptr=ptr+1;
}
ptr--; 

// Returns pointer to point towards MSB
while(len!=0){
    ptr--;
    len--;
	}
}
return(s);
}

/*---------------------------------------Integer to Octal Number conversion------------------------------------------------------*/
// Check for base value
else if(base==8){
        int32_t back=data;

// Check whether number is positive or negative
    	if(data<0){
	data= -1*data;
	}
int32_t q,r;
uint8_t length=0;
q=r=data;

//Perform repetitive division until quotient is greater than base value
while(q>=base) {
	q=q/8;
	r=data%8;
	*ptr=r;
	ptr++;
	data=data/8;
	length++;
	}
length++;
*ptr=q;
ptr++;
*ptr=0;
ptr--;

//Taking backup of variable length into another variable
int32_t size=length;
int32_t len=length;
int32_t s=length;
uint32_t u;

// Printing the remainder values obtained during division process
	while(length!=0){
	#ifdef DEBUG
    	printf("%o",u=(*ptr));
	#endif
    	ptr--;
    	length--;
	}
int32_t sub=0;
ptr=ptr+1;
#ifdef DEBUG
printf("\n");
#endif

// Process to handle signed integer(Performing two's complement)
if(back<0)
{
ptr=ptr+s;
*ptr=1;
ptr=ptr-s;
	while(size!=0)
	{
	*ptr=(*ptr^07);
	*ptr=*ptr +01;
	*ptr=*ptr&07;
		if(sub==1){
		    *ptr=*ptr-01;
		}
	size--;
	printf("%o\n",*ptr);
	if(*ptr>00){ 
		sub=1;
		}
	ptr=ptr+1;
	}
ptr--;
#ifdef DEBUG
printf("\n");
#endif
while(len!=0){
	#ifdef DEBUG
    printf("%o",u=(*ptr));
	#endif
    ptr--;
    len--;
	}
	}
	
	return(s);
	}
return 0;
}
/*------------------------------------------------------------------------------------------------*/

//                            ASCII TO INTEGER CONVERSION

/*------------------------------------------------------------------------------------------------*/

/*--------------------------Binary to Decimal conversion------------------------------------------*/

int32_t my_atoi(uint8_t*ptr,uint8_t digits,uint32_t base){

//Check for base value
if(base==2){

uint8_t size=digits;
int32_t u=0;
int32_t i;
int32_t *m=&i;
uint8_t overall=1;

// Performing binary to decimal conversion using multiplication by base algorithm
	while(digits!=0){

		 if(*ptr==0)
		 {
			*m=0;
    
    		u+=*m * overall;
		digits--;


		 }	
		else if(*ptr==1){
			*m=1;
		       u+=*m * overall;
			digits--;


 			} 
ptr++;

overall=overall*2;
}

ptr=ptr-1;

// Process to handle signed integer(Binary to signed integer conversion)
if(*(ptr+1)==1){
	overall=2;
	#ifdef DEBUG
	printf("%d\n",size);
	#endif
	u=convert(size,u,overall);
	
    return(u);
	}
printf("%d",u);
return(u);
}

/*-----------------------------------------Integer to base 10 conversion--------------------------------------------*/

//Check for base value
 if(base==10){

int32_t u=0;


int32_t overall=1;

// Converting ascii into integer by repetitive multiplication by base 10
	while(digits!=0){
		if(*ptr==1){
			u+=*ptr*overall;
			}
		if(*ptr==2){
		u+=*ptr*overall;
			}
		if(*ptr==3){
		u+=*ptr*overall;
		}
		if(*ptr==4){
		u+=*ptr*overall;
		}
		if(*ptr==5){
		u+=*ptr*overall;
		}
		if(*ptr==6){
		u+=*ptr*overall;
		}
		if(*ptr==7){
		u+=*ptr*overall;
		}
		if(*ptr==8){
		u+=*ptr*overall;
		}
		if(*ptr==9){
		u+=*ptr*overall;
		}
		ptr++;
		overall=overall*10;
		digits--;
		}

//Process to handle negative numbers
	if(*(ptr)==1){
		u=-1*u;

	}
return(u);
}

/*----------------------------------------------Hexadecimal to decimal conversion------------------------------------------*/
// Check for base value
if(base==16){
uint8_t size=digits;
int32_t u=0;
int32_t i;
int32_t *m=&i;
uint8_t overall=1;

// COnverting Hexadecimal to decimal by repetitve multiplication by base value
	while(digits!=0){

	 if(*ptr==0){
		*m=0;
    
    		u+=*m * overall;
		digits--;
		 }	
	else if(*ptr==1){
	*m=1;
    	u+=*m * overall;
	digits--;
	 }
	 else if(*ptr==2){
	  *m=2;
    	digits--;  
   	 u+= *m * overall;
 	}
 	else if(*ptr==3){
    	*m=3;
    	digits--;
   	 u+= *m * overall;
 	}
 	else if(*ptr==4){
    	*m=4;
    	digits--;
   	 u+= *m * overall;
 	}
 	else if(*ptr==5){
    	*m=5;
    	digits--;
       u+= *m * overall;
 	}
 	else if(*ptr==6){
 	   *m=6;
 	   digits--;
 	   u+= *m * overall;
 	}
 	else if(*ptr==7){
 	   *m=7;
 	   digits--;
 	
    	u+= *m * overall;
 	}
 	else if(*ptr==8){
    	*m=8;
    	digits--;
   
   	 u+= *m * overall;
 	}
 	else if(*ptr==9){
    	*m=9;
    	digits--;
   
   	 u+= *m * overall;
 	}
 	else if(*ptr==10){
    	*m=10;
    	digits--;
       u+= *m * overall;
 	}
 	else if(*ptr==11){
    	*m=11;
    	digits--;
   
   	 u+= *m * overall;
 	}
 	else if(*ptr==12){
    	*m=12;
    	digits--;
   
   	 u+= *m * overall;
 	}
 	else if(*ptr==13){
    	*m=13;
    	digits--;
   
   	 u+= *m * overall;
 	}
 	else if(*ptr==14){
    	*m=14;
    	digits--;
   
   	 u+= *m * overall;
 	}
 	else if(*ptr==15) {
    	*m=15;
    	digits--;
    	u+= *m * overall;
 	}
ptr++;

overall=overall*16;
#ifdef DEBUG
printf("%d\n",u);
#endif
}
ptr=ptr-1;

//Process to handle negative numbers
if(*(ptr+1)==1){
	overall=16;
	u=convert(size,u,overall);
		    return(u);
	}
	#ifdef DEBUG	
	printf("%d",u);
	#endif
	return(u);
	}
/*--------------------------------------------Octal to Decimal conversion-------------------------------------------*/
//Check for base value
if (base==8){
uint8_t size=digits;
int32_t u=0;
int32_t i;
int32_t *m=&i;
int32_t overall=1;

//Converting Octal to decimal by repetive multiplication by base
	while(digits!=0){

		 if(*ptr==0){
			*m=0;
			   u+=*m * overall;
			digits--;


		 }
		else if(*ptr==1)
		 {
		*m=1;

		 u+=*m * overall;
		digits--;


 		}
 		else if(*ptr==2){
    		*m=2;
    		digits--;
   
   		 u+= *m * overall;
 		}
 		else if(*ptr==3){
    		*m=3;
    		digits--;
   
   		 u+= *m * overall;
 		}
 		else if(*ptr==4){
    		*m=4;
    		digits--;
   
   		 u+= *m * overall;
 		}
 		else if(*ptr==5){
 		*m=5;
		digits--;
   
   		 u+= *m * overall;
 		}
 		else if(*ptr==6){
    		*m=6;
    		digits--;
   
   		 u+= *m * overall;
 		}
 		else if(*ptr==7){
    		*m=7;
    		digits--;
   
   		 u+= *m * overall;
 		}
ptr++;
overall=overall*8;
}
ptr=ptr-1;

// Process to handle negative numbers
if(*(ptr+1)==1){
	overall=8;

	u=convert(size,u,overall);
	    return(u);
	}
	#ifdef DEBUG
	printf("%d",u);
	#endif
	return(u);}

return 0;
	}



/*---------------------------------------------------------------------------------------------------------------------------------------*/


//					BIG TO LITTLE ENDIAN CONVERSION
			
/*---------------------------------------------------------------------------------------------------------------------------------------*/

int8_t big_to_little32(uint32_t *data,uint32_t length){
    uint32_t little;
    while(length!=0){

// Masking byte and then shifting the values to coreesponding position
        little=((*data &0X000000FF)<<24)|((*data &0X0000FF00)<<8)|((*data &0X00FF0000)>>8)|((*data &0XFF000000)>>24);
	#ifdef DEBUG
         printf("Littleendian convention of 0X%X is 0X%X\n",*data,little);
	 printf("\n");
	#endif
         length--;
         data++;




    }
    return 0;



}
/*--------------------------------------------------------------------------------------------------------------------------------------------*/

//					LITTLE TO BIG ENDIAN


/*----------------------------------------------------------------------------------------------------------------------------------------------*/
int8_t little_to_big32(uint32_t *data,uint32_t length){
    uint32_t little;
    while(length!=0){

// Masking and then shifting values to corresponding position
        little=((*data &0X000000FF)<<24)|((*data &0X0000FF00)<<8)|((*data &0X00FF0000)>>8)|((*data &0XFF000000)>>24);
	#ifdef DEBUG
         printf("Bigendian convention of 0X%X is 0X%X\n",*data,little);
	 printf("\n");
	#endif
         length--;
         data++;




    }
    return 0;
} 


