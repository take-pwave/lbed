################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/TestSerial.cpp \
../src/cr_cpp_config.cpp \
../src/dummy.cpp 

C_SRCS += \
../src/LM4F_startup.c 

OBJS += \
./src/LM4F_startup.o \
./src/TestSerial.o \
./src/cr_cpp_config.o \
./src/dummy.o 

C_DEPS += \
./src/LM4F_startup.d 

CPP_DEPS += \
./src/TestSerial.d \
./src/cr_cpp_config.d \
./src/dummy.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPP_USE_HEAP -D__USE_CMSIS -DCORE_M4 -D__REDLIB__ -DDEBUG -D__CODE_RED -I"/Users/take/proj/LBED/lbed/StelarisWare/StellarisWare" -I"/Users/take/proj/LBED/lbed/LBED_LM4F120_USERLIB/inc" -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Include" -I"/Users/take/proj/LBED/lbed/LBED_LM4F120/inc" -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Device/TI/LM4F/Include" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -D__USE_CMSIS -DCORE_M4 -D__CODE_RED -DCPP_USE_HEAP -DDEBUG -I"/Users/take/proj/LBED/lbed/StelarisWare/StellarisWare" -I"/Users/take/proj/LBED/lbed/LBED_LM4F120_USERLIB/inc" -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Include" -I"/Users/take/proj/LBED/lbed/LBED_LM4F120/inc" -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Device/TI/LM4F/Include" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


