################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src_base/Main.cpp \
../src_base/cr_cpp_config.cpp \
../src_base/cr_startup_lpc11.cpp 

C_SRCS += \
../src_base/C_Int_Handler.c 

OBJS += \
./src_base/C_Int_Handler.o \
./src_base/Main.o \
./src_base/cr_cpp_config.o \
./src_base/cr_startup_lpc11.o 

C_DEPS += \
./src_base/C_Int_Handler.d 

CPP_DEPS += \
./src_base/Main.d \
./src_base/cr_cpp_config.d \
./src_base/cr_startup_lpc11.d 


# Each subdirectory must supply rules for building sources it contributes
src_base/%.o: ../src_base/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -D__USE_CMSIS=CMSISv2p00_LPC11xx -DDEBUG -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LPC11xx/inc" -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src_base/%.o: ../src_base/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -D__USE_CMSIS=CMSISv2p00_LPC11xx -DDEBUG -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LPC11xx/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino_USERLIB/src/SD" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino/src/Common/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino_USERLIB/inc" -Os -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


