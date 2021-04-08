#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case ACCUMULATOR: {
			return 0x4A;
		}case ZERO_PAGE: {
			return 0x46;
		}case ZERO_PAGE_X: {
			return 0x56;
		}case ABSOLUTE: {
			return 0x4E;
		}case ABSOLUTE_X: {
			return 0x5E;
		}default:{
			return -1;
		}
	}
}

Instruction* registerLSRInstruction(){
	Instruction* lsr = (Instruction*) malloc(sizeof(Instruction));
	lsr->name = "LSR";
	lsr->modes_count = 5;
	lsr->modes = (MODES*) malloc(lsr->modes_count * sizeof(int));
	lsr->modes[0] = ACCUMULATOR;
	lsr->modes[1] = ZERO_PAGE;
	lsr->modes[2] = ZERO_PAGE_Y;
	lsr->modes[3] = ABSOLUTE;
	lsr->modes[4] = ABSOLUTE_Y;
	lsr->opcode = &opcode;
	return lsr;
}