################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Device/TI/LM4F/Source/Templates/startup/GCC/startup_LM4F.obj: ../Device/TI/LM4F/Source/Templates/startup/GCC/startup_LM4F.s $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/tms470_4.9.5/bin/cl470" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/tms470_4.9.5/include" --include_path="C:/EK-LM4F120XL-CCS-733/workspace_v5_2/CCS_CMSIS/Device/TI/LM4F/Include" --include_path="C:/EK-LM4F120XL-CCS-733/workspace_v5_2/CCS_CMSIS/Include" --define=ARM_MATH_CM4 --define=__FPU_PRESENT=1 --define=__GNUC__ --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Device/TI/LM4F/Source/Templates/startup/GCC/startup_LM4F.pp" --obj_directory="Device/TI/LM4F/Source/Templates/startup/GCC" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


