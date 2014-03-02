################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/RealTimeClock.cpp \
../src/cr_cpp_config.cpp \
../src/cr_startup_lpc8xx.cpp 

C_SRCS += \
../src/crp.c \
../src/mtb.c 

OBJS += \
./src/RealTimeClock.o \
./src/cr_cpp_config.o \
./src/cr_startup_lpc8xx.o \
./src/crp.o \
./src/mtb.o 

C_DEPS += \
./src/crp.d \
./src/mtb.d 

CPP_DEPS += \
./src/RealTimeClock.d \
./src/cr_cpp_config.d \
./src/cr_startup_lpc8xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_CMSIS=CMSIS_CORE_LPC8xx -DCPP_USE_HEAP -D__LPC8XX__ -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/LBED_LPC810/inc" -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/LBED_LPC810/src/common" -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/LBED_LPC810/src/userlib" -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/CMSIS_CORE_LPC8xx/inc" -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/lpc800_driver_lib/inc" -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/cr_startup_lpc8xx.o: ../src/cr_startup_lpc8xx.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_CMSIS=CMSIS_CORE_LPC8xx -DCPP_USE_HEAP -D__LPC8XX__ -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/LBED_LPC810/inc" -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/LBED_LPC810/src/common" -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/LBED_LPC810/src/userlib" -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/CMSIS_CORE_LPC8xx/inc" -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/lpc800_driver_lib/inc" -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/cr_startup_lpc8xx.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_CMSIS=CMSIS_CORE_LPC8xx -DCPP_USE_HEAP -D__LPC8XX__ -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/LBED_LPC810/inc" -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/LBED_LPC810/src/common" -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/LBED_LPC810/src/userlib" -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/CMSIS_CORE_LPC8xx/inc" -I"/Users/take/Documents/LPCXpresso_6.0.2/workspace/lpc800_driver_lib/inc" -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


