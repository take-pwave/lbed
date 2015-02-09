################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SDCard_logger.cpp 

OBJS += \
./src/SDCard_logger.o 

CPP_DEPS += \
./src/SDCard_logger.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -D__USE_CMSIS=CMSISv2p00_LPC11xx -DDEBUG -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LPC11xx/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino_USERLIB/src/SD" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino/src/Common/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino_MAIN/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino_USERLIB/inc" -Os -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


