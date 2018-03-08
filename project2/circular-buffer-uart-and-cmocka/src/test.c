/*-----------------------------------------------------------------------------------------------------------------------------------*/
 /* 0.Documentation section
  -----------------------------------------------------------------------------------------------------------------------------------

  @file-test.c

 @brief:This file includes unit testing on memmove,memset,memzero,big2little,little2big and various circular buffer operation.

 @author: Vikrant Waje and Kiran Hegde

 @date:27 October 2017


 */

/*------------------------------------------------------------------------------------------------------------------------------------*/

/*1. Preprocessor directives*/
#include <math.h>
#include <stdlib.h>

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "memory.h"
#include "conversion.h"
#include"cb.h"
#include<stdint.h>
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for memset

  Checks whether the memset function sets the value in block of memory successfully.

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------Testing for memset-------------------------*/
void test_memset(void **state)
{
uint8_t *status;
uint8_t a;
uint8_t *src=&a;
  status=my_memset(src,4,8); //Calls memset function with block length as 4 and with value as 8.
  assert_int_equal(*status,8);//Checks whether value is 8
}
/*--------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for memset(NULLPOINTER)

  Checks whether the memset function is able to handle NULL pointer.

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*------------------------Testing for memset(NULL pointer)---------------------------------------------------*/
void test_memset1(void **state)
{
uint8_t *src=NULL;
uint8_t *status;
status=my_memset(src,4,8);
  assert_ptr_equal(status,NULL);
}
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for memzero

  Checks whether the memzero function resets the value in block of memory successfully.

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/


/*-----------------Testing for memzero-----------------------------------*/
void test_memzero(void **state)
{
 	uint8_t *status;
uint8_t a;
uint8_t *src=&a;
  	status=my_memzero(src,4);// Call memzero function to reset value of block of memory which is of length 4
	assert_int_equal(*status,0);//Checks whether value is zero
}
/*---------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for memzero(NULLPOINTER)

  Checks whether the memzero function is able to handle NULL pointer.

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*------------------------Testing for memset(NULL pointer)---------------------------------------------------*/
void test_memzero1(void **state)
{
uint8_t *src=NULL;
uint8_t *status;
status=my_memzero(src,4);
  assert_ptr_equal(status,NULL);
}
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for memmove

  Checks whether the memmove function moves data from source to destination successfully without overlap successfully.

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/

/*---------------------Testing for memmove(No overlap)------------------*/
void test_memmove1(void **state)
{
uint8_t l=0;
 uint8_t a[8];
for(l=0;l<=8;l++){
a[l]=l;//load some value into source location and destination
}
uint8_t *src=&a[0];
uint8_t *dst=&a[4];


  uint8_t i;

  my_memmove(src,dst,4);
 for(i=0;i<4;i++){
  assert_int_equal(*(src+i),*(dst+i));//Checks whether value at destination location is same as source location.
	}
}
/*-------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for memmove

  Checks whether Source pointer is null when it is pointing to null

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
/*---------------------Testing for memmove(NULL POINTER)------------------*/
void test_memmove2(void **state)
{
uint8_t *src=NULL;
uint8_t *dst=NULL;
uint8_t *status;
status=my_memmove(src,dst,4);
  assert_ptr_equal(status,NULL);
}
/*--------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for memmove

  Checks whether a block of memory is copied successfully from source to destination location when there is overlap of destination into source

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/

/*-------------------Testing for memmove(overlap dst in src)----------------*/

void test_memmove3(void **state)
{
uint8_t i;
uint8_t l=0;
  uint8_t a[8];
for(l=0;l<=8;l++){
        //Load some random values into block of memory
a[l]=l;
}
//uint8_t *temp=&k;
uint8_t *src=&a[0];
uint8_t *dst=&a[3];

my_memmove(src,dst,4);//Calls memmove function
for(i=0;i<4;i++){
    //Checks whether the value at destination is successfully copied even in case of overlap condition.
assert_int_equal((i),*(dst+i));
}
}

