-include sources.mk

ifeq ($(PLATFORM),BBB)
	CC=arm-linux-gnueabihf-gcc
	INCLUDE= $(HOST_LIB) $(CMSIS_LIB) 
	SOURCES_C=$(SOURCES_HOST)
	CPP=$(VERBOSE_FLAG)
	C_FLAGS=$(COMMONFLAGS) $(BBB_FLAGS) #$(VERBOSE_FLAG) #$(DEBUG_FLAG) $(VERBOSE_FLAG)
	OBJS:= $(SOURCES_C:.c=.o)
else
ifeq ($(PLATFORM),KL25Z)
	CC=arm-none-eabi-gcc
	INCLUDE=$(HOST_LIB) $(CMSIS_LIB) $(KL25Z_LIB)
	SOURCES_C=$(SOURCES_KL25Z)
	C_FLAGS=$(COMMONFLAGS) $(KL25Z_FLAGS) $(KL25Z_LDFLAGS)
	OBJS:= $(SOURCES_KL25Z:.c=.o) $(SOURCES_KL25Z_S:.S=.o)
else 
ifeq ($(PLATFORM),HOST)	
	CC=gcc
	INCLUDE=$(HOST_LIB)
	SOURCES_C=$(SOURCES_HOST)
	C_FLAGS=$(COMMONFLAGS)
	OBJS:= $(SOURCES_C:.c=.o)

endif
endif
endif



ifeq ($(COMPILETIME),DEBUG)
	CFLAGS=$(C_FLAGS) $(DEBUG_FLAG)
else
ifeq ($(COMPILETIME),VERBOSE)
	CFLAGS=$(C_FLAGS) $(VERBOSE_FLAG)
else
	CFLAGS=$(C_FLAGS) $(DEBUG_FLAG) $(VERBOSE_FLAG)
endif
endif


DEPS_C:=$(SOURCES_C:.c=.d)


%.i:%.c
	-@echo 'GENERATING PRE-PROCESSING FILES - *.i' 
	$(CC) $(CFLAGS) $(INCLUDE) -E $< -o $@
	-@echo ' '
	
%.asm:%.c
	-@echo 'GENERATING ASSEMBLY FILES *-@echo 'GENERATING PRE-PROCESSING FILES.ASM'
	$(CC) $(CFLAGS) $(INCLUDE) -S $< -o $@
	-@echo ' '

%.o:%.S
	-@echo 'Generating .o file from .S file'
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

%.o:%.c 
	-@echo 'GENERATING OBJECT FILES *.O'
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	-@echo ' '

%.d:%.c
	-@echo 'GENERATING DEPENDENCY FILES *.D'
	$(CC) $(CFLAGS) $(INCLUDE) -M $< -o $@
	-@echo ' '
%.d:%.S
	-@echo 'GENERATING DEPENDENCY FILES *.D'
	$(CC) $(CFLAGS) $(INCLUDE) -M $< -o $@
	-@echo ' '
.PHONY: COMPILE_ALL
COMPILE_ALL:
	-@echo 'COMPILING ALL .C AND .S FILES'
	$(OBJS)
	-@echo ' '
.PHONY: build
build: $(OBJS) $(DEPS_C)
	-@echo 'BUILDING'
	$(CC) $(CFLAGS) $(INCLUDE) -Xlinker -Map=project1.map -o project1.elf $(OBJS)
	-@echo ' '
.PHONY : clean
clean:
	-@echo 'REMOVING ALL FILES CREATED BY BUILD PROCESS'
	rm -rf *.o *.d *.i *.asm project1.elf
	-@echo ' '

.PHONY: size
size:
	size --format=Berkeley project1.elf
