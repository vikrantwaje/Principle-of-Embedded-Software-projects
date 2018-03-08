#include sources.mk where flags are defined
-include sources.mk

#-----------------------------------------------------------------------------------------
#if platform is FRDM KL25Z board, choose the flags and compiler
ifeq ($(PLATFORM),KL25Z)
	CC=arm-none-eabi-gcc
	INCLUDE=$(HOST_LIB) $(CMSIS_LIB) $(KL25Z_LIB)
	SOURCES_C=$(SOURCES_KL25Z)
	C_FLAGS=$(COMMONFLAGS) $(KL25Z_FLAGS) $(KL25Z_LDFLAGS)
	OBJS:= $(SOURCES_KL25Z:.c=.o) $(SOURCES_KL25Z_S:.S=.o)
endif
#------------------------------------------------------------------------------------------

CFLAGS=$(C_FLAGS)

$(LIB) : $(LIB_OBJS)
	$(AR) $(ARFLAGS) $@ $^

CFLAG_TEST = $(COMMONFLAGS) -I$(CMOCKA_INCLUDE_DIR)

#------------------------------------------------------------------------------------------
#For generating only dependency files
DEPS_C:=$(SOURCES_C:.c=.d)
#-------------------------------------------------------------------------------------------

$(TEST_QUADRATIC_EXE) : $(TEST_QUADRATIC_SRCS) $(LIB)
	$(CC) $(CFLAG_TEST) -o $@ $^ $(CMOCKA_LIBRARY) -lm

#--------------------------------------------------------------------------------------------
#for generating pre-processing directive files
%.i:%.c
	-@echo 'GENERATING PRE-PROCESSING FILES - *.i' 
	$(CC) $(CFLAGS) $(INCLUDE) -E $< -o $@
	-@echo ' '
	
#for generating assembly files
%.asm:%.c
	-@echo 'GENERATING ASSEMBLY FILES *-@echo 'GENERATING PRE-PROCESSING FILES.ASM'
	$(CC) $(CFLAGS) $(INCLUDE) -S $< -o $@
	-@echo ' '

#for generating objects from .s files
%.o:%.S
	-@echo 'Generating .o file from .S file'
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

#for generating objects from .c files
%.o:%.c 
	-@echo 'GENERATING OBJECT FILES *.O'
	$(CC) $(CFLAG) $(INCLUDE) $(CMOCKA_INCLUDE_DIR) -c $< -o $@
	-@echo ' '

#for generating dependency files
%.d:%.c
	-@echo 'GENERATING DEPENDENCY FILES *.D'
	$(CC) $(CFLAGS) $(INCLUDE) -M $< -o $@
	-@echo ' '

#for generating dependency files from .S files
%.d:%.S
	-@echo 'GENERATING DEPENDENCY FILES *.D'
	$(CC) $(CFLAGS) $(INCLUDE) -M $< -o $@
	-@echo ' '

#---------------------------------------------------------------------------------------------

#This command compiles all the C files
.PHONY: COMPILE_ALL
COMPILE_ALL:
	-@echo 'COMPILING ALL .C AND .S FILES'
	$(OBJS)
	-@echo ' '

#this command creates an executable
.PHONY: build
build:  $(OBJS) $(DEPS_C)
	-@echo 'BUILDING'
	$(CC) $(CFLAGS) $(INCLUDE) -Xlinker -Map=project2.map -o project2.elf $(OBJS)
	-@echo ' '

#this command is for unit testing with cmocka
.PHONY: test
test : $(TEST_QUADRATIC_EXE)
	./$(TEST_QUADRATIC_EXE)
#-----------------------------------------------------------------------------------------------

#this command removes all the files created by the build and test process
.PHONY : clean
clean:
	-@echo 'REMOVING ALL FILES CREATED BY BUILD PROCESS'
	rm -rf *~ *.o *.d *.i *.asm *.elf *.map $(TEST_QUADRATIC_EXE) *.dSYM/
	-@echo ' '

#this command gives the size of the executable created
.PHONY: size
size:
	size --format=Berkeley project2.elf
