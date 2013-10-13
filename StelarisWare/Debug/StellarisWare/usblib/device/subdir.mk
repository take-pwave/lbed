################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../StellarisWare/usblib/device/usbdaudio.c \
../StellarisWare/usblib/device/usbdbulk.c \
../StellarisWare/usblib/device/usbdcdc.c \
../StellarisWare/usblib/device/usbdcdesc.c \
../StellarisWare/usblib/device/usbdcomp.c \
../StellarisWare/usblib/device/usbdconfig.c \
../StellarisWare/usblib/device/usbddfu-rt.c \
../StellarisWare/usblib/device/usbdenum.c \
../StellarisWare/usblib/device/usbdhandler.c \
../StellarisWare/usblib/device/usbdhid.c \
../StellarisWare/usblib/device/usbdhidkeyb.c \
../StellarisWare/usblib/device/usbdhidmouse.c \
../StellarisWare/usblib/device/usbdmsc.c 

OBJS += \
./StellarisWare/usblib/device/usbdaudio.o \
./StellarisWare/usblib/device/usbdbulk.o \
./StellarisWare/usblib/device/usbdcdc.o \
./StellarisWare/usblib/device/usbdcdesc.o \
./StellarisWare/usblib/device/usbdcomp.o \
./StellarisWare/usblib/device/usbdconfig.o \
./StellarisWare/usblib/device/usbddfu-rt.o \
./StellarisWare/usblib/device/usbdenum.o \
./StellarisWare/usblib/device/usbdhandler.o \
./StellarisWare/usblib/device/usbdhid.o \
./StellarisWare/usblib/device/usbdhidkeyb.o \
./StellarisWare/usblib/device/usbdhidmouse.o \
./StellarisWare/usblib/device/usbdmsc.o 

C_DEPS += \
./StellarisWare/usblib/device/usbdaudio.d \
./StellarisWare/usblib/device/usbdbulk.d \
./StellarisWare/usblib/device/usbdcdc.d \
./StellarisWare/usblib/device/usbdcdesc.d \
./StellarisWare/usblib/device/usbdcomp.d \
./StellarisWare/usblib/device/usbdconfig.d \
./StellarisWare/usblib/device/usbddfu-rt.d \
./StellarisWare/usblib/device/usbdenum.d \
./StellarisWare/usblib/device/usbdhandler.d \
./StellarisWare/usblib/device/usbdhid.d \
./StellarisWare/usblib/device/usbdhidkeyb.d \
./StellarisWare/usblib/device/usbdhidmouse.d \
./StellarisWare/usblib/device/usbdmsc.d 


# Each subdirectory must supply rules for building sources it contributes
StellarisWare/usblib/device/%.o: ../StellarisWare/usblib/device/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -Dcodered -DDEBUG -D__CODE_RED -I"/Users/take/proj/LBED/lbed/StelarisWare/StellarisWare" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


