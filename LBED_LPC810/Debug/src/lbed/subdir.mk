################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/lbed/DigitalIn.cpp \
../src/lbed/DigitalOut.cpp \
../src/lbed/I2C.cpp \
../src/lbed/Print.cpp \
../src/lbed/pure_virtual.cpp 

C_SRCS += \
../src/lbed/I2C_SwitchMatrix.c \
../src/lbed/lbed_setup.c \
../src/lbed/wait_api.c 

OBJS += \
./src/lbed/DigitalIn.o \
./src/lbed/DigitalOut.o \
./src/lbed/I2C.o \
./src/lbed/I2C_SwitchMatrix.o \
./src/lbed/Print.o \
./src/lbed/lbed_setup.o \
./src/lbed/pure_virtual.o \
./src/lbed/wait_api.o 

C_DEPS += \
./src/lbed/I2C_SwitchMatrix.d \
./src/lbed/lbed_setup.d \
./src/lbed/wait_api.d 

CPP_DEPS += \
./src/lbed/DigitalIn.d \
./src/lbed/DigitalOut.d \
./src/lbed/I2C.d \
./src/lbed/Print.d \
./src/lbed/pure_virtual.d 


# Each subdirectory must supply rules for building sources it contributes
src/lbed/%.o: ../src/lbed/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_CMSIS=CMSIS_CORE_LPC8xx -DCPP_USE_HEAP -D__LPC8XX__ -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/LBED_LPC810/inc" -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/LBED_LPC810/src/common" -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/LBED_LPC810/src/userlib" -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/CMSIS_CORE_LPC8xx/inc" -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/lpc800_driver_lib/inc" -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lbed/%.o: ../src/lbed/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_CMSIS=CMSIS_CORE_LPC8xx -DCPP_USE_HEAP -D__LPC8XX__ -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/LBED_LPC810/inc" -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/LBED_LPC810/src/common" -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/LBED_LPC810/src/userlib" -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/CMSIS_CORE_LPC8xx/inc" -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/lpc800_driver_lib/inc" -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


