//0. Documentation
// Title: conversion.h
// Functions:my_itoa,my_atoi,big_to_little32,little_to_big32
// Author: a) Vikrant Waje.
//	   b) Kiran Hegde.
//Date: 30 September 2017.

//1. Guards
#ifndef CONVERSION_H_

//2.Preprocessor macros
#define CONVERSION_H_


//3. Function declaration
/*---------------------------------------------------------------------------------------------*/

//my_itoa:Integer to ascii conversion
//Input: Data, Source pointer, Base to which number should be converted
//Output:Converted data string from integer 
uint8_t my_itoa(int32_t data,uint8_t*ptr,uint32_t base);

/*-------------------------------------------------------------------------------------*/
//my_atoi: Ascii to integer conversion
//Input: Source pointer, number of digits, base
// Output: Integer value
int32_t my_atoi(uint8_t*ptr,uint8_t digits,uint32_t base);

/*-----------------------------------------------------------------------------------------*/
//big_to_little: Converts from big endian to little endian
//Input:Data pointer, length of block
//Output: Data in terms of little endian convention
int8_t big_to_little32(uint32_t *data,uint32_t length);

/*-------------------------------------------------------------------------------------------*/
//little_to_big: Converts from little endian to big endian convention
//Input:data pointer, length of block
//Output: Data in terms of big endian convention
int8_t little_to_big32(uint32_t *data,uint32_t length);


#endif