/*---------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for memmove

  Checks whether a block of memory is copied successfully from source to destination location when there is overlap of source into destination.

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/

/*--------------------Testing for memmove(overlap src in dst)-----------------------*/
void test_memmove4(void **state)
{
uint8_t i;
uint8_t l=0;
  uint8_t a[8];
for(l=0;l<=8;l++){
    //load some random value into block of memory

a[l]=l;
}
uint8_t *src=&a[3];
uint8_t *dst=&a[0];
//uint8_t *temp=&k;


my_memmove(src,dst,4);//Call memmove function.
for(i=0;i<4;i++){
assert_int_equal((i+3),*(dst+i));//Checks whether the block of memory is been successfully copied into destination even in case of overlap.
}
}
/*----------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for Reverse function with odd length

  Checks whether the content of memory location are successfully reversed when length is odd

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/

/*------------------------Reverse(checking for odd values of length)-----------------------*/
void test_reverse1(void **state)
{uint8_t i;
uint8_t array[]="HII";//Original string which is to be reversed
uint8_t *src=array;
uint8_t temp[]="IIH";//Final reversed string which is to be compared with
my_reverse(src,3);

for(i=0;i<=3;i++){
    //Checks whether the content at memory location has been successfully reversed
assert_int_equal(*(src+i),temp[i]);
}
}


/*---------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for Reverse function with even length

  Checks whether the content of memory location are successfully reversed when length is even

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/

/*---------------------Reverse(checking for even length)---------------------------------------*/
void test_reverse2(void **state)
{uint8_t i;
uint8_t array[]="HIGH";//Original string which is to be reversed
uint8_t *src=array;
uint8_t temp[]="HGIH";//Final reversed string which is to be compared with.
my_reverse(src,4);

for(i=0;i<=3;i++){
    //Checks whether the content has been successfully reversed.
assert_int_equal(*(src+i),temp[i]);
}
}
/*--------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for Reverse function with values in memory from 0 to 255.

  Checks whether the values 0 to 255 are successfully reversed.

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/

/*---------------------Reverse(checking for values between 0 and 255)--------------------------------------*/
void test_reverse3(void **state)
{
uint8_t i=0;
uint8_t array[255];
for(i=0;i<255;i++){// Load some random data into block of memory
array[i]=i;
}
uint8_t *src=array;

my_reverse(src,255);//Calls reverse function.

for(i=0;i<255;i++){
assert_int_equal(*(src+i),(254-i));//Checks whether the contents are successfully reversed.
}
}

/*------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for Reverse function with NULL pointer.

  Checks whether the function reverse is able to handle NULL pointer

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/

/*---------------------------Reverse(checking for NULL pointer)------------------------------------------*/
void test_reverse4(void **state)
{

uint8_t *src=NULL;//Initialising source pointer to null.
uint8_t *status;
status=my_reverse(src,256);


assert_ptr_equal(status,NULL);
}

/*-------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for big to little endian conversion.

  Checks whether the given data is converted from big endian to little endian successfully.

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------Testbigtolittle---------------------------------------------------------*/
void test_big2little(void **state)
{

uint32_t data=0x12345678;//Data that has to be converted from big endian to little endian
uint32_t *src=&data;
big_to_little32(src,1);
assert_int_equal(*src,0x78563412);//Compared the little endian data with expected output.


}
/*---------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for big to little endian conversion.(with NULL pointer)

  Checks whether the little to big endian function is able to handle NULL pointer successfully.

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*------------------------------------------------------Bigtolittle(checking with NULL pointer)--------------------------------------------------------------------*/
void test_big2little1(void **state)
{

uint32_t *src=NULL;//Passing a NULL pointer to function
uint32_t status=big_to_little32(src,1);
assert_int_equal(status,1);//Check whether the return value is 1 which means that the pointer is NULL pointer


}
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for little to big endian conversion.

  Checks whether the given data is converted from little endian to big endian successfully.

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/

