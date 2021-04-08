#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case ZERO_PAGE: {
			return 0x85;
		}case ZERO_PAGE_Y: {
			return 0x95;
		}case ABSOLUTE: {
			return 0x8D;
		}default:{
			return -1;
		}
	}
}

Instruction* registerSTXInstruction(){
	Instruction* stx = (Instruction*) malloc(sizeof(Instruction));
	stx->name = "STX";
	stx->modes_count = 3;
	stx->modes = (MODES*) malloc(stx->modes_count * sizeof(int));
	stx->modes[0] = ZERO_PAGE;
	stx->modes[1] = ZERO_PAGE_Y;
	stx->modes[2] = ABSOLUTE;
	stx->opcode = &opcode;
	return stx;
}