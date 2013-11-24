################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/I2cLCD.cpp \
../src/LM73.cpp \
../src/MARMEX_OB_oled.cpp \
../src/TextLCD.cpp \
../src/Tone.cpp 

OBJS += \
./src/I2cLCD.o \
./src/LM73.o \
./src/MARMEX_OB_oled.o \
./src/TextLCD.o \
./src/Tone.o 

CPP_DEPS += \
./src/I2cLCD.d \
./src/LM73.d \
./src/MARMEX_OB_oled.d \
./src/TextLCD.d \
./src/Tone.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -DCPP_USE_HEAP -DCORE_M4 -DDEBUG -D__CODE_RED -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Include" -I"/Users/take/proj/LBED/lbed/LBED_LM4F120_USERLIB/inc" -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Device/TI/LM4F/Include" -I"/Users/take/proj/LBED/lbed/LBED_LM4F120/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