/*------------------------Testlittletobig------------------------------------------------------------------------*/
void test_little2big(void **state)
{

uint32_t data=0x12345678;//Data that has to be converted into big endian
uint32_t *src=&data;
little_to_big32(src,1);
assert_int_equal(*src,0x78563412);//Compare the converted data with expected result

}

/*---------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for little to big endian conversion.(with NULL pointer)

  Checks whether the little to big endian function is able to handle NULL pointer successfully.

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*------------------------------------------------------littletobig(checking with NULL pointer)--------------------------------------------------------------------*/

void test_little2big1(void **state)
{

uint32_t *src=NULL;//Passing a NULL pointer to function
uint32_t status=little_to_big32(src,1);
assert_int_equal(status,1);//Check whether the return value is 1 which means that the pointer is NULL pointer


}
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for Circular buffer.

  Checks whether the circular buffer is full.

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------Bufferfull----------------------------------------------------*/
void circularfull(void **state)
{
CB_t * ptr=malloc(sizeof(CB_t));

 CB_init(ptr,3);
//Add items until circular buffer
CB_buffer_add_item(ptr,3);
CB_buffer_add_item(ptr,4);
CB_buffer_add_item(ptr,5);
CB_status i=CB_is_full(ptr);//Checks whether buffer has got full.
assert_int_equal(i,0);

}
/*----------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for Circular buffer.

  Checks whether the circular buffer is empty.

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------Bufferempty---------------------------------------------------*/
void circularempty(void **state)
{uint8_t o;
uint8_t *temp=&o;
CB_t * ptr=malloc(sizeof(CB_t));

 CB_init(ptr,1);
CB_buffer_add_item(ptr,5);
CB_buffer__buffer_remove_item(ptr,temp);//Removing items from circular buffer when its empty
CB_status i=CB_buffer__buffer_remove_item(ptr,temp);

assert_int_equal(i,1);//Checking whether the CB return status is empty

}
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for Circular buffer.

  Checks whether the circular buffer is able to handle invalid pointer.

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
/*------------------------Invalid pointer------------------------------------------------------------------*/

void invalidpointer(void **state)
{

CB_t * ptr=malloc(sizeof(CB_t));

CB_status i= CB_init(ptr,3);//Initialises the circular buffer
assert_ptr_not_equal(i,null);//Checks whether after initialising the pointer is not NULL


}
/*--------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for Circular buffer.

  Checks whether the circular buffer is able to allocate the buffer of proper length

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/

/*------------------------Allocatefree-------------------------------------------------------------------------*/

