#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case RELATIVE: {
			return 0xB0;
		}default:{
			return -1;
		}
	}
}

static uint8_t size(MODES mode){
	switch(mode){
		case RELATIVE: {
			return 2;
		}default:{
			return -1;
		}
	}
}

__attribute__((unused)) static uint8_t* decode_instruction(uint16_t argument, MODES mode){
	return generate_opcode_string(size(mode), mode, opcode(mode), argument);
}

Instruction* registerBCSInstruction(){
	Instruction* bcs = (Instruction*) malloc(sizeof(Instruction));
	bcs->name = "BCS";
	bcs->modes_count = 1;
	bcs->modes = (MODES*) malloc(bcs->modes_count * sizeof(int));
	bcs->modes[0] = RELATIVE;
	bcs->opcode = &opcode;
	bcs->size = &size;	
	bcs->decode_instruction = &decode_instruction;
	return bcs;
}
