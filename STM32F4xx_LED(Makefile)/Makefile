BIN = STM32F4xx_LED.bin
ELF = STM32F4xx_LED.elf

FLASH_LD = ./User/STM32F417IG_FLASH.ld

SRC += ./User/*.c
SRC += ./Peripheral_BSP/*.c
SRC += ./STM32F4xx_DSP_StdPeriph_Lib_V1.8.0/STM32F4xx_StdPeriph_Driver/src/*.c
SRC += ./STM32F4xx_DSP_StdPeriph_Lib_V1.8.0/CMSIS/Device/ST/STM32F4xx/Source/Templates/*.c

STARTUP = ./STM32F4xx_DSP_StdPeriph_Lib_V1.8.0/CMSIS/Device/ST/STM32F4xx/Source/Templates/TrueSTUDIO/*.s

INC += -I./STM32F4xx_DSP_StdPeriph_Lib_V1.8.0/STM32F4xx_StdPeriph_Driver/inc
INC += -I./STM32F4xx_DSP_StdPeriph_Lib_V1.8.0/CMSIS/Device/ST/STM32F4xx/Include
INC += -I./STM32F4xx_DSP_StdPeriph_Lib_V1.8.0/CMSIS/Include
INC += -I./Peripheral_BSP
INC += -I./User

DEF += -DSTM32F40_41xxx 
DEF += -DUSE_STDPERIPH_DRIVER


CFLAGS += -mcpu=cortex-m4
CFLAGS += -Wall
CFLAGS += -mfloat-abi=hard
CFLAGS += -mthumb
CFLAGS += -mfpu=fpv4-sp-d16

SRC_RAW = $(wildcard $(SRC))
OBJ = $(SRC_RAW:%.c=%.o)

STARTUP_RAW = $(wildcard $(STARTUP))
STARTUP_OBJ = $(STARTUP_RAW:%.s=%.o)


all: $(OBJ) $(STARTUP_OBJ)
	@echo $(CFLAGS)
	@echo $(STARTUP_OBJ)
	@echo $(FLASH_LD)
	@echo $(ELF)
	@echo $(BIN)

#$(ELF):$(OBJ)
#	arm-none-eabi-gcc -o $@ $(CFLAGS) $^ -T$(FLASH_LD)

%.o:%.s
	arm-none-eabi-gcc -c $(CFLAGS) $< -o $@
	-mv $@ ./output

%.o:%.c
	arm-none-eabi-gcc -c $(CFLAGS) $(DEF) $(INC) $< -o $@
	-mv $@ ./output

.PHONY : clean
clean :
	-rm ./output/*.o
