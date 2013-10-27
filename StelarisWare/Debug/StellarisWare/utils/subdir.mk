################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../StellarisWare/utils/cmdline.c \
../StellarisWare/utils/cpu_usage.c \
../StellarisWare/utils/crc.c \
../StellarisWare/utils/flash_pb.c \
../StellarisWare/utils/isqrt.c \
../StellarisWare/utils/ringbuf.c \
../StellarisWare/utils/scheduler.c \
../StellarisWare/utils/sine.c \
../StellarisWare/utils/softi2c.c \
../StellarisWare/utils/softssi.c \
../StellarisWare/utils/softuart.c \
../StellarisWare/utils/uartstdio.c \
../StellarisWare/utils/ustdlib.c 

OBJS += \
./StellarisWare/utils/cmdline.o \
./StellarisWare/utils/cpu_usage.o \
./StellarisWare/utils/crc.o \
./StellarisWare/utils/flash_pb.o \
./StellarisWare/utils/isqrt.o \
./StellarisWare/utils/ringbuf.o \
./StellarisWare/utils/scheduler.o \
./StellarisWare/utils/sine.o \
./StellarisWare/utils/softi2c.o \
./StellarisWare/utils/softssi.o \
./StellarisWare/utils/softuart.o \
./StellarisWare/utils/uartstdio.o \
./StellarisWare/utils/ustdlib.o 

C_DEPS += \
./StellarisWare/utils/cmdline.d \
./StellarisWare/utils/cpu_usage.d \
./StellarisWare/utils/crc.d \
./StellarisWare/utils/flash_pb.d \
./StellarisWare/utils/isqrt.d \
./StellarisWare/utils/ringbuf.d \
./StellarisWare/utils/scheduler.d \
./StellarisWare/utils/sine.d \
./StellarisWare/utils/softi2c.d \
./StellarisWare/utils/softssi.d \
./StellarisWare/utils/softuart.d \
./StellarisWare/utils/uartstdio.d \
./StellarisWare/utils/ustdlib.d 


# Each subdirectory must supply rules for building sources it contributes
StellarisWare/utils/%.o: ../StellarisWare/utils/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -Dcodered -D__CODE_RED -DPART_LM4F120H5QR -I"/Users/take/proj/LBED/lbed/StelarisWare/StellarisWare" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


