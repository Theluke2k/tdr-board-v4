################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/adc/adi_adc.c \
C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/beep/adi_beep.c \
C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/crc/adi_crc.c \
C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/dma/adi_dma.c \
C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/flash/adi_flash.c \
C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/gpio/adi_gpio.c \
C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/i2c/adi_i2c.c \
C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/pwr/adi_pwr.c \
C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/rtc/adi_rtc.c \
C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/spi/adi_spi.c \
C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/uart/adi_uart.c \
C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/wdt/adi_wdt.c \
C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/xint/adi_xint.c \
C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/common.c \
../RTE/Device/ADuCM4050/startup_ADuCM4050.c \
../RTE/Device/ADuCM4050/system_ADuCM4050.c 

S_UPPER_SRCS += \
../RTE/Device/ADuCM4050/reset_ADuCM4050.S 

SRC_OBJS += \
./RTE/Device/ADuCM4050/adi_adc.o \
./RTE/Device/ADuCM4050/adi_beep.o \
./RTE/Device/ADuCM4050/adi_crc.o \
./RTE/Device/ADuCM4050/adi_dma.o \
./RTE/Device/ADuCM4050/adi_flash.o \
./RTE/Device/ADuCM4050/adi_gpio.o \
./RTE/Device/ADuCM4050/adi_i2c.o \
./RTE/Device/ADuCM4050/adi_pwr.o \
./RTE/Device/ADuCM4050/adi_rtc.o \
./RTE/Device/ADuCM4050/adi_spi.o \
./RTE/Device/ADuCM4050/adi_uart.o \
./RTE/Device/ADuCM4050/adi_wdt.o \
./RTE/Device/ADuCM4050/adi_xint.o \
./RTE/Device/ADuCM4050/common.o \
./RTE/Device/ADuCM4050/reset_ADuCM4050.o \
./RTE/Device/ADuCM4050/startup_ADuCM4050.o \
./RTE/Device/ADuCM4050/system_ADuCM4050.o 

C_DEPS += \
./RTE/Device/ADuCM4050/adi_adc.d \
./RTE/Device/ADuCM4050/adi_beep.d \
./RTE/Device/ADuCM4050/adi_crc.d \
./RTE/Device/ADuCM4050/adi_dma.d \
./RTE/Device/ADuCM4050/adi_flash.d \
./RTE/Device/ADuCM4050/adi_gpio.d \
./RTE/Device/ADuCM4050/adi_i2c.d \
./RTE/Device/ADuCM4050/adi_pwr.d \
./RTE/Device/ADuCM4050/adi_rtc.d \
./RTE/Device/ADuCM4050/adi_spi.d \
./RTE/Device/ADuCM4050/adi_uart.d \
./RTE/Device/ADuCM4050/adi_wdt.d \
./RTE/Device/ADuCM4050/adi_xint.d \
./RTE/Device/ADuCM4050/common.d \
./RTE/Device/ADuCM4050/startup_ADuCM4050.d \
./RTE/Device/ADuCM4050/system_ADuCM4050.d 


# Each subdirectory must supply rules for building sources it contributes
RTE/Device/ADuCM4050/adi_adc.o: C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/adc/adi_adc.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0x1 @includes-6300ced82c7ec706d04c78f3bc4bcca9.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/Device/ADuCM4050/adi_beep.o: C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/beep/adi_beep.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0x1 @includes-6300ced82c7ec706d04c78f3bc4bcca9.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/Device/ADuCM4050/adi_crc.o: C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/crc/adi_crc.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0x1 @includes-6300ced82c7ec706d04c78f3bc4bcca9.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/Device/ADuCM4050/adi_dma.o: C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/dma/adi_dma.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0x1 @includes-6300ced82c7ec706d04c78f3bc4bcca9.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/Device/ADuCM4050/adi_flash.o: C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/flash/adi_flash.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0x1 @includes-6300ced82c7ec706d04c78f3bc4bcca9.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/Device/ADuCM4050/adi_gpio.o: C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/gpio/adi_gpio.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0x1 @includes-6300ced82c7ec706d04c78f3bc4bcca9.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/Device/ADuCM4050/adi_i2c.o: C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/i2c/adi_i2c.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0x1 @includes-6300ced82c7ec706d04c78f3bc4bcca9.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/Device/ADuCM4050/adi_pwr.o: C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/pwr/adi_pwr.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0x1 @includes-6300ced82c7ec706d04c78f3bc4bcca9.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/Device/ADuCM4050/adi_rtc.o: C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/rtc/adi_rtc.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0x1 @includes-6300ced82c7ec706d04c78f3bc4bcca9.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/Device/ADuCM4050/adi_spi.o: C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/spi/adi_spi.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0x1 @includes-6300ced82c7ec706d04c78f3bc4bcca9.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/Device/ADuCM4050/adi_uart.o: C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/uart/adi_uart.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0x1 @includes-6300ced82c7ec706d04c78f3bc4bcca9.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/Device/ADuCM4050/adi_wdt.o: C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/wdt/adi_wdt.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0x1 @includes-6300ced82c7ec706d04c78f3bc4bcca9.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/Device/ADuCM4050/adi_xint.o: C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/drivers/xint/adi_xint.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0x1 @includes-6300ced82c7ec706d04c78f3bc4bcca9.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/Device/ADuCM4050/common.o: C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.10.1/ARM/packs/AnalogDevices/ADuCM4x50_DFP/4.0.0/Source/common.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0x1 @includes-6300ced82c7ec706d04c78f3bc4bcca9.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/Device/ADuCM4050/%.o: ../RTE/Device/ADuCM4050/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -g -gdwarf-2 -DCORE0 -D_DEBUG -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0x1 @includes-6300ced82c7ec706d04c78f3bc4bcca9.txt -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/Device/ADuCM4050/%.o: ../RTE/Device/ADuCM4050/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0x1 @includes-6300ced82c7ec706d04c78f3bc4bcca9.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


