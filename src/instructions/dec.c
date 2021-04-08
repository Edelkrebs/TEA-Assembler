#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case ZERO_PAGE: {
			return 0xC6;
		}case ZERO_PAGE_X: {
			return 0xD6;
		}case ABSOLUTE: {
			return 0xCE;
		}case ABSOLUTE_X: {
			return 0xDE;
		}default:{
			return -1;
		}
	}
}

Instruction* registerDECInstruction(){
	Instruction* dec = (Instruction*) malloc(sizeof(Instruction));
	dec->name = "DEC";
	dec->modes_count = 4;
	dec->modes = (MODES*) malloc(dec->modes_count * sizeof(int));
	dec->modes[0] = IMPLIED;
	dec->opcode = &opcode;
	return dec;
}