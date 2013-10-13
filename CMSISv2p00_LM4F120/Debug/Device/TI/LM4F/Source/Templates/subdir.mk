################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Device/TI/LM4F/Source/Templates/system_LM4F.c 

OBJS += \
./Device/TI/LM4F/Source/Templates/system_LM4F.o 

C_DEPS += \
./Device/TI/LM4F/Source/Templates/system_LM4F.d 


# Each subdirectory must supply rules for building sources it contributes
Device/TI/LM4F/Source/Templates/%.o: ../Device/TI/LM4F/Source/Templates/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DARM_MATH_CM4 -DDEBUG -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Include" -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/DSP_Lib/Examples/Common/Include" -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Device/TI/LM4F/Include" -O3 -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


