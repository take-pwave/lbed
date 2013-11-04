################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/I2cLCD.obj: ../src/I2cLCD.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/tms470_4.9.5/bin/cl470" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/tms470_4.9.5/include" --include_path="Z:/take/proj/LBED/lbed/CCS_CMSIS/Include" --include_path="Z:/take/proj/LBED/lbed/CCS_CMSIS/Device/TI/LM4F/Include" --include_path="Z:/take/proj/LBED/lbed/CCS_LBED/inc" --include_path="Z:/take/proj/LBED/lbed/CCS_LBED_USERLIB/inc" --include_path="C:/StellarisWare" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="src/I2cLCD.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/LM73.obj: ../src/LM73.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/tms470_4.9.5/bin/cl470" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/tms470_4.9.5/include" --include_path="Z:/take/proj/LBED/lbed/CCS_CMSIS/Include" --include_path="Z:/take/proj/LBED/lbed/CCS_CMSIS/Device/TI/LM4F/Include" --include_path="Z:/take/proj/LBED/lbed/CCS_LBED/inc" --include_path="Z:/take/proj/LBED/lbed/CCS_LBED_USERLIB/inc" --include_path="C:/StellarisWare" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="src/LM73.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/TextLCD.obj: ../src/TextLCD.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/tms470_4.9.5/bin/cl470" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/tms470_4.9.5/include" --include_path="Z:/take/proj/LBED/lbed/CCS_CMSIS/Include" --include_path="Z:/take/proj/LBED/lbed/CCS_CMSIS/Device/TI/LM4F/Include" --include_path="Z:/take/proj/LBED/lbed/CCS_LBED/inc" --include_path="Z:/take/proj/LBED/lbed/CCS_LBED_USERLIB/inc" --include_path="C:/StellarisWare" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="src/TextLCD.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


