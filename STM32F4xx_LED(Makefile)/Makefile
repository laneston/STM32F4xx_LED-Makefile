BIN = ./output/STM32F4xx_LED.bin
ELF = ./output/STM32F4xx_LED.elf

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
CFLAGS += -mfloat-abi=hard
CFLAGS += -mthumb
CFLAGS += -mfpu=fpv4-sp-d16
CFLAGS += -Os
CFLAGS += -Wall
CFLAGS += -ffunction-sections
CFLAGS += -fdata-sections

LFLAGS += -mcpu=cortex-m4
LFLAGS += -mfloat-abi=hard
LFLAGS += -mthumb
LFLAGS += -mfpu=fpv4-sp-d16
LFLAGS += -Wl,--gc-sections

SRC_RAW = $(wildcard $(SRC))
OBJ = $(SRC_RAW:%.c=%.o)

STARTUP_RAW = $(wildcard $(STARTUP))
STARTUP_OBJ = $(STARTUP_RAW:%.s=%.o)

OUTPUT_OBJ = ./output/*.o

all:$(OBJ) $(STARTUP_OBJ) $(ELF) $(BIN)
	@echo $(ELF)
	@echo $(BIN)
	@echo

$(BIN):$(ELF)
	arm-none-eabi-objcopy -O binary -S $< $@
	@echo

$(ELF):
	arm-none-eabi-gcc -o $@ $(LFLAGS) $(OUTPUT_OBJ) -T$(FLASH_LD)
	@echo

%.o:%.s
	arm-none-eabi-gcc -c $(CFLAGS) $< -o $@
	-mv $@ ./output
	@echo

%.o:%.c
	arm-none-eabi-gcc -c $(CFLAGS) $(DEF) $(INC) $< -o $@
	-mv $@ ./output
	@echo

.PHONY: clean
clean :
	-rm ./output/*.o\
	    ./output/*.elf\
		./output/*.bin
