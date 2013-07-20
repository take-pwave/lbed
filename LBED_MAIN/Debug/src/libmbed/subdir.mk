################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/libmbed/BusOut.cpp \
../src/libmbed/DigitalOut.cpp \
../src/libmbed/I2C.cpp \
../src/libmbed/Print.cpp \
../src/libmbed/PwmOut.cpp \
../src/libmbed/SPI.cpp \
../src/libmbed/Serial.cpp \
../src/libmbed/pure_virtual.cpp 

C_SRCS += \
../src/libmbed/wait_api.c 

OBJS += \
./src/libmbed/BusOut.o \
./src/libmbed/DigitalOut.o \
./src/libmbed/I2C.o \
./src/libmbed/Print.o \
./src/libmbed/PwmOut.o \
./src/libmbed/SPI.o \
./src/libmbed/Serial.o \
./src/libmbed/pure_virtual.o \
./src/libmbed/wait_api.o 

C_DEPS += \
./src/libmbed/wait_api.d 

CPP_DEPS += \
./src/libmbed/BusOut.d \
./src/libmbed/DigitalOut.d \
./src/libmbed/I2C.d \
./src/libmbed/Print.d \
./src/libmbed/PwmOut.d \
./src/libmbed/SPI.d \
./src/libmbed/Serial.d \
./src/libmbed/pure_virtual.d 


# Each subdirectory must supply rules for building sources it contributes
src/libmbed/%.o: ../src/libmbed/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -D__USE_CMSIS=CMSISv2p00_LPC11xx -DDEBUG -I"/Users/take/Documents/LPCXpresso_4.2.4/workspace/CMSISv2p00_LPC11xx/inc" -I"/Users/take/Documents/LPCXpresso_4.2.4/workspace/LBED_LPC11xx/inc" -I"/Users/take/Documents/LPCXpresso_4.2.4/workspace/LBED_LPC11xx/src/Common/inc" -I"/Users/take/Documents/LPCXpresso_4.2.4/workspace/cpp_test_tmp/src/Common/inc" -I"/Users/take/Documents/LPCXpresso_4.2.4/workspace/cpp_test_tmp/inc" -I"/Users/take/Documents/LPCXpresso_4.2.4/workspace/LBED_USERLIB/inc" -O1 -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/libmbed/%.o: ../src/libmbed/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DDEBUG -I"/Users/take/Documents/LPCXpresso_4.2.4/workspace/LBED_LPC11xx/src/Common/inc" -I"/Users/take/Documents/LPCXpresso_4.2.4/workspace/LBED_LPC11xx/inc" -I"/Users/take/Documents/LPCXpresso_4.2.4/workspace/CMSISv2p00_LPC11xx/inc" -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


