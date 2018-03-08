
#include <stdint.h>
#include "debug.h"
#include"platform.h"
#include "project1.h"
#include "memory.h"
#include "conversion.h"



int8_t test_data1() {
  uint8_t * ptr;
  int32_t num =-8;
  uint32_t digits;
  int32_t value;

	#ifdef DEBUG
  printf("\ntest_data1();\n");
	#endif
  ptr = (uint8_t*) reserve_words( DATA_SET_SIZE_W );

  if (! ptr )
  {
    return TEST_ERROR;
  }

  digits = my_itoa( num, ptr, 2);  
  value = my_atoi( ptr, digits, 2);
  #ifdef VERBOSE
  printf("  Initial number: %d\n", num); 
  printf(" digits : %x\n", digits); 
  printf("  Final Decimal number: %d\n", value);  
  #endif
  free_words( (uint32_t*)ptr );

  if ( value != num )
  {
    return TEST_ERROR;
  }
  return TEST_NO_ERROR;
}

int8_t test_data2() {
  uint8_t * ptr;
  int32_t num = -45;
  uint32_t digits;
  int32_t value;
	#ifdef DEBUG
  printf("test_data2();\n");
	#endif
  ptr = (uint8_t*) reserve_words( DATA_SET_SIZE_W );

  if (! ptr )
  {
    return TEST_ERROR;
  }

  digits = my_itoa( num, ptr, 2);
#ifdef DEBUG
printf("length=%d\n",digits);
#endif

  value = my_atoi( ptr, digits, 2);
  #ifdef VERBOSE
  printf("  Initial Decimal number: %d\n", num);  
  printf("  Final Decimal number: %d\n", value);  
  #endif
  free_words( (uint32_t*)ptr );

  if ( value != num )
  {
    return TEST_ERROR;
  }
  return TEST_NO_ERROR;
}

int8_t test_memmove1() {
  uint8_t i;
  int8_t ret = TEST_NO_ERROR;
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;
	#ifdef DEBUG
  printf("test_memmove1() - NO OVERLAP\n");
  #endif
  set = (uint8_t*) reserve_words( MEM_SET_SIZE_W );

  if (! set ) 
  {
    return TEST_ERROR;
  }
  
  ptra = &set[0];
  ptrb = &set[16];
  
  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++)
  {
    set[i] = i;
  }
	#ifdef VERBOSE
  print_memory(set, MEM_SET_SIZE_B);
	#endif
  my_memmove(ptra, ptrb, TEST_MEMMOVE_LENGTH);
	#ifdef VERBOSE
  print_memory(set, MEM_SET_SIZE_B);
	#endif
  for (i = 0; i < TEST_MEMMOVE_LENGTH; i++)
  {
    if (set[i + 16] != i)
    {
      ret = TEST_ERROR;
    }
  }

  free_words( (uint32_t*)set );
  return ret;
}

int8_t test_memmove2() {
  uint8_t i;
  int8_t ret = TEST_NO_ERROR;
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;
	#ifdef DEBUG
  printf("test_memmove2() -OVERLAP END OF SRC BEGINNING OF DST\n");
	#endif
  set = (uint8_t*) reserve_words(MEM_SET_SIZE_W);

  if (! set )
  {
    return TEST_ERROR;
  }
  ptra = &set[0];
  ptrb = &set[8];

  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++) {
    set[i] = i;
  }
	#ifdef VERBOSE
  print_memory(set, MEM_SET_SIZE_B);
#endif  
	my_memmove(ptra, ptrb, TEST_MEMMOVE_LENGTH);
  
#ifdef VERBOSE
print_memory(set, MEM_SET_SIZE_B);
#endif
  for (i = 0; i < TEST_MEMMOVE_LENGTH; i++)
  {
    if (set[i + 8] != i)
    {
      ret = TEST_ERROR;
    }
  }

  free_words( (uint32_t*)set );
  return ret;
}

int8_t test_memmove3() {
  uint8_t i;
  int8_t ret = TEST_NO_ERROR;
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;
#ifdef DEBUG
  printf("test_memove3() - OVERLAP END OF DEST BEGINNING OF SRC\n");
#endif
  set = (uint8_t*)reserve_words( MEM_SET_SIZE_W);

  if (! set ) 
  {
    return TEST_ERROR;
  }
  ptra = &set[8];
  ptrb = &set[0];

  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++)
  {
    set[i] = i;
  }
#ifdef VERBOSE
  print_memory(set, MEM_SET_SIZE_B);
#endif
  my_memmove(ptra, ptrb, TEST_MEMMOVE_LENGTH);
#ifdef VERBOSE
  print_memory(set, MEM_SET_SIZE_B);
