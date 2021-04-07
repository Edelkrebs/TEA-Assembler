#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMMEDIATE: {
			return 0x69;
		}case ZERO_PAGE: {
			return 0x65;
		}case ZERO_PAGE_X: {
			return 0x75;
		}case ABSOLUTE: {
			return 0x6D;
		}case ABSOLUTE_X: {
			return 0x7D;
		}case ABSOLUTE_Y: {
			return 0x79;
		}case INDIRECT_X: {
			return 0x61;
		}case INDIRECT_Y: {
			return 0x71;
		}default:{
			return -1;
		}
	}
}

Instruction* registerADCInstruction(){
	Instruction* adc = (Instruction*) malloc(sizeof(Instruction));
	adc->name = "ADC";
	adc->modes_count = 8;
	adc->modes = (MODES*) malloc(adc->modes_count * sizeof(int));
	adc->modes[0] = IMMEDIATE;
	adc->modes[1] = ZERO_PAGE;
	adc->modes[2] = ZERO_PAGE_X;
	adc->modes[3] = ABSOLUTE;
	adc->modes[4] = ABSOLUTE_X;
	adc->modes[5] = ABSOLUTE_Y;
	adc->modes[6] = INDIRECT_X;
	adc->modes[7] = INDIRECT_Y;
	adc->opcode = &opcode;
	return adc;
}
