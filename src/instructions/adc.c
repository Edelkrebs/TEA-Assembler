#include <instruction/instruction.h>
#include <stdlib.h>

uint8_t opcode(MODES mode){
	switch(mode){
		case IMMEDIATE: {
			return 2;
		}case ZERO_PAGE: {
			return 2;
		}case ZERO_PAGE_X: {
			return 2;
		}case ABSOLUTE: {
			return 3;
		}case ABSOLUTE_X: {
			return 3;
		}case ABSOLUTE_Y: {
			return 3;
		}case INDIRECT_X: {
			return 2;
		}case INDIRECT_Y: {
			return 2;
		}default:{
			return -1;
		}
	}
}

uint8_t size(MODES mode){
	switch(mode){
		case IMMEDIATE: {
			return 2;
		}case ZERO_PAGE: {
			return 2;
		}case ZERO_PAGE_X: {
			return 2;
		}case ABSOLUTE: {
			return 3;
		}case ABSOLUTE_X: {
			return 3;
		}case ABSOLUTE_Y: {
			return 3;
		}case INDIRECT_X: {
			return 2;
		}case INDIRECT_Y: {
			return 2;
		}default:{
			return -1;
		}
	}
}

char* decode_instruction(uint16_t argument, MODES mode){
	switch(mode){
		case I
	}
	return generate_opcode_string(size(mode), mode, )
}

void registerADCInstruction(){
	Instruction* adc = (Instruction*) malloc(sizeof(Instruction));
	adc->modes = (MODES*) malloc(8 * sizeof(int));
	adc->modes_count = 8;
	adc->modes[0] = IMMEDIATE;
	adc->modes[1] = ZERO_PAGE;
	adc->modes[2] = ZERO_PAGE_X;
	adc->modes[3] = ABSOLUTE;
	adc->modes[4] = ABSOLUTE_X;
	adc->modes[5] = ABSOLUTE_Y;
	adc->modes[6] = INDIRECT_X;
	adc->modes[7] = INDIRECT_Y;
	adc->size = &size;	
}
