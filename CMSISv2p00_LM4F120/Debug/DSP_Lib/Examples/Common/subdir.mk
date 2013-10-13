################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DSP_Lib/Examples/Common/system_ARMCM4.c 

OBJS += \
./DSP_Lib/Examples/Common/system_ARMCM4.o 

C_DEPS += \
./DSP_Lib/Examples/Common/system_ARMCM4.d 


# Each subdirectory must supply rules for building sources it contributes
DSP_Lib/Examples/Common/%.o: ../DSP_Lib/Examples/Common/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DARM_MATH_CM4 -DDEBUG -I"/Users/take/Documents/LPCXpresso_5.2.6/workspace/CMSISv2p00_LM4F120/Include" -I"/Users/take/Documents/LPCXpresso_5.2.6/workspace/CMSISv2p00_LM4F120/DSP_Lib/Examples/Common/Include" -I"/Users/take/Documents/LPCXpresso_5.2.6/workspace/CMSISv2p00_LM4F120/Device/TI/LM4F/Include" -O3 -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


