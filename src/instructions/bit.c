#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case ZERO_PAGE: {
			return 0x24;
		}case ABSOLUTE: {
			return 0x2C;
		}default:{
			return -1;
		}
	}
}

static uint8_t size(MODES mode){
	switch(mode){
		case ZERO_PAGE: {
			return 2;
		}case ABSOLUTE: {
			return 3;
		}default:{
			return -1;
		}
	}
}

__attribute__((unused)) static uint8_t* decode_instruction(uint16_t argument, MODES mode){
	return generate_opcode_string(size(mode), mode, opcode(mode), argument);
}

Instruction* registerBITInstruction(){
	Instruction* bit = (Instruction*) malloc(sizeof(Instruction));
	bit->name = "BIT";
	bit->modes_count = 2;
	bit->modes = (MODES*) malloc(bit->modes_count * sizeof(int));
	bit->modes[0] = ZERO_PAGE;
	bit->modes[1] = ABSOLUTE;
	bit->opcode = &opcode;
	bit->size = &size;	
	bit->decode_instruction = &decode_instruction;
	return bit;
}
