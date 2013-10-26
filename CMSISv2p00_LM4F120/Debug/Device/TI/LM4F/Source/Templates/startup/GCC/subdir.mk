################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Device/TI/LM4F/Source/Templates/startup/GCC/startup_LM4F.s 

OBJS += \
./Device/TI/LM4F/Source/Templates/startup/GCC/startup_LM4F.o 


# Each subdirectory must supply rules for building sources it contributes
Device/TI/LM4F/Source/Templates/startup/GCC/%.o: ../Device/TI/LM4F/Source/Templates/startup/GCC/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -D__NEWLIB__  -DDEBUG -D__CODE_RED -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Include" -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Device/TI/LM4F/Include" -mcpu=cortex-m4 -mfpu=vfp -mfloat-abi=softfp -mthumb -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