void allocatefree(void **state)
{

CB_t * ptr=malloc(sizeof(CB_t));

CB_status i= CB_init(ptr,3);
assert_ptr_not_equal(i,null);// Check whether the pointer is not null
assert_int_equal(ptr->length,3);//Check whether the buffer has got initialised to proper length as expected


}
/*--------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for Circular buffer.

  Checks whether the circular buffer is able to allocate the buffer of proper length,with heead and tail pointer getting initialised to start

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------Noninitialisedbuffer---------------------------------------------------------*/
void noninitialisedbuffer(void **state)
{

CB_t * ptr=malloc(sizeof(CB_t));

CB_status i= CB_init(ptr,3);
assert_ptr_not_equal(i,null);//Check whether the pointer is not null
assert_int_equal(ptr->length,3);//check whether length of buffer is initialised as expected
assert_int_equal(ptr->count,0);//Check whether count is zero
assert_int_equal(ptr->head,ptr->buffptr);//Check whether head has got initialised to start
assert_int_equal(ptr->tail,ptr->buffptr);//Check whether tail has got initialised properly


}
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for Circular buffer.

  Checks whether the circular buffer is being removed with same value with which it has been added

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------Add-remove--------------------------------------------------------------*/
void addremove(void **state)
{
uint8_t o;
uint8_t *temp=&o;

CB_t * ptr=malloc(sizeof(CB_t));
CB_buffer_add_item(ptr,3);
CB_buffer__buffer_remove_item(ptr,temp);

 CB_init(ptr,3);
CB_buffer_add_item(ptr,3);
CB_buffer__buffer_remove_item(ptr,temp);

assert_ptr_equal(*temp,3);


}
/*--------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for Circular buffer.

  Checks whether the circular buffer is able to handle overfilling of buffer

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
/*-------------------------------Overfill-------------------------------------------------------------*/
void overfill(void **state)
{
CB_t * ptr=malloc(sizeof(CB_t));

 CB_init(ptr,3);
 //Add items into buffer until it gets full
CB_buffer_add_item(ptr,3);
CB_buffer_add_item(ptr,4);
CB_buffer_add_item(ptr,5);
CB_buffer_add_item(ptr,6);
//Check whether buffer has got full after overfilling and does not overwrite
CB_status i=CB_is_full(ptr);
assert_int_equal(i,0);


}
/*--------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for Circular buffer.

  Checks whether the circular buffer is able to handle overemptying of buffer

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/

/*-----------------------------Overempty----------------------------------------------------------*/
void overempty(void **state)
{
uint8_t o;
uint8_t *temp=&o;
CB_t * ptr=malloc(sizeof(CB_t));

 CB_init(ptr,1);
CB_status i=CB_buffer__buffer_remove_item(ptr,temp);//Remove item from circular buffer even when it is empty

assert_int_equal(i,1);// Check whether it returns empty status
}
/*--------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for Circular buffer.

  Checks whether the circular buffer is able to handle wrap around condition properly without overwriting the circular buffer(When head pointer is at the end)

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------Wrapadd--------------------------------------------------------*/
void wrapadd(void **state)
{
CB_t * ptr=malloc(sizeof(CB_t));

 CB_init(ptr,2);
 //Add items into circular buffer until wrap around occurs
CB_buffer_add_item(ptr,6);
CB_buffer_add_item(ptr,6);

assert_ptr_equal(ptr->head,ptr->buffptr);//Checks whether the head pointer is returned back to start of circular buffer
}
/*---------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Testing for Circular buffer.

  Checks whether the circular buffer is able to handle wrap around condition properly without overwriting the circular buffer(when tail pointer is at the end)

 @param: NONE
 @param:NONE

 @return: NONE
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------Wrapremove--------------------------------------------------------------------*/
void wrapremove(void **state)
{
uint8_t o;
uint8_t *temp=&o;
CB_t * ptr=malloc(sizeof(CB_t));

 CB_init(ptr,2);
 //Remove items until tail pointer reaches the end
CB_buffer_add_item(ptr,6);
CB_buffer_add_item(ptr,6);

CB_buffer__buffer_remove_item(ptr,temp);
CB_buffer__buffer_remove_item(ptr,temp);

assert_ptr_equal(ptr->tail,ptr->buffptr);//Check whether the tail pointer gets wrapped around properly
}
/*-------------------------------------------------------------------------------------------------------------------------------*/
/*1. Main section: Contains various test conditions*/
int main(int argc, char **argv)
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_memset),
    cmocka_unit_test(test_memset1),
   cmocka_unit_test(test_memzero),
cmocka_unit_test(test_memzero1),
   cmocka_unit_test(test_memmove1),
    cmocka_unit_test(test_memmove2),
    cmocka_unit_test(test_memmove3),
cmocka_unit_test(test_memmove4),
   cmocka_unit_test(test_reverse1),
    cmocka_unit_test(test_reverse2),
   cmocka_unit_test(test_reverse3),
   cmocka_unit_test(test_reverse4),

    cmocka_unit_test(test_big2little),
    cmocka_unit_test(test_big2little1),
    cmocka_unit_test(test_little2big),
    cmocka_unit_test(test_little2big1),
    cmocka_unit_test(circularfull),
   cmocka_unit_test(circularempty),
   cmocka_unit_test(invalidpointer),
   cmocka_unit_test(allocatefree),
   cmocka_unit_test(noninitialisedbuffer),
   cmocka_unit_test(addremove),
   cmocka_unit_test(overfill),
   cmocka_unit_test(overempty),
   cmocka_unit_test(wrapadd),
   cmocka_unit_test(wrapremove)


  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
