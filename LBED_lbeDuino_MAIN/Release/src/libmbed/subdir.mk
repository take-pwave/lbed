################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/libmbed/BusOut.cpp \
../src/libmbed/DigitalOut.cpp \
../src/libmbed/Print.cpp \
../src/libmbed/TextLCD.cpp 

C_SRCS += \
../src/libmbed/wait_api.c 

OBJS += \
./src/libmbed/BusOut.o \
./src/libmbed/DigitalOut.o \
./src/libmbed/Print.o \
./src/libmbed/TextLCD.o \
./src/libmbed/wait_api.o 

C_DEPS += \
./src/libmbed/wait_api.d 

CPP_DEPS += \
./src/libmbed/BusOut.d \
./src/libmbed/DigitalOut.d \
./src/libmbed/Print.d \
./src/libmbed/TextLCD.d 


# Each subdirectory must supply rules for building sources it contributes
src/libmbed/%.o: ../src/libmbed/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -DNDEBUG -D__CODE_RED -I"/Users/take/Documents/LPCXpresso_4.2.4/workspace/CMSISv2p00_LPC11xx/inc" -I"/Users/take/Documents/LPCXpresso_4.2.4/workspace/cpp_test/src/libmbed" -Os -Os -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/libmbed/%.o: ../src/libmbed/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DNDEBUG -D__CODE_RED -I"/Users/take/Documents/LPCXpresso_4.2.4/workspace/CMSISv2p00_LPC11xx/inc" -I"/Users/take/Documents/LPCXpresso_4.2.4/workspace/cpp_test/src/libmbed" -Os -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


