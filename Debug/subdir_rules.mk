################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Vectors_intr.obj: ../Vectors_intr.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"D:/ti/ccsv5/tools/compiler/c6000/bin/cl6x" -mv6713 -g --define=CHIP_6713 --include_path="D:/ti/ccsv5/tools/compiler/c6000/include" --include_path="C:/Program Files/C6xCSL/include" --include_path="C:/DSK6713/c6000/dsk6713/include" --display_error_number --diag_warning=225 --mem_model:const=far --mem_model:data=far --abi=coffabi --preproc_with_compile --preproc_dependency="Vectors_intr.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

bitrev.obj: ../bitrev.sa $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"D:/ti/ccsv5/tools/compiler/c6000/bin/cl6x" -mv6713 -g --define=CHIP_6713 --include_path="D:/ti/ccsv5/tools/compiler/c6000/include" --include_path="C:/Program Files/C6xCSL/include" --include_path="C:/DSK6713/c6000/dsk6713/include" --display_error_number --diag_warning=225 --mem_model:const=far --mem_model:data=far --abi=coffabi --preproc_with_compile --preproc_dependency="bitrev.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

c6713dskinit.obj: ../c6713dskinit.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"D:/ti/ccsv5/tools/compiler/c6000/bin/cl6x" -mv6713 -g --define=CHIP_6713 --include_path="D:/ti/ccsv5/tools/compiler/c6000/include" --include_path="C:/Program Files/C6xCSL/include" --include_path="C:/DSK6713/c6000/dsk6713/include" --display_error_number --diag_warning=225 --mem_model:const=far --mem_model:data=far --abi=coffabi --preproc_with_compile --preproc_dependency="c6713dskinit.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

cfftr2_dit.obj: ../cfftr2_dit.sa $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"D:/ti/ccsv5/tools/compiler/c6000/bin/cl6x" -mv6713 -g --define=CHIP_6713 --include_path="D:/ti/ccsv5/tools/compiler/c6000/include" --include_path="C:/Program Files/C6xCSL/include" --include_path="C:/DSK6713/c6000/dsk6713/include" --display_error_number --diag_warning=225 --mem_model:const=far --mem_model:data=far --abi=coffabi --preproc_with_compile --preproc_dependency="cfftr2_dit.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

digitrev_index.obj: ../digitrev_index.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"D:/ti/ccsv5/tools/compiler/c6000/bin/cl6x" -mv6713 -g --define=CHIP_6713 --include_path="D:/ti/ccsv5/tools/compiler/c6000/include" --include_path="C:/Program Files/C6xCSL/include" --include_path="C:/DSK6713/c6000/dsk6713/include" --display_error_number --diag_warning=225 --mem_model:const=far --mem_model:data=far --abi=coffabi --preproc_with_compile --preproc_dependency="digitrev_index.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"D:/ti/ccsv5/tools/compiler/c6000/bin/cl6x" -mv6713 -g --define=CHIP_6713 --include_path="D:/ti/ccsv5/tools/compiler/c6000/include" --include_path="C:/Program Files/C6xCSL/include" --include_path="C:/DSK6713/c6000/dsk6713/include" --display_error_number --diag_warning=225 --mem_model:const=far --mem_model:data=far --abi=coffabi --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


