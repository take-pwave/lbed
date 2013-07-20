################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../not_used/LM73.cpp \
../not_used/TextLCD.cpp \
../not_used/main.cpp 

OBJS += \
./not_used/LM73.o \
./not_used/TextLCD.o \
./not_used/main.o 

CPP_DEPS += \
./not_used/LM73.d \
./not_used/TextLCD.d \
./not_used/main.d 


# Each subdirectory must supply rules for building sources it contributes
not_used/%.o: ../not_used/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -D__USE_CMSIS=CMSISv2p00_LPC11xx -DDEBUG -I"/Users/take/Documents/LPCXpresso_4.2.4/workspace/cpp_test/src/libmbed" -I"/Users/take/Documents/LPCXpresso_4.2.4/workspace/cpp_test/src/Common/inc" -I"/Users/take/Documents/LPCXpresso_4.2.4/workspace/CMSISv2p00_LPC11xx/inc" -Os -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


