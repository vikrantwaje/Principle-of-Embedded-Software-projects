-include sources.mk
# Selcting Beaglebone as platform
ifeq ($(PLATFORM),BBB)
	CC=arm-linux-gnueabihf-gcc
	INCLUDE= $(HOST_LIB) $(CMSIS_LIB) 
	SOURCES_C=$(SOURCES_HOST)
	CFLAGS=$(COMMONFLAGS) $(BBB_FLAGS)
	OBJS:= $(SOURCES_C:.c=.o)
else
#selecting kl25z as platform
ifeq ($(PLATFORM),KL25Z)
	CC=arm-none-eabi-gcc
	INCLUDE=$(HOST_LIB) $(CMSIS_LIB) $(KL25Z_LIB)
	SOURCES_C=$(SOURCES_KL25Z)
	CFLAGS=$(COMMONFLAGS) $(KL25Z_FLAGS) $(KL25Z_LDFLAGS)
	OBJS:= $(SOURCES_KL25Z:.c=.o) $(SOURCES_KL25Z_S:.S=.o)
else
#Selecting Host as platform 
ifeq ($(PLATFORM),HOST)	
	CC=gcc
	INCLUDE=$(HOST_LIB)
	SOURCES_C=$(SOURCES_HOST)
	CFLAGS=$(COMMONFLAGS)
	OBJS:= $(SOURCES_C:.c=.o)
endif
endif
endif
# Generating dependencies
DEPS_C:=$(SOURCES_C:.c=.d)

#Generating preprocessor files from source file
%.i:%.c
	-@echo 'GENERATING PRE-PROCESSING FILES - *.i' 
	$(CC) $(CFLAGS) $(INCLUDE) -E $< -o $@
	-@echo ' '
	
#Generating assembly files from source file
%.asm:%.c
	-@echo 'GENERATING ASSEMBLY FILES *-@echo 'GENERATING PRE-PROCESSING FILES.ASM'
	$(CC) $(CFLAGS) $(INCLUDE) -S $< -o $@
	-@echo ' '
	
#Generating output files from startup file
%.o:%.S
	-@echo 'Generating .o file from .S file'
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	
#Generating output files from source file
%.o:%.c 
	-@echo 'GENERATING OBJECT FILES *.O'
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	-@echo ' '
	
#Generating dependency files from source file
%.d:%.c
	-@echo 'GENERATING DEPENDENCY FILES *.D'
	$(CC) $(CFLAGS) $(INCLUDE) -M $< -o $@
	-@echo ' '
	
#Generating dependency files from startup file
%.d:%.S
	-@echo 'GENERATING DEPENDENCY FILES *.D'
	$(CC) $(CFLAGS) $(INCLUDE) -M $< -o $@
	-@echo ' '
	
#PHONY TARGET to build and compile all files
COMPILE_ALL:
	-@echo 'COMPILING ALL .C AND .S FILES'
	$(OBJS)
	-@echo ' '
	
#PHONY target to build target
build: $(OBJS) $(DEPS_C)
	-@echo 'BUILDING'
	$(CC) $(CFLAGS) $(INCLUDE) -Xlinker -Map=project1.map -o project1.elf $(OBJS)
	-@echo ' '
	
#PHONY target to clean target
clean:
	-@echo 'REMOVING ALL FILES CREATED BY BUILD PROCESS'
	rm -rf *.elf *.o *.asm *.d *.i *.map
	-@echo ' '
size:
		size --format=SysV   project3.elf

