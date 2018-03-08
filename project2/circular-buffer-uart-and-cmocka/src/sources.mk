#common flags used for all building process
COMMONFLAGS=-Wall \
 -g \
 -std=c99 \
 -O0 \
 -DPROJECT2 \
 -fno-stack-protector \
 -Werror

#flag for cmocka unit tests
THIRD_PARTY_DIR = 3rd-party

#include directories for cmocka
CMOCKA_INCLUDE_DIR = $(THIRD_PARTY_DIR)/build-Debug/include
CMOCKA_LIBRARY = $(THIRD_PARTY_DIR)/build-Debug/lib/libcmocka.a

#C source files for cmocka unit tests
LIB_SRCS = \
./memory.c \
./conversion.c \
./cb.c

LIB_OBJS = $(LIB_SRCS:%.c=%.o)

LIB_HEADERS = $(LIB_SRCS:%.c=%.h)

LIB = libutils.a


TEST_QUADRATIC_SRCS = test.c

TEST_QUADRATIC_OBJS = $(TEST_QUADRATIC_SRCS:%.c=%.o)

TEST_QUADRATIC_EXE = test.out

#library files for different platforms 
CMSIS_LIB=-I../include/CMSIS
HOST_LIB=-I../include/HOST
KL25Z_LIB=-I../include/KL25Z

#Freedom board CPU details
KL25Z_CPU=cortex-m0plus

#linker flag for kl25z
KL25Z_LDFLAGS=-T../platform/MKL25Z128xxx4_flash.ld

#KL25Z board specific details about processor and architecture
KL25Z_FLAGS=-mcpu=$(KL25Z_CPU) \
 -mthumb \
 -march=armv6-m \
 -mfloat-abi=soft \
 -mfpu=fpv4-sp-d16 \
 -specs=nosys.specs 

#C source files for building
SOURCES_HOST=./cb.c \
./uart.c \
./project2.c \
./main.c

#specific source files for KL25Z
SOURCES_KL25Z= $(SOURCES_HOST) \
 ./system_MKL25Z4.c

SOURCES_KL25ZI_S=./startup_MKL25Z4.S
