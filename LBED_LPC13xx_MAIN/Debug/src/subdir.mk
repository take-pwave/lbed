################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/TestLED.cpp \
../src/cr_cpp_config.cpp \
../src/cr_startup_lpc13.cpp 

OBJS += \
./src/TestLED.o \
./src/cr_cpp_config.o \
./src/cr_startup_lpc13.o 

CPP_DEPS += \
./src/TestLED.d \
./src/cr_cpp_config.d \
./src/cr_startup_lpc13.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -D__USE_CMSIS=CMSISv2p00_LPC13xx -DDEBUG -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LPC13xx/inc" -I"/Users/take/proj/LBED/lbed/LBED_USERLIB/inc" -I"/Users/take/proj/LBED/lbed/LBED_LPC13xx/src/Common/inc" -I"/Users/take/proj/LBED/lbed/LBED_LPC13xx/inc" -O1 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


