################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/adc.c \
../src/flash.c \
../src/general_functions.c \
../src/gpio.c \
../src/i2c.c \
../src/rtc.c \
../src/sensors.c \
../src/spi.c \
../src/sx1276.c \
../src/tdr-board-v4.c \
../src/tdr.c \
../src/uart.c \
../src/xint.c 

SRC_OBJS += \
./src/adc.o \
./src/flash.o \
./src/general_functions.o \
./src/gpio.o \
./src/i2c.o \
./src/rtc.o \
./src/sensors.o \
./src/spi.o \
./src/sx1276.o \
./src/tdr-board-v4.o \
./src/tdr.o \
./src/uart.o \
./src/xint.o 

C_DEPS += \
./src/adc.d \
./src/flash.d \
./src/general_functions.d \
./src/gpio.d \
./src/i2c.d \
./src/rtc.d \
./src/sensors.d \
./src/spi.d \
./src/sx1276.d \
./src/tdr-board-v4.d \
./src/tdr.d \
./src/uart.d \
./src/xint.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0x1 @includes-6300ced82c7ec706d04c78f3bc4bcca9.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


