#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMMEDIATE: {
			return 0xE0;
		}case ZERO_PAGE: {
			return 0xE4;
		}case ABSOLUTE: {
			return 0xEC;
		}default:{
			return -1;
		}
	}
}

Instruction* registerCPXInstruction(){
	Instruction* cpx = (Instruction*) malloc(sizeof(Instruction));
	cpx->name = "CPX";
	cpx->modes_count = 3;
	cpx->modes = (MODES*) malloc(cpx->modes_count * sizeof(int));
	cpx->modes[0] = IMMEDIATE;
	cpx->modes[1] = ZERO_PAGE;
	cpx->modes[2] = ABSOLUTE;
	cpx->opcode = &opcode;
	return cpx;
}