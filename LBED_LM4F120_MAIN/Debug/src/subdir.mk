################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Interface201311.cpp \
../src/cr_cpp_config.cpp \
../src/dummy.cpp 

C_SRCS += \
../src/LM4F_startup.c \
../src/syscalls.c 

OBJS += \
./src/Interface201311.o \
./src/LM4F_startup.o \
./src/cr_cpp_config.o \
./src/dummy.o \
./src/syscalls.o 

C_DEPS += \
./src/LM4F_startup.d \
./src/syscalls.d 

CPP_DEPS += \
./src/Interface201311.d \
./src/cr_cpp_config.d \
./src/dummy.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -DPART_LM4F120H5QR -D__USE_CMSIS -DCORE_M4 -D__CODE_RED -DCPP_USE_HEAP -DDEBUG -I"/Users/take/proj/LBED/lbed/StelarisWare/StellarisWare" -I"/Users/take/proj/LBED/lbed/LBED_LM4F120_USERLIB/inc" -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Include" -I"/Users/take/proj/LBED/lbed/LBED_LM4F120/inc" -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Device/TI/LM4F/Include" -I"/Users/take/proj/LBED/lbed/LBED_LM4F120_MAIN/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPP_USE_HEAP -DPART_LM4F120H5QR -D__USE_CMSIS -DCORE_M4 -D__NEWLIB__ -DDEBUG -D__CODE_RED -I"/Users/take/proj/LBED/lbed/StelarisWare/StellarisWare" -I"/Users/take/proj/LBED/lbed/LBED_LM4F120_USERLIB/inc" -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Include" -I"/Users/take/proj/LBED/lbed/LBED_LM4F120/inc" -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Device/TI/LM4F/Include" -I"/Users/take/proj/LBED/lbed/LBED_LM4F120_MAIN/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-exceptions -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