#endif
  for (i = 0; i < TEST_MEMMOVE_LENGTH; i++)
  {
    if (set[i] != (i + 8))
    {
      ret = TEST_ERROR;
    }
  }


  free_words( (uint32_t*)set );
  return ret;

}

int8_t test_memcpy() {
  uint8_t i;
  int8_t ret = TEST_NO_ERROR;
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;
#ifdef DEBUG
  printf("test_memcpy()\n");
#endif
  set = (uint8_t*) reserve_words(MEM_SET_SIZE_W);

  if (! set ) 
  {
    return TEST_ERROR;
  }
  ptra = &set[0];
  ptrb = &set[16];

  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++) {
    set[i] = i;
  }
#ifdef VERBOSE
  print_memory(set, MEM_SET_SIZE_B);
#endif
  my_memcpy(ptra, ptrb, TEST_MEMMOVE_LENGTH);
#ifdef VERBOSE
  print_memory(set, MEM_SET_SIZE_B);
#endif
  for (i = 0; i < TEST_MEMMOVE_LENGTH; i++)
  {
    if (set[i+16] != i)
    {
      ret = TEST_ERROR;
    }
  }

  free_words( (uint32_t*)set );
  return ret;
}

int8_t test_memset() 
{
  uint8_t i;
  uint8_t ret = TEST_NO_ERROR;
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;
#ifdef DEBUG
  printf("test_memset()\n");
#endif
  set = (uint8_t*)reserve_words(MEM_SET_SIZE_W);
  if (! set )
  {
    return TEST_ERROR;
  }
  ptra = &set[0];
  ptrb = &set[16];

  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++) 
  {
    set[i] = i;
  }
#ifdef VERBOSE
  print_memory(set, MEM_SET_SIZE_B);
#endif  
my_memset(ptra, MEM_SET_SIZE_B, 0xFF);
#ifdef VERBOSE  
print_memory(set, MEM_SET_SIZE_B);
#endif  
my_memzero(ptrb, MEM_ZERO_LENGTH);
#ifdef VERBOSE  
print_memory(set, MEM_SET_SIZE_B);
 #endif
  /* Validate Set & Zero Functionality */
  for (i = 0; i < MEM_ZERO_LENGTH; i++)
  {
    if (set[i] != 0xFF)
    {
      ret = TEST_ERROR;
    }
    if (set[16 + i] != 0)
    {
      ret = TEST_ERROR;
    }
  }
  
  free_words( (uint32_t*)set );
  return ret;
}

int8_t test_reverse()
{
  uint8_t i;
  int8_t ret = TEST_NO_ERROR;
  uint8_t * copy;
  uint8_t set[MEM_SET_SIZE_B] = {0x3F, 0x73, 0x72, 0x33, 0x54, 0x43, 0x72, 0x26,
                                 0x48, 0x63, 0x20, 0x66, 0x6F, 0x00, 0x20, 0x33,
                                 0x72, 0x75, 0x74, 0x78, 0x21, 0x4D, 0x20, 0x40,
                                 0x20, 0x24, 0x7C, 0x20, 0x24, 0x69, 0x68, 0x54
                               };
#ifdef DEBUG
  printf("test_reverse()\n");
#endif
  copy = (uint8_t*)reserve_words(MEM_SET_SIZE_W);
  if (! copy )
  {
    return TEST_ERROR;
  }
  
  my_memcpy(set, copy, MEM_SET_SIZE_B);
#ifdef VERBOSE
  print_memory(set, MEM_SET_SIZE_B);
#endif
  my_reverse(set, MEM_SET_SIZE_B);
#ifdef VERBOSE  
print_memory(set, MEM_SET_SIZE_B);
#endif
  for (i = 0; i < MEM_SET_SIZE_B; i++)
  {
    if (set[i] != copy[MEM_SET_SIZE_B - i - 1])
    {
      ret = TEST_ERROR;
    }
  }

  free_words( (uint32_t*)copy );
  return ret;
}

void project1(void) 
{
  uint8_t i;
  int8_t failed = 0;
  int8_t results[TESTCOUNT];

  results[0] = test_data1();
  results[1] = test_data2();
  results[2] = test_memmove1();
  results[3] = test_memmove2();
  results[4] = test_memmove3();
  results[5] = test_memcpy();
  results[6] = test_memset();
  results[7] = test_reverse();
  for ( i = 0; i < TESTCOUNT; i++) 

  {
#ifdef DEBUG
printf("%d \t ", results[i]);
#endif
}


  for ( i = 0; i < TESTCOUNT; i++) 
  {
    failed += results[i];
  }
#ifdef DEBUG
  printf("--------------------------------\n");
  printf("Test Results:\n");
  printf("  PASSED: %d / %d\n", (TESTCOUNT - failed), TESTCOUNT);
  printf("  FAILED: %d / %d\n", failed, TESTCOUNT);
  printf("--------------------------------\n");
#endif
}
