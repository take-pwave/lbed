################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/libmbed/AnalogIn.cpp \
../src/libmbed/BusOut.cpp \
../src/libmbed/DigitalIn.cpp \
../src/libmbed/DigitalOut.cpp \
../src/libmbed/I2C.cpp \
../src/libmbed/Print.cpp \
../src/libmbed/PwmOut.cpp \
../src/libmbed/SPI.cpp \
../src/libmbed/Serial.cpp \
../src/libmbed/SerialCDC.cpp \
../src/libmbed/pure_virtual.cpp 

C_SRCS += \
../src/libmbed/wait_api.c 

OBJS += \
./src/libmbed/AnalogIn.o \
./src/libmbed/BusOut.o \
./src/libmbed/DigitalIn.o \
./src/libmbed/DigitalOut.o \
./src/libmbed/I2C.o \
./src/libmbed/Print.o \
./src/libmbed/PwmOut.o \
./src/libmbed/SPI.o \
./src/libmbed/Serial.o \
./src/libmbed/SerialCDC.o \
./src/libmbed/pure_virtual.o \
./src/libmbed/wait_api.o 

C_DEPS += \
./src/libmbed/wait_api.d 

CPP_DEPS += \
./src/libmbed/AnalogIn.d \
./src/libmbed/BusOut.d \
./src/libmbed/DigitalIn.d \
./src/libmbed/DigitalOut.d \
./src/libmbed/I2C.d \
./src/libmbed/Print.d \
./src/libmbed/PwmOut.d \
./src/libmbed/SPI.d \
./src/libmbed/Serial.d \
./src/libmbed/SerialCDC.d \
./src/libmbed/pure_virtual.d 


# Each subdirectory must supply rules for building sources it contributes
src/libmbed/%.o: ../src/libmbed/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__USE_CMSIS=CMSISv2p00_LPC13xx -D__NEWLIB__ -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LPC13xx/inc" -I"/Users/take/proj/LBED/lbed/LBED_LPC13xx/src/Common/inc" -I"/Users/take/proj/LBED/lbed/LBED_LPC13xx/inc" -O1 -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/libmbed/SerialCDC.o: ../src/libmbed/SerialCDC.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__USE_CMSIS=CMSISv2p00_LPC13xx -D__NEWLIB__ -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LPC13xx/inc" -I"/Users/take/proj/LBED/lbed/LBED_LPC13xx/src/Common/inc" -I"/Users/take/proj/LBED/lbed/LBED_LPC13xx/inc" -O0 -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/libmbed/SerialCDC.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/libmbed/%.o: ../src/libmbed/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC13xx -D__NEWLIB__ -DDEBUG -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LPC13xx/inc" -I"/Users/take/proj/LBED/lbed/LBED_LPC13xx/src/Common/inc" -I"/Users/take/proj/LBED/lbed/LBED_LPC13xx/inc" -O0 -Os -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


