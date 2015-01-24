################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Common/src/_gpio.c \
../src/Common/src/_i2c.c \
../src/Common/src/_ssp.c \
../src/Common/src/_timer16.c \
../src/Common/src/_timer32.c 

OBJS += \
./src/Common/src/_gpio.o \
./src/Common/src/_i2c.o \
./src/Common/src/_ssp.o \
./src/Common/src/_timer16.o \
./src/Common/src/_timer32.o 

C_DEPS += \
./src/Common/src/_gpio.d \
./src/Common/src/_i2c.d \
./src/Common/src/_ssp.d \
./src/Common/src/_timer16.d \
./src/Common/src/_timer32.d 


# Each subdirectory must supply rules for building sources it contributes
src/Common/src/%.o: ../src/Common/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC11xx -D__NEWLIB__ -DDEBUG -I../inc -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino/src/Common/inc" -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LPC11xx/inc" -O0 -Os -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


