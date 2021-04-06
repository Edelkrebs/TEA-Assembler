#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case RELATIVE: {
			return 0x10;
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

Instruction* registerBPLInstruction(){
	Instruction* bpl = (Instruction*) malloc(sizeof(Instruction));
	bpl->name = "BPL";
	bpl->modes_count = 1;
	bpl->modes = (MODES*) malloc(bpl->modes_count * sizeof(int));
	bpl->modes[0] = RELATIVE;
	bpl->opcode = &opcode;
	bpl->size = &size;	
	bpl->decode_instruction = &decode_instruction;
	return bpl;
}
