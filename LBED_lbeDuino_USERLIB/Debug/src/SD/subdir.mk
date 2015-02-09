################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SD/File.cpp \
../src/SD/SD.cpp 

OBJS += \
./src/SD/File.o \
./src/SD/SD.o 

CPP_DEPS += \
./src/SD/File.d \
./src/SD/SD.d 


# Each subdirectory must supply rules for building sources it contributes
src/SD/File.o: ../src/SD/File.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -DDEBUG -D__CODE_RED -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LPC11xx/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino_USERLIB/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino/src/Common/inc" -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/SD/File.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/SD/SD.o: ../src/SD/SD.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -DDEBUG -D__CODE_RED -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LPC11xx/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino_USERLIB/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino/src/Common/inc" -O1 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/SD/SD.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


