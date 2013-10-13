################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../Device/ARM/ARMCM4/Source/GCC/startup_ARMCM4.S 

OBJS += \
./Device/ARM/ARMCM4/Source/GCC/startup_ARMCM4.o 


# Each subdirectory must supply rules for building sources it contributes
Device/ARM/ARMCM4/Source/GCC/%.o: ../Device/ARM/ARMCM4/Source/GCC/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -D__NEWLIB__  -DDEBUG -D__CODE_RED -I"/Users/take/Documents/LPCXpresso_5.2.6/workspace/CMSISv2p00_LM4F120/Include" -I"/Users/take/Documents/LPCXpresso_5.2.6/workspace/CMSISv2p00_LM4F120/Device/TI/LM4F/Include" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


