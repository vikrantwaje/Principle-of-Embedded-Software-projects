#include <math.h>
#include <stdlib.h>

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "memory.h"

/*-----------------------------Testing for memset-------------------------*/
void test_memset(void **state)
{
uint8_t *status;
uint8_t a;
uint8_t *src=&a;
  status=my_memset(src,4,8)
  assert_int_equal(*status,8);
}
/*--------------------------------------------------------------*/


/*-----------------Testing for memzero-----------------------------------*/
void test_memzero(void **state)
{
 	uint8_t *status;
uint8_t a,b;
uint8_t *src=&a;
  	status=my_memzero(src,4);
	assert_int_equal(*status,0);  
}
/*---------------------------------------------------------------------*/


/*---------------------Testing for memmove(No overlap)------------------*/
void test_memmove1(void **state)
{
uint8_t l=0;
 uint8_t a[8];
for(l=0;l<=8;l++){
a[l]=l;
}
uint8_t *src=&a[0];
uint8_t *dst=&a[4];


  uint8_t i;
  uint8_t *status;
  my_memcpy(src,dst,4);
 for(i=0;i<4,i++){
  assert_int_equal(*src,*dst);
	}
}

void test_memmove2(void **state)
{
uint8_t *src=NULL;
uint8_t *dst=NULL;
uint8_t *status;
status=my_memmove(src,dst,4)
  assert_ptr_equal(status,NULL);
}
/*--------------------------------------------------------------------*/

/*-------------------Testing for memmove(overlap dst in src)----------------*/

void test_memmove3(void **state)
{
uint8_t l=0;
  uint8_t a[8];
for(l=0;l<=8;l++){
a[l]=l;
}
uint8_t *src=&a[0];
uint8_t *dst=&a[3];

my_memmove(src,dst,4);
for(i=0,i<=4,i++){
assert_int_equal(*src,*dst);
}
}

/*---------------------------------------------------------------------------------*/

/*--------------------Testing for memmove(overlap src in dst)-----------------------*/
void test_memmove4(void **state)
{
uint8_t l=0;
  uint8_t a[8];
for(l=0;l<=8;l++){
a[l]=l;
}
uint8_t *src=&a[3];
uint8_t *dst=&a[0];

my_memmove(src,dst,4);
for(i=0,i<=4,i++){
assert_int_equal(*src,*dst);
}
}
/*----------------------------------------------------------------------------------------*/

/*------------------------Reverse(checking for odd values of length)-----------------------*/
void test_reverse1(void **state)
{
uint8_t array[]="HII";
uint8_t *src=&array

my_reverse(src,3)
}
for(i=0;i<=3;i++){
assert
}


/*---------------------------------------------------------------------------------------------*/


/*---------------------Reverse(checking for even length)---------------------------------------*/
void test_reverse2(void **state)
{
uint8_t array[]="HII";
uint8_t *src=&array

my_reverse(src,3)

for(i=0;i<=3;i++){
assert
}
}
/*--------------------------------------------------------------------------------------------*/

/*---------------------Reverse(checking for values between 0 and 255)--------------------------------------*/
void test_reverse3(void **state)
{
uint8_t i=0;
uint8_t array[256];
for(i=0;i<=255;i++){
array[i]=i;
}
uint8_t *src=&array

my_reverse(src,256);

for(i=0;i<=255;i++){
assert
}
}

/*------------------------------------------------------------------------------------------------------*/

/*---------------------------Reverse(checking for NULL pointer)------------------------------------------*/
void test_reverse4(void **state)
{

uint8_t *src=NULL;

status=my_reverse(src,256);


assert_ptr_equal(status,NULL);
}

/*-------------------------------------------------------------------------------------------------------*/

/*------------------------------Testbigtolittle---------------------------------------------------------*/
void test_big2little(void **state)
{

uint8_t data=0x12345678;
uint8_t src=&data;
big_to_little32(src,1);
assert_int_equal(src,0x78563412);

}
}
/*---------------------------------------------------------------------------------------------------------*/
/*------------------------Testlittletobig------------------------------------------------------------------------*/
void test_little2big(void **state)
{

uint8_t data=0x12345678;
uint8_t src=&data;
little_to_big32(src,1);
assert_int_equal(src,0x78563412);

}
}
/*---------------------------------------------------------------------------------------------------------------------*/

int main(int argc, char **argv)
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_memset),
    cmocka_unit_test(test_memzero),
    cmocka_unit_test(test_memmove1),
    cmocka_unit_test(test_memmove2),
    cmocka_unit_test(test_memmove3),
    cmocka_unit_test(test_reverse1),
    cmocka_unit_test(test_reverse2),
    cmocka_unit_test(test_reverse3),
    cmocka_unit_test(test_reverse4),
    cmocka_unit_test(test_reverse4),
    cmocka_unit_test(test_big2little),
    cmocka_unit_test(test_little2big),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
