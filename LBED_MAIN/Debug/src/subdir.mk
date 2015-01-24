################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/TestLCD.cpp \
../src/cr_cpp_config.cpp \
../src/cr_startup_lpc11.cpp 

OBJS += \
./src/TestLCD.o \
./src/cr_cpp_config.o \
./src/cr_startup_lpc11.o 

CPP_DEPS += \
./src/TestLCD.d \
./src/cr_cpp_config.d \
./src/cr_startup_lpc11.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -D__USE_CMSIS=CMSISv2p00_LPC11xx -DDEBUG -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LPC11xx/inc" -I"/Users/take/proj/LBED/lbed/LBED_LPC11xx/inc" -I"/Users/take/proj/LBED/lbed/LBED_LPC11xx/src/Common/inc" -I"/Users/take/proj/LBED/lbed/LBED_MAIN/inc" -I"/Users/take/proj/LBED/lbed/LBED_USERLIB/inc" -O0 -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


