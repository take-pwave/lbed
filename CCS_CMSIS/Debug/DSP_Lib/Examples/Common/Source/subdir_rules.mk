################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
DSP_Lib/Examples/Common/Source/math_helper.obj: ../DSP_Lib/Examples/Common/Source/math_helper.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/tms470_4.9.5/bin/cl470" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/tms470_4.9.5/include" --include_path="C:/EK-LM4F120XL-CCS-733/workspace_v5_2/CCS_CMSIS/Device/TI/LM4F/Include" --include_path="C:/EK-LM4F120XL-CCS-733/workspace_v5_2/CCS_CMSIS/Include" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="DSP_Lib/Examples/Common/Source/math_helper.pp" --obj_directory="DSP_Lib/Examples/Common/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


