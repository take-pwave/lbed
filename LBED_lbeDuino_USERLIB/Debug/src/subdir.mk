################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AQCM0802.cpp \
../src/LM73.cpp \
../src/LM75B.cpp \
../src/MARMEX_OB_oled.cpp \
../src/TextLCD.cpp \
../src/Tone.cpp 

OBJS += \
./src/AQCM0802.o \
./src/LM73.o \
./src/LM75B.o \
./src/MARMEX_OB_oled.o \
./src/TextLCD.o \
./src/Tone.o 

CPP_DEPS += \
./src/AQCM0802.d \
./src/LM73.d \
./src/LM75B.d \
./src/MARMEX_OB_oled.d \
./src/TextLCD.d \
./src/Tone.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -DDEBUG -D__CODE_RED -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LPC11xx/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino_USERLIB/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino/src/Common/inc" -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

