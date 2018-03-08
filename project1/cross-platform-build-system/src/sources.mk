COMMONFLAGS=-Wall \
 -g \
 -std=c99 \
 -O0 \
 -DPROJECT1 \
 -Werror\

CMSIS_LIB=-I../include/CMSIS
HOST_LIB=-I../include/HOST
KL25Z_LIB=-I../include/KL25Z

KL25Z_CPU=cortex-m0plus
KL25Z_LDFLAGS=-T../platform/MKL25Z128xxx4_flash.ld

DEBUG_FLAG=-DDEBUG
VERBOSE_FLAG=-DVERBOSE

BBB_FLAGS=-mcpu=cortex-a8 \
 -mthumb \
 -mfloat-abi=hard 

KL25Z_FLAGS=-mcpu=$(KL25Z_CPU) \
 -mthumb \
 -march=armv6-m \
 -mfloat-abi=soft \
 -mfpu=fpv4-sp-d16 \
 -specs=nosys.specs 

SOURCES_HOST=./conversion.c \
./debug.c \
./memory.c \
./main_program.c \
./project1.c

SOURCES_KL25Z= $(SOURCES_HOST) \
 ./system_MKL25Z4.c

SOURCES_KL25ZI_S=./startup_MKL25Z4.S
