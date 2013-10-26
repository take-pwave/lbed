################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../StellarisWare/usblib/host/usbhaudio.c \
../StellarisWare/usblib/host/usbhhid.c \
../StellarisWare/usblib/host/usbhhidkeyboard.c \
../StellarisWare/usblib/host/usbhhidmouse.c \
../StellarisWare/usblib/host/usbhhub.c \
../StellarisWare/usblib/host/usbhmsc.c \
../StellarisWare/usblib/host/usbhostenum.c \
../StellarisWare/usblib/host/usbhscsi.c 

OBJS += \
./StellarisWare/usblib/host/usbhaudio.o \
./StellarisWare/usblib/host/usbhhid.o \
./StellarisWare/usblib/host/usbhhidkeyboard.o \
./StellarisWare/usblib/host/usbhhidmouse.o \
./StellarisWare/usblib/host/usbhhub.o \
./StellarisWare/usblib/host/usbhmsc.o \
./StellarisWare/usblib/host/usbhostenum.o \
./StellarisWare/usblib/host/usbhscsi.o 

C_DEPS += \
./StellarisWare/usblib/host/usbhaudio.d \
./StellarisWare/usblib/host/usbhhid.d \
./StellarisWare/usblib/host/usbhhidkeyboard.d \
./StellarisWare/usblib/host/usbhhidmouse.d \
./StellarisWare/usblib/host/usbhhub.d \
./StellarisWare/usblib/host/usbhmsc.d \
./StellarisWare/usblib/host/usbhostenum.d \
./StellarisWare/usblib/host/usbhscsi.d 


# Each subdirectory must supply rules for building sources it contributes
StellarisWare/usblib/host/%.o: ../StellarisWare/usblib/host/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -Dcodered -D__CODE_RED -DPART_LM4F120H5QR -I"/Users/take/proj/LBED/lbed/StelarisWare/StellarisWare" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


