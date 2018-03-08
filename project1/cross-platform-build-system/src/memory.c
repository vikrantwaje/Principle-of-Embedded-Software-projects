// 0. Documentation Section
// Title: To perform memory manipulation like memory move,memory copy,memory set,memory zero, reserve words, freewords, reverse
// Author: 1) Vikrant Waje 2) Kiran Hegde
// Date: 1 October 2017 
// Tools used: Linux command line, GCC, Beaglebone black, KL25Z, Host machine
/*---------------------------------------------------------------------------------------------------------------------------------------------*/

// 1. Preprocessor Directive Section

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include"memory.h"
/*--------------------------------------------------------------------------------------------------------------------------------------------*/

//2. Function definition

//	a) Input: Pointer to source location
//	b) Output: Frees the location which are allocated dynamically.
//	c)Function: Frees the heap which was reserved during dynamic allocation.


void free_words(uint32_t *src){

 free(src);
 }
/*-------------------------------------------------------------------------------------------------------------------------*/

//	a) Input: Size of input variable
//	b) Output:Pointer to memory location that is reserved dynamically.
//	c)Function: Allocates a block of location dynamically.

uint32_t* reserve_words(size_t length){


    uint32_t *p=malloc(sizeof(size_t)*length); //the function malloc will return base address for what type of data ,hence the pointer type is same
    if(p==NULL){
	#ifdef DEBUG
        printf("Unsuccessful memory allocation");
	#endif	
	}
        else{

            return(p);
           
        }
	return 0;
    }
/*--------------------------------------------------------------------------------------------------------------------------------------------------------*/
//	a)Input: Source pointer, Destination pointer, block size to be copied
//	b)Output: Returns pointer to destination.
//	c)Function: Copies block of data from source to destination with chances of corrupting data due to overlap.

uint8_t* my_memcpy(uint8_t *src,uint8_t *dst,size_t length){
int s=length;



// Copies block of memory from source to destination pointer without checking for overlap condition
while(length>0){
        *dst=*src;
        dst++;
        src++;
        length--;}
        int i=0;
        for(i=s;i>0;i--){
        dst--;}
        src=src-length;
        return(dst);
}
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//	a)Input: Source pointer, destination pointer, block size to be copied.
//	b)Output: Returns pointer to destination.
//	c)Function: Copies block of data from source to destination taking care of overlapping condition.


uint8_t* my_memmove(uint8_t *src,uint8_t *dst,size_t length){
int s=length;



//If destination address greater than source ,perform copying data from bottom
if(dst>src){

dst=dst+s-1;
src=src+s-1;
while(length>0){
        *dst=*src;
        
        dst--;
        src--;
        length--;}
        
}
//If source address is greater than destination, perform copying of data from top
else if(src>dst){


while(length>0){
        *dst=*src;
        
        dst++;
        src++;
        length--;}
        
}



        return(dst);
}
/*--------------------------------------------------------------------------------------------------------------------*/
//	 a)Input: Source pointer, destination pointer, value to which location is to be set.
//	 b)Output: Returns pointer to source location
//	 c)Function: Sets a block of memory location with given value.

uint8_t * my_memset(uint8_t *src,size_t length,uint8_t value){
int s=length;

// Set value of given memory block to a particular value
while(length!=0){
    *src=value;
	#ifdef DEBUG
    printf("%p %d\n",src,*src);
	#endif  
  length--;
    src++;
}
//Bring back the pointer to original source location
while(s!=0){
    src--;
    s--;

}
return(src);


}
/*----------------------------------------------------------------------------------------------------------------------*/
//	 a)Input: Source pointer, destination pointer, value to which location is to be cleared.
//	 b)Output: Returns pointer to source location
//	 c)Function: Clears the given block of memory location.

uint8_t *my_memzero(uint8_t *src,size_t length){
uint8_t s=length;
// Set value of given block of memory to zero
while(length!=0){
    *src=0;
    
    length--;
    src++;
}
// Bringing back pointer to original source location
while(s!=0){
    src--;
    s--;

}
return(src);


}
/*----------------------------------------------------------------------------------------------------------------------*/
//	 a)Input: Source pointer, size of string.
//	 b)Output: Returns pointer to memory location 
//	 c)Function: Reverses the input string.

uint8_t *my_reverse(uint8_t *src,size_t length){
uint8_t s=length;

//Dynamically allocating block of memory in heap
uint8_t *vol=malloc(length*sizeof(size_t));


// Temporarily storing value in heap
while(length!=0){
	*vol=*src;
	vol++;
	src++;
        
	

    	length--;
    	

}
src--;
// Reversing the string by help of value stored in heap.
while(s!=0 ){
    	*src=*(vol-s);
	src--;
	
	s--;
}
#ifdef DEBUG
printf("\n");
#endif
src++;
return(src);


}
