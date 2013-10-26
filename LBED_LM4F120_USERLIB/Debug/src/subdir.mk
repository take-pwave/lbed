################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/TextLCD.cpp 

OBJS += \
./src/TextLCD.o 

CPP_DEPS += \
./src/TextLCD.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -DCPP_USE_HEAP -DCORE_M4 -DDEBUG -D__CODE_RED -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Include" -I"/Users/take/proj/LBED/lbed/LBED_LM4F120_USERLIB/inc" -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Device/TI/LM4F/Include" -I"/Users/take/proj/LBED/lbed/LBED_LM4F120/inc" -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


