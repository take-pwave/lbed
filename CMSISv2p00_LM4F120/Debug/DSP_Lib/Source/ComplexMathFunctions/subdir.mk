################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_conj_f32.c \
../DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_conj_q15.c \
../DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_conj_q31.c \
../DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.c \
../DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.c \
../DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.c \
../DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_f32.c \
../DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_q15.c \
../DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_q31.c \
../DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.c \
../DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.c \
../DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.c \
../DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.c \
../DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.c \
../DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.c \
../DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.c \
../DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.c \
../DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.c 

OBJS += \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_conj_f32.o \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_conj_q15.o \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_conj_q31.o \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.o \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.o \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.o \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_f32.o \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_q15.o \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_q31.o \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.o \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.o \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.o \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.o \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.o \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.o \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.o \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.o \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.o 

C_DEPS += \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_conj_f32.d \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_conj_q15.d \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_conj_q31.d \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.d \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.d \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.d \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_f32.d \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_q15.d \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_q31.d \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.d \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.d \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.d \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.d \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.d \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.d \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.d \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.d \
./DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.d 


# Each subdirectory must supply rules for building sources it contributes
DSP_Lib/Source/ComplexMathFunctions/%.o: ../DSP_Lib/Source/ComplexMathFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DARM_MATH_CM4 -DDEBUG -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Include" -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/DSP_Lib/Examples/Common/Include" -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Device/TI/LM4F/Include" -O3 -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=vfp -mfloat-abi=softfp -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


