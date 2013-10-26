################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DSP_Lib/Source/StatisticsFunctions/arm_max_f32.c \
../DSP_Lib/Source/StatisticsFunctions/arm_max_q15.c \
../DSP_Lib/Source/StatisticsFunctions/arm_max_q31.c \
../DSP_Lib/Source/StatisticsFunctions/arm_max_q7.c \
../DSP_Lib/Source/StatisticsFunctions/arm_mean_f32.c \
../DSP_Lib/Source/StatisticsFunctions/arm_mean_q15.c \
../DSP_Lib/Source/StatisticsFunctions/arm_mean_q31.c \
../DSP_Lib/Source/StatisticsFunctions/arm_mean_q7.c \
../DSP_Lib/Source/StatisticsFunctions/arm_min_f32.c \
../DSP_Lib/Source/StatisticsFunctions/arm_min_q15.c \
../DSP_Lib/Source/StatisticsFunctions/arm_min_q31.c \
../DSP_Lib/Source/StatisticsFunctions/arm_min_q7.c \
../DSP_Lib/Source/StatisticsFunctions/arm_power_f32.c \
../DSP_Lib/Source/StatisticsFunctions/arm_power_q15.c \
../DSP_Lib/Source/StatisticsFunctions/arm_power_q31.c \
../DSP_Lib/Source/StatisticsFunctions/arm_power_q7.c \
../DSP_Lib/Source/StatisticsFunctions/arm_rms_f32.c \
../DSP_Lib/Source/StatisticsFunctions/arm_rms_q15.c \
../DSP_Lib/Source/StatisticsFunctions/arm_rms_q31.c \
../DSP_Lib/Source/StatisticsFunctions/arm_std_f32.c \
../DSP_Lib/Source/StatisticsFunctions/arm_std_q15.c \
../DSP_Lib/Source/StatisticsFunctions/arm_std_q31.c \
../DSP_Lib/Source/StatisticsFunctions/arm_var_f32.c \
../DSP_Lib/Source/StatisticsFunctions/arm_var_q15.c \
../DSP_Lib/Source/StatisticsFunctions/arm_var_q31.c 

OBJS += \
./DSP_Lib/Source/StatisticsFunctions/arm_max_f32.o \
./DSP_Lib/Source/StatisticsFunctions/arm_max_q15.o \
./DSP_Lib/Source/StatisticsFunctions/arm_max_q31.o \
./DSP_Lib/Source/StatisticsFunctions/arm_max_q7.o \
./DSP_Lib/Source/StatisticsFunctions/arm_mean_f32.o \
./DSP_Lib/Source/StatisticsFunctions/arm_mean_q15.o \
./DSP_Lib/Source/StatisticsFunctions/arm_mean_q31.o \
./DSP_Lib/Source/StatisticsFunctions/arm_mean_q7.o \
./DSP_Lib/Source/StatisticsFunctions/arm_min_f32.o \
./DSP_Lib/Source/StatisticsFunctions/arm_min_q15.o \
./DSP_Lib/Source/StatisticsFunctions/arm_min_q31.o \
./DSP_Lib/Source/StatisticsFunctions/arm_min_q7.o \
./DSP_Lib/Source/StatisticsFunctions/arm_power_f32.o \
./DSP_Lib/Source/StatisticsFunctions/arm_power_q15.o \
./DSP_Lib/Source/StatisticsFunctions/arm_power_q31.o \
./DSP_Lib/Source/StatisticsFunctions/arm_power_q7.o \
./DSP_Lib/Source/StatisticsFunctions/arm_rms_f32.o \
./DSP_Lib/Source/StatisticsFunctions/arm_rms_q15.o \
./DSP_Lib/Source/StatisticsFunctions/arm_rms_q31.o \
./DSP_Lib/Source/StatisticsFunctions/arm_std_f32.o \
./DSP_Lib/Source/StatisticsFunctions/arm_std_q15.o \
./DSP_Lib/Source/StatisticsFunctions/arm_std_q31.o \
./DSP_Lib/Source/StatisticsFunctions/arm_var_f32.o \
./DSP_Lib/Source/StatisticsFunctions/arm_var_q15.o \
./DSP_Lib/Source/StatisticsFunctions/arm_var_q31.o 

C_DEPS += \
./DSP_Lib/Source/StatisticsFunctions/arm_max_f32.d \
./DSP_Lib/Source/StatisticsFunctions/arm_max_q15.d \
./DSP_Lib/Source/StatisticsFunctions/arm_max_q31.d \
./DSP_Lib/Source/StatisticsFunctions/arm_max_q7.d \
./DSP_Lib/Source/StatisticsFunctions/arm_mean_f32.d \
./DSP_Lib/Source/StatisticsFunctions/arm_mean_q15.d \
./DSP_Lib/Source/StatisticsFunctions/arm_mean_q31.d \
./DSP_Lib/Source/StatisticsFunctions/arm_mean_q7.d \
./DSP_Lib/Source/StatisticsFunctions/arm_min_f32.d \
./DSP_Lib/Source/StatisticsFunctions/arm_min_q15.d \
./DSP_Lib/Source/StatisticsFunctions/arm_min_q31.d \
./DSP_Lib/Source/StatisticsFunctions/arm_min_q7.d \
./DSP_Lib/Source/StatisticsFunctions/arm_power_f32.d \
./DSP_Lib/Source/StatisticsFunctions/arm_power_q15.d \
./DSP_Lib/Source/StatisticsFunctions/arm_power_q31.d \
./DSP_Lib/Source/StatisticsFunctions/arm_power_q7.d \
./DSP_Lib/Source/StatisticsFunctions/arm_rms_f32.d \
./DSP_Lib/Source/StatisticsFunctions/arm_rms_q15.d \
./DSP_Lib/Source/StatisticsFunctions/arm_rms_q31.d \
./DSP_Lib/Source/StatisticsFunctions/arm_std_f32.d \
./DSP_Lib/Source/StatisticsFunctions/arm_std_q15.d \
./DSP_Lib/Source/StatisticsFunctions/arm_std_q31.d \
./DSP_Lib/Source/StatisticsFunctions/arm_var_f32.d \
./DSP_Lib/Source/StatisticsFunctions/arm_var_q15.d \
./DSP_Lib/Source/StatisticsFunctions/arm_var_q31.d 


# Each subdirectory must supply rules for building sources it contributes
DSP_Lib/Source/StatisticsFunctions/%.o: ../DSP_Lib/Source/StatisticsFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DARM_MATH_CM4 -DDEBUG -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Include" -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/DSP_Lib/Examples/Common/Include" -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Device/TI/LM4F/Include" -O3 -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


