################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Device/TI/LM4F/Source/Templates/startup/GCC/subdir.mk
-include Device/TI/LM4F/Source/Templates/subdir.mk
-include DSP_Lib/Source/TransformFunctions/subdir.mk
-include DSP_Lib/Source/SupportFunctions/subdir.mk
-include DSP_Lib/Source/StatisticsFunctions/subdir.mk
-include DSP_Lib/Source/MatrixFunctions/subdir.mk
-include DSP_Lib/Source/FilteringFunctions/subdir.mk
-include DSP_Lib/Source/FastMathFunctions/subdir.mk
-include DSP_Lib/Source/ControllerFunctions/subdir.mk
-include DSP_Lib/Source/ComplexMathFunctions/subdir.mk
-include DSP_Lib/Source/CommonTables/subdir.mk
-include DSP_Lib/Source/BasicMathFunctions/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: libCMSISv2p00_LM4F120.a

# Tool invocations
libCMSISv2p00_LM4F120.a: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Archiver'
	arm-none-eabi-ar -r  "libCMSISv2p00_LM4F120.a" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ARCHIVES) libCMSISv2p00_LM4F120.a
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size libCMSISv2p00_LM4F120.a ; # arm-none-eabi-objdump -h -S libCMSISv2p00_LM4F120.a >libCMSISv2p00_LM4F120.lss
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
