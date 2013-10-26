################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DSP_Lib/Source/SupportFunctions/arm_copy_f32.c \
../DSP_Lib/Source/SupportFunctions/arm_copy_q15.c \
../DSP_Lib/Source/SupportFunctions/arm_copy_q31.c \
../DSP_Lib/Source/SupportFunctions/arm_copy_q7.c \
../DSP_Lib/Source/SupportFunctions/arm_fill_f32.c \
../DSP_Lib/Source/SupportFunctions/arm_fill_q15.c \
../DSP_Lib/Source/SupportFunctions/arm_fill_q31.c \
../DSP_Lib/Source/SupportFunctions/arm_fill_q7.c \
../DSP_Lib/Source/SupportFunctions/arm_float_to_q15.c \
../DSP_Lib/Source/SupportFunctions/arm_float_to_q31.c \
../DSP_Lib/Source/SupportFunctions/arm_float_to_q7.c \
../DSP_Lib/Source/SupportFunctions/arm_q15_to_float.c \
../DSP_Lib/Source/SupportFunctions/arm_q15_to_q31.c \
../DSP_Lib/Source/SupportFunctions/arm_q15_to_q7.c \
../DSP_Lib/Source/SupportFunctions/arm_q31_to_float.c \
../DSP_Lib/Source/SupportFunctions/arm_q31_to_q15.c \
../DSP_Lib/Source/SupportFunctions/arm_q31_to_q7.c \
../DSP_Lib/Source/SupportFunctions/arm_q7_to_float.c \
../DSP_Lib/Source/SupportFunctions/arm_q7_to_q15.c \
../DSP_Lib/Source/SupportFunctions/arm_q7_to_q31.c 

OBJS += \
./DSP_Lib/Source/SupportFunctions/arm_copy_f32.o \
./DSP_Lib/Source/SupportFunctions/arm_copy_q15.o \
./DSP_Lib/Source/SupportFunctions/arm_copy_q31.o \
./DSP_Lib/Source/SupportFunctions/arm_copy_q7.o \
./DSP_Lib/Source/SupportFunctions/arm_fill_f32.o \
./DSP_Lib/Source/SupportFunctions/arm_fill_q15.o \
./DSP_Lib/Source/SupportFunctions/arm_fill_q31.o \
./DSP_Lib/Source/SupportFunctions/arm_fill_q7.o \
./DSP_Lib/Source/SupportFunctions/arm_float_to_q15.o \
./DSP_Lib/Source/SupportFunctions/arm_float_to_q31.o \
./DSP_Lib/Source/SupportFunctions/arm_float_to_q7.o \
./DSP_Lib/Source/SupportFunctions/arm_q15_to_float.o \
./DSP_Lib/Source/SupportFunctions/arm_q15_to_q31.o \
./DSP_Lib/Source/SupportFunctions/arm_q15_to_q7.o \
./DSP_Lib/Source/SupportFunctions/arm_q31_to_float.o \
./DSP_Lib/Source/SupportFunctions/arm_q31_to_q15.o \
./DSP_Lib/Source/SupportFunctions/arm_q31_to_q7.o \
./DSP_Lib/Source/SupportFunctions/arm_q7_to_float.o \
./DSP_Lib/Source/SupportFunctions/arm_q7_to_q15.o \
./DSP_Lib/Source/SupportFunctions/arm_q7_to_q31.o 

C_DEPS += \
./DSP_Lib/Source/SupportFunctions/arm_copy_f32.d \
./DSP_Lib/Source/SupportFunctions/arm_copy_q15.d \
./DSP_Lib/Source/SupportFunctions/arm_copy_q31.d \
./DSP_Lib/Source/SupportFunctions/arm_copy_q7.d \
./DSP_Lib/Source/SupportFunctions/arm_fill_f32.d \
./DSP_Lib/Source/SupportFunctions/arm_fill_q15.d \
./DSP_Lib/Source/SupportFunctions/arm_fill_q31.d \
./DSP_Lib/Source/SupportFunctions/arm_fill_q7.d \
./DSP_Lib/Source/SupportFunctions/arm_float_to_q15.d \
./DSP_Lib/Source/SupportFunctions/arm_float_to_q31.d \
./DSP_Lib/Source/SupportFunctions/arm_float_to_q7.d \
./DSP_Lib/Source/SupportFunctions/arm_q15_to_float.d \
./DSP_Lib/Source/SupportFunctions/arm_q15_to_q31.d \
./DSP_Lib/Source/SupportFunctions/arm_q15_to_q7.d \
./DSP_Lib/Source/SupportFunctions/arm_q31_to_float.d \
./DSP_Lib/Source/SupportFunctions/arm_q31_to_q15.d \
./DSP_Lib/Source/SupportFunctions/arm_q31_to_q7.d \
./DSP_Lib/Source/SupportFunctions/arm_q7_to_float.d \
./DSP_Lib/Source/SupportFunctions/arm_q7_to_q15.d \
./DSP_Lib/Source/SupportFunctions/arm_q7_to_q31.d 


# Each subdirectory must supply rules for building sources it contributes
DSP_Lib/Source/SupportFunctions/%.o: ../DSP_Lib/Source/SupportFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DARM_MATH_CM4 -DDEBUG -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Include" -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/DSP_Lib/Examples/Common/Include" -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Device/TI/LM4F/Include" -O3 -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


