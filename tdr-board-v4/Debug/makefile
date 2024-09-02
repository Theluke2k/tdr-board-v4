################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := ${ComSpec}

-include ../makefile.init

RM := clean

# All of the sources participating in the build are defined here
-include sources.mk
-include system/pinmux/GeneratedSources/subdir.mk
-include system/subdir.mk
-include src/subdir.mk
-include RTE/Device/ADuCM4050/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
tdr-board-v4 \

OBJS := $(SRC_OBJS)
# Quote makefile variable : OBJS 
OBJS := $(subst \ ,@, $(OBJS))
OBJS := $(foreach var, $(OBJS), "$(subst @, ,$(var))")
# Quote makefile variable : C_DEPS 
C_DEPS := $(subst \ ,@, $(C_DEPS))
C_DEPS := $(foreach var, $(C_DEPS), "$(subst @, ,$(var))")

# All Target
all: tdr-board-v4.hex

# Tool invocations
tdr-board-v4.hex: $(EXECUTABLES) $(SRC_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: CrossCore GCC ARM Embedded Object Copier'
	arm-none-eabi-objcopy -O ihex $(EXECUTABLES) "tdr-board-v4.hex"
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE)  --no-print-directory post-build


PREPROC:
	@echo 'Preprocessing LD script: tdr-board-v4.ld'
	arm-none-eabi-cpp -E -P -DCORE0 -DDEBUG -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0x1 -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/ARM/CMSIS/5.0.1/CMSIS/Include" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/adc" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/beep" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/crc" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/dma" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/flash" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/gpio" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/i2c" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/pwr" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/rtc" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/spi" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/uart" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/wdt" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/xint" -I"C:\Users\lselm\Downloads\PipeSense_AU_SW-main\PipeSense_AU_SW-main\tdr-board-v4_1/RTE" -I"C:\Users\lselm\Downloads\PipeSense_AU_SW-main\PipeSense_AU_SW-main\tdr-board-v4_1/RTE/Device/ADuCM4050" -o  "tdr-board-v4.ld" "C:\Users\lselm\Downloads\PipeSense_AU_SW-main\PipeSense_AU_SW-main\tdr-board-v4_1/RTE/Device/ADuCM4050/ADuCM4050.ld"

tdr-board-v4: $(USER_OBJS) $(SRC_OBJS) PREPROC
	@echo 'Invoking: CrossCore GCC ARM Embedded C Linker'
	arm-none-eabi-gcc -Ttdr-board-v4.ld -DCORE0 -DDEBUG -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0x1 -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/ARM/CMSIS/5.0.1/CMSIS/Include" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/adc" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/beep" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/crc" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/dma" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/flash" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/gpio" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/i2c" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/pwr" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/rtc" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/spi" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/uart" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/wdt" -I"C:/Analog Devices/CrossCore Embedded Studio 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Include/drivers/xint" -I"C:\Users\lselm\Downloads\PipeSense_AU_SW-main\PipeSense_AU_SW-main\tdr-board-v4_1/RTE" -I"C:\Users\lselm\Downloads\PipeSense_AU_SW-main\PipeSense_AU_SW-main\tdr-board-v4_1/RTE/Device/ADuCM4050" -Wl,--gc-sections -mcpu=cortex-m4 -mthumb -specs=nosys.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -o  "tdr-board-v4" @input-file.txt
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(INTEL_HEX_FILE_OUTPUTS)$(EXECUTABLES)$(OBJS)$(C_DEPS) tdr-board-v4.hex
	-@echo ' '

post-build:
	-arm-none-eabi-objcopy -O ihex tdr-board-v4 tdr-board-v4.hex
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
