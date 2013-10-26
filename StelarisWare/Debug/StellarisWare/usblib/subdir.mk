################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../StellarisWare/usblib/usbbuffer.c \
../StellarisWare/usblib/usbdesc.c \
../StellarisWare/usblib/usbkeyboardmap.c \
../StellarisWare/usblib/usbmode.c \
../StellarisWare/usblib/usbringbuf.c \
../StellarisWare/usblib/usbtick.c 

OBJS += \
./StellarisWare/usblib/usbbuffer.o \
./StellarisWare/usblib/usbdesc.o \
./StellarisWare/usblib/usbkeyboardmap.o \
./StellarisWare/usblib/usbmode.o \
./StellarisWare/usblib/usbringbuf.o \
./StellarisWare/usblib/usbtick.o 

C_DEPS += \
./StellarisWare/usblib/usbbuffer.d \
./StellarisWare/usblib/usbdesc.d \
./StellarisWare/usblib/usbkeyboardmap.d \
./StellarisWare/usblib/usbmode.d \
./StellarisWare/usblib/usbringbuf.d \
./StellarisWare/usblib/usbtick.d 


# Each subdirectory must supply rules for building sources it contributes
StellarisWare/usblib/%.o: ../StellarisWare/usblib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -Dcodered -D__CODE_RED -DPART_LM4F120H5QR -I"/Users/take/proj/LBED/lbed/StelarisWare/StellarisWare" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


