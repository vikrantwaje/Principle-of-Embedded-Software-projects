#include<stdio.h>
#include<stdint.h>

#ifndef CONVERSION_H_
#define CONVERSION_H_
uint8_t my_itoa(int32_t data,uint8_t*ptr,uint32_t base);
int32_t my_atoi(uint8_t*ptr,uint8_t digits,uint32_t base);
uint32_t big_to_little32(uint32_t *data,uint32_t length);
uint32_t little_to_big32(uint32_t *data,uint32_t length);


#endif
