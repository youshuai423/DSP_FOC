################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
sources/imcontrol.obj: ../sources/imcontrol.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"c:/ti/ccsv6/tools/compiler/c2000_6.2.5/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/Users/yoush/Desktop/DSP_FOC/Includes" --include_path="c:/ti/ccsv6/tools/compiler/c2000_6.2.5/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="sources/imcontrol.pp" --obj_directory="sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

sources/main.obj: ../sources/main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"c:/ti/ccsv6/tools/compiler/c2000_6.2.5/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/Users/yoush/Desktop/DSP_FOC/Includes" --include_path="c:/ti/ccsv6/tools/compiler/c2000_6.2.5/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="sources/main.pp" --obj_directory="sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

sources/ysADC.obj: ../sources/ysADC.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"c:/ti/ccsv6/tools/compiler/c2000_6.2.5/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/Users/yoush/Desktop/DSP_FOC/Includes" --include_path="c:/ti/ccsv6/tools/compiler/c2000_6.2.5/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="sources/ysADC.pp" --obj_directory="sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

sources/ysPWM.obj: ../sources/ysPWM.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"c:/ti/ccsv6/tools/compiler/c2000_6.2.5/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/Users/yoush/Desktop/DSP_FOC/Includes" --include_path="c:/ti/ccsv6/tools/compiler/c2000_6.2.5/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="sources/ysPWM.pp" --obj_directory="sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

