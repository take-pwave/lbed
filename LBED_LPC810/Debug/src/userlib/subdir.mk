################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/userlib/AQCM0802.cpp \
../src/userlib/RTC8664.cpp 

OBJS += \
./src/userlib/AQCM0802.o \
./src/userlib/RTC8664.o 

CPP_DEPS += \
./src/userlib/AQCM0802.d \
./src/userlib/RTC8664.d 


# Each subdirectory must supply rules for building sources it contributes
src/userlib/%.o: ../src/userlib/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_CMSIS=CMSIS_CORE_LPC8xx -DCPP_USE_HEAP -D__LPC8XX__ -I"/Users/take/proj/LBED/lbed/LBED_LPC810/inc" -I"/Users/take/proj/LBED/lbed/LBED_LPC810/src/common" -I"/Users/take/proj/LBED/lbed/LBED_LPC810/src/userlib" -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/CMSIS_CORE_LPC8xx/inc" -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/lpc800_driver_lib/inc" -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


