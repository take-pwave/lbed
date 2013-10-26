################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/libmbed/BusOut.cpp \
../src/libmbed/DigitalIn.cpp \
../src/libmbed/DigitalOut.cpp \
../src/libmbed/Print.cpp \
../src/libmbed/Serial.cpp \
../src/libmbed/cr_cpp_config.cpp \
../src/libmbed/dummy.cpp \
../src/libmbed/pure_virtual.cpp 

C_SRCS += \
../src/libmbed/wait_api.c 

OBJS += \
./src/libmbed/BusOut.o \
./src/libmbed/DigitalIn.o \
./src/libmbed/DigitalOut.o \
./src/libmbed/Print.o \
./src/libmbed/Serial.o \
./src/libmbed/cr_cpp_config.o \
./src/libmbed/dummy.o \
./src/libmbed/pure_virtual.o \
./src/libmbed/wait_api.o 

C_DEPS += \
./src/libmbed/wait_api.d 

CPP_DEPS += \
./src/libmbed/BusOut.d \
./src/libmbed/DigitalIn.d \
./src/libmbed/DigitalOut.d \
./src/libmbed/Print.d \
./src/libmbed/Serial.d \
./src/libmbed/cr_cpp_config.d \
./src/libmbed/dummy.d \
./src/libmbed/pure_virtual.d 


# Each subdirectory must supply rules for building sources it contributes
src/libmbed/%.o: ../src/libmbed/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__USE_CMSIS=CMSISv2p00_LPC13xx -DPART_LM4F120H5QR -DCPP_USE_HEAP -D__NEWLIB__ -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Include" -I"/Users/take/proj/LBED/lbed/LBED_LM4F120/inc" -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Device/TI/LM4F/Include" -I"/Users/take/proj/LBED/lbed/StelarisWare/StellarisWare" -O1 -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/libmbed/%.o: ../src/libmbed/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv2p00_LPC13xx -DPART_LM4F120H5QR -D__NEWLIB__ -DDEBUG -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Include" -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Device/TI/LM4F/Include" -I"/Users/take/proj/LBED/lbed/LBED_LM4F120/inc" -I"/Users/take/proj/LBED/lbed/StelarisWare/StellarisWare" -O0 -Os -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


