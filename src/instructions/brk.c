#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case RELATIVE: {
			return 0x00;
		}default:{
			return -1;
		}
	}
}

static uint8_t size(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 1;
		}default:{
			return -1;
		}
	}
}

__attribute__((unused)) static uint8_t* decode_instruction(uint16_t argument, MODES mode){
	return generate_opcode_string(size(mode), mode, opcode(mode), argument);
}

Instruction* registerBRKInstruction(){
	Instruction* brk = (Instruction*) malloc(sizeof(Instruction));
	brk->name = "BRK";
	brk->modes_count = 1;
	brk->modes = (MODES*) malloc(brk->modes_count * sizeof(int));
	brk->modes[0] = IMPLIED;
	brk->opcode = &opcode;
	brk->size = &size;	
	brk->decode_instruction = &decode_instruction;
	return brk;
}
