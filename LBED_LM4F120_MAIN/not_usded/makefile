################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: LBED_LM4F120_MAIN.axf

# Tool invocations
LBED_LM4F120_MAIN.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU C++ Linker'
	arm-none-eabi-c++ -nostartfiles -nostdlib -L"/Users/take/proj/LBED/lbed/LBED_LM4F120_USERLIB/Debug" -L"/Users/take/proj/LBED/lbed/StelarisWare/Debug" -L"/Users/take/proj/LBED/lbed/LBED_LM4F120/Debug" -L"/Users/take/proj/LBED/lbed/CMSISv2p00_LM4F120/Debug" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -T LBED_LM4F120_MAIN_Debug.ld -o "LBED_LM4F120_MAIN.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) LBED_LM4F120_MAIN.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "LBED_LM4F120_MAIN.axf"; # arm-none-eabi-objcopy -O binary "LBED_LM4F120_MAIN.axf" "LBED_LM4F120_MAIN.bin" ; checksum -p Cortex_M4 -d "LBED_LM4F120_MAIN.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
