################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LM73.cpp \
../src/MARMEX_OB_oled.cpp \
../src/TextLCD.cpp \
../src/Tone.cpp 

OBJS += \
./src/LM73.o \
./src/MARMEX_OB_oled.o \
./src/TextLCD.o \
./src/Tone.o 

CPP_DEPS += \
./src/LM73.d \
./src/MARMEX_OB_oled.d \
./src/TextLCD.d \
./src/Tone.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -DDEBUG -D__CODE_RED -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LPC11xx/inc" -I"/Users/take/proj/LBED/lbed/LBED_USERLIB/inc" -I"/Users/take/proj/LBED/lbed/LBED_LPC11xx/inc" -I"/Users/take/proj/LBED/lbed/LBED_LPC11xx/src/Common/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


