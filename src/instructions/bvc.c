#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case RELATIVE: {
			return 0x50;
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

Instruction* registerBVCInstruction(){
	Instruction* bvc = (Instruction*) malloc(sizeof(Instruction));
	bvc->name = "BVC";
	bvc->modes_count = 1;
	bvc->modes = (MODES*) malloc(bvc->modes_count * sizeof(int));
	bvc->modes[0] = RELATIVE;
	bvc->opcode = &opcode;
	bvc->size = &size;	
	bvc->decode_instruction = &decode_instruction;
	return bvc;
}
