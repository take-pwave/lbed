################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SD/utility/Sd2Card.cpp \
../src/SD/utility/SdFile.cpp \
../src/SD/utility/SdVolume.cpp 

OBJS += \
./src/SD/utility/Sd2Card.o \
./src/SD/utility/SdFile.o \
./src/SD/utility/SdVolume.o 

CPP_DEPS += \
./src/SD/utility/Sd2Card.d \
./src/SD/utility/SdFile.d \
./src/SD/utility/SdVolume.d 


# Each subdirectory must supply rules for building sources it contributes
src/SD/utility/Sd2Card.o: ../src/SD/utility/Sd2Card.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -DDEBUG -D__CODE_RED -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LPC11xx/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino_USERLIB/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino/src/Common/inc" -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/SD/utility/Sd2Card.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/SD/utility/%.o: ../src/SD/utility/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -DDEBUG -D__CODE_RED -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LPC11xx/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino_USERLIB/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino/src/Common/inc" -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/SD/utility/SdVolume.o: ../src/SD/utility/SdVolume.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -DDEBUG -D__CODE_RED -I"/Users/take/proj/LBED/lbed/CMSISv2p00_LPC11xx/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino_USERLIB/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino/inc" -I"/Users/take/proj/LBED/lbed/LBED_lbeDuino/src/Common/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/SD/utility/SdVolume.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


