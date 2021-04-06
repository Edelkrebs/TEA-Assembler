#include <instruction/instruction.h>
#include <stdlib.h>
#include <stdio.h>

uint8_t* generate_opcode_string(uint8_t size, MODES mode, uint8_t opcode, uint16_t argument){
	if((mode == ABSOLUTE) && (size != 3)) || (mode == ABSOLUTE_X) && (size != 3)) || (mode == ABSOLUTE_Y) && (size != 3))){
		printf("Invalid operation size.Aborting\n");
		exit(-1);
	}
	uint8_t* opcode_string = (char*) malloc(size * sizeof(char));
	switch(mode){
		case IMMEDIATE: {
			opcode_string[0] = opcode;
			opcode_string[1] = (uint8_t)argument;
		}case ZERO_PAGE: {
			
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

void initInstructionset(){
	REGISTER_INSTRUCTION(ADC);
}