################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/TestLED.obj: ../src/TestLED.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/tms470_4.9.5/bin/cl470" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/tms470_4.9.5/include" --include_path="Z:/take/proj/LBED/lbed/CCS_LBED/inc" --include_path="Z:/take/proj/LBED/lbed/CCS_LBED_USERLIB/inc" --include_path="Z:/take/proj/LBED/lbed/CCS_CMSIS/Device/TI/LM4F/Include" --include_path="Z:/take/proj/LBED/lbed/CCS_CMSIS/Include" --include_path="C:/StellarisWare" --define=ARM_MATH_CM4 --define=__FPU_PRESENT=1 --define=PART_LM4F120H5QR --define=__GNUC__ --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="src/TestLED.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/startup_ccs.obj: ../src/startup_ccs.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/tms470_4.9.5/bin/cl470" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/tms470_4.9.5/include" --include_path="Z:/take/proj/LBED/lbed/CCS_LBED/inc" --include_path="Z:/take/proj/LBED/lbed/CCS_LBED_USERLIB/inc" --include_path="Z:/take/proj/LBED/lbed/CCS_CMSIS/Device/TI/LM4F/Include" --include_path="Z:/take/proj/LBED/lbed/CCS_CMSIS/Include" --include_path="C:/StellarisWare" --define=ARM_MATH_CM4 --define=__FPU_PRESENT=1 --define=PART_LM4F120H5QR --define=__GNUC__ --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="src/startup_ccs.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/system_LM4F.obj: ../src/system_LM4F.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/tms470_4.9.5/bin/cl470" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/tms470_4.9.5/include" --include_path="Z:/take/proj/LBED/lbed/CCS_LBED/inc" --include_path="Z:/take/proj/LBED/lbed/CCS_LBED_USERLIB/inc" --include_path="Z:/take/proj/LBED/lbed/CCS_CMSIS/Device/TI/LM4F/Include" --include_path="Z:/take/proj/LBED/lbed/CCS_CMSIS/Include" --include_path="C:/StellarisWare" --define=ARM_MATH_CM4 --define=__FPU_PRESENT=1 --define=PART_LM4F120H5QR --define=__GNUC__ --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="src/system_LM4F.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


