################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/cr_cpp_config.cpp \
../src/cr_startup_lpc11.cpp \
../src/main.cpp 

OBJS += \
./src/cr_cpp_config.o \
./src/cr_startup_lpc11.o \
./src/main.o 

CPP_DEPS += \
./src/cr_cpp_config.d \
./src/cr_startup_lpc11.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -DNDEBUG -D__CODE_RED -I"/Users/take/Documents/LPCXpresso_4.2.4/workspace/CMSISv2p00_LPC11xx/inc" -I"/Users/take/Documents/LPCXpresso_4.2.4/workspace/cpp_test/src/libmbed" -Os -Os -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


