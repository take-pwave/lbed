################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../StellarisWare/driverlib/adc.c \
../StellarisWare/driverlib/can.c \
../StellarisWare/driverlib/comp.c \
../StellarisWare/driverlib/cpu.c \
../StellarisWare/driverlib/eeprom.c \
../StellarisWare/driverlib/epi.c \
../StellarisWare/driverlib/ethernet.c \
../StellarisWare/driverlib/fan.c \
../StellarisWare/driverlib/flash.c \
../StellarisWare/driverlib/fpu.c \
../StellarisWare/driverlib/gpio.c \
../StellarisWare/driverlib/hibernate.c \
../StellarisWare/driverlib/i2c.c \
../StellarisWare/driverlib/i2s.c \
../StellarisWare/driverlib/interrupt.c \
../StellarisWare/driverlib/lpc.c \
../StellarisWare/driverlib/mpu.c \
../StellarisWare/driverlib/peci.c \
../StellarisWare/driverlib/pwm.c \
../StellarisWare/driverlib/qei.c \
../StellarisWare/driverlib/ssi.c \
../StellarisWare/driverlib/sysctl.c \
../StellarisWare/driverlib/sysexc.c \
../StellarisWare/driverlib/systick.c \
../StellarisWare/driverlib/timer.c \
../StellarisWare/driverlib/uart.c \
../StellarisWare/driverlib/udma.c \
../StellarisWare/driverlib/usb.c \
../StellarisWare/driverlib/watchdog.c 

OBJS += \
./StellarisWare/driverlib/adc.o \
./StellarisWare/driverlib/can.o \
./StellarisWare/driverlib/comp.o \
./StellarisWare/driverlib/cpu.o \
./StellarisWare/driverlib/eeprom.o \
./StellarisWare/driverlib/epi.o \
./StellarisWare/driverlib/ethernet.o \
./StellarisWare/driverlib/fan.o \
./StellarisWare/driverlib/flash.o \
./StellarisWare/driverlib/fpu.o \
./StellarisWare/driverlib/gpio.o \
./StellarisWare/driverlib/hibernate.o \
./StellarisWare/driverlib/i2c.o \
./StellarisWare/driverlib/i2s.o \
./StellarisWare/driverlib/interrupt.o \
./StellarisWare/driverlib/lpc.o \
./StellarisWare/driverlib/mpu.o \
./StellarisWare/driverlib/peci.o \
./StellarisWare/driverlib/pwm.o \
./StellarisWare/driverlib/qei.o \
./StellarisWare/driverlib/ssi.o \
./StellarisWare/driverlib/sysctl.o \
./StellarisWare/driverlib/sysexc.o \
./StellarisWare/driverlib/systick.o \
./StellarisWare/driverlib/timer.o \
./StellarisWare/driverlib/uart.o \
./StellarisWare/driverlib/udma.o \
./StellarisWare/driverlib/usb.o \
./StellarisWare/driverlib/watchdog.o 

C_DEPS += \
./StellarisWare/driverlib/adc.d \
./StellarisWare/driverlib/can.d \
./StellarisWare/driverlib/comp.d \
./StellarisWare/driverlib/cpu.d \
./StellarisWare/driverlib/eeprom.d \
./StellarisWare/driverlib/epi.d \
./StellarisWare/driverlib/ethernet.d \
./StellarisWare/driverlib/fan.d \
./StellarisWare/driverlib/flash.d \
./StellarisWare/driverlib/fpu.d \
./StellarisWare/driverlib/gpio.d \
./StellarisWare/driverlib/hibernate.d \
./StellarisWare/driverlib/i2c.d \
./StellarisWare/driverlib/i2s.d \
./StellarisWare/driverlib/interrupt.d \
./StellarisWare/driverlib/lpc.d \
./StellarisWare/driverlib/mpu.d \
./StellarisWare/driverlib/peci.d \
./StellarisWare/driverlib/pwm.d \
./StellarisWare/driverlib/qei.d \
./StellarisWare/driverlib/ssi.d \
./StellarisWare/driverlib/sysctl.d \
./StellarisWare/driverlib/sysexc.d \
./StellarisWare/driverlib/systick.d \
./StellarisWare/driverlib/timer.d \
./StellarisWare/driverlib/uart.d \
./StellarisWare/driverlib/udma.d \
./StellarisWare/driverlib/usb.d \
./StellarisWare/driverlib/watchdog.d 


# Each subdirectory must supply rules for building sources it contributes
StellarisWare/driverlib/%.o: ../StellarisWare/driverlib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -Dcodered -D__CODE_RED -DPART_LM4F120H5QR -I"/Users/take/proj/LBED/lbed/StelarisWare/StellarisWare" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


