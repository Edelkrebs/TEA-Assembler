#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMMEDIATE: {
			return 0xC0;
		}case ZERO_PAGE: {
			return 0xC4;
		}case ABSOLUTE: {
			return 0xCC;
		}default:{
			return -1;
		}
	}
}

Instruction* registerCPYInstruction(){
	Instruction* cpy = (Instruction*) malloc(sizeof(Instruction));
	cpy->name = "CPY";
	cpy->modes_count = 3;
	cpy->modes = (MODES*) malloc(cpy->modes_count * sizeof(int));
	cpy->modes[0] = IMMEDIATE;
	cpy->modes[1] = ZERO_PAGE;
	cpy->modes[2] = ABSOLUTE;
	cpy->opcode = &opcode;
	return cpy;
}