################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Device/ARM/ARMCM4/Source/system_ARMCM4.c 

OBJS += \
./Device/ARM/ARMCM4/Source/system_ARMCM4.o 

C_DEPS += \
./Device/ARM/ARMCM4/Source/system_ARMCM4.d 


# Each subdirectory must supply rules for building sources it contributes
Device/ARM/ARMCM4/Source/%.o: ../Device/ARM/ARMCM4/Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DDEBUG -I"/Users/take/Documents/LPCXpresso_5.2.6/workspace/CMSISv2p00_LM4F120/Include" -I"/Users/take/Documents/LPCXpresso_5.2.6/workspace/CMSISv2p00_LM4F120/Device/ARM/ARMCM4/Include" -I"/Users/take/Documents/LPCXpresso_5.2.6/workspace/CMSISv2p00_LM4F120/Device/TI/LM4F/Include" -O3 -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


