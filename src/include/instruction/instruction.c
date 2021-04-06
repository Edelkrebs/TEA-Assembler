#include <instruction/instruction.h>
#include <stdlib.h>
#include <stdio.h>

uint8_t* generate_opcode_string(uint8_t size, MODES mode, uint8_t opcode, uint16_t argument){
	if(((mode == ABSOLUTE) && (size != 3)) || ((mode == ABSOLUTE_X) && (size != 3)) || ((mode == ABSOLUTE_Y) && (size != 3))){
		printf("Invalid operation size.Aborting\n");
		exit(-1);
	}
	uint8_t* opcode_string = (uint8_t*) malloc(size * sizeof(uint8_t));
	switch(mode){
		case IMMEDIATE: {
			opcode_string[0] = opcode;
			opcode_string[1] = (uint8_t)argument;
			return opcode_string;
		}case ZERO_PAGE: {
			opcode_string[0] = opcode;
			opcode_string[1] = (uint8_t)argument;
			return opcode_string;
		}case ZERO_PAGE_X: {
			opcode_string[0] = opcode;
			opcode_string[1] = (uint8_t)argument;
			return opcode_string;
		}case ABSOLUTE: {
			opcode_string[0] = opcode;
			opcode_string[1] = (uint8_t)(argument);
			opcode_string[2] = (uint8_t)(argument >> 8);
			return opcode_string;
		}case ABSOLUTE_X: {
			opcode_string[0] = opcode;
			opcode_string[1] = (uint8_t)(argument);
			opcode_string[2] = (uint8_t)(argument >> 8);
			return opcode_string;
		}case ABSOLUTE_Y: {
			opcode_string[0] = opcode;
			opcode_string[1] = (uint8_t)(argument);
			opcode_string[2] = (uint8_t)(argument >> 8);
			return opcode_string;
		}case INDIRECT_X: {
			opcode_string[0] = opcode;
			opcode_string[1] = (uint8_t)(argument);
			return opcode_string;
		}case INDIRECT_Y: {
			opcode_string[0] = opcode;
			opcode_string[1] = (uint8_t)(argument);
			return opcode_string;
		}default:{
			return 0;
		}
	}
}

void initInstructionset(){
	REGISTER_INSTRUCTION(ADC);
}