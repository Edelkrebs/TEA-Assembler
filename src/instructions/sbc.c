#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMMEDIATE: {
			return 0xE9;
		}case ZERO_PAGE: {
			return 0xE5;
		}case ZERO_PAGE_X: {
			return 0xF5;
		}case ABSOLUTE: {
			return 0xED;
		}case ABSOLUTE_X: {
			return 0xFD;
		}case ABSOLUTE_Y: {
			return 0xF9;
		}case INDIRECT_X: {
			return 0xE1;
		}case INDIRECT_Y: {
			return 0xF1;
		}default:{
			return -1;
		}
	}
}

Instruction* registerSBCInstruction(){
	Instruction* sbc = (Instruction*) malloc(sizeof(Instruction));
	sbc->name = "SBC";
	sbc->modes_count = 8;
	sbc->modes = (MODES*) malloc(sbc->modes_count * sizeof(int));
	sbc->modes[0] = IMMEDIATE;
	sbc->modes[1] = ZERO_PAGE;
	sbc->modes[2] = ZERO_PAGE_X;
	sbc->modes[3] = ABSOLUTE;
	sbc->modes[4] = ABSOLUTE_X;
	sbc->modes[5] = ABSOLUTE_Y;
	sbc->modes[6] = INDIRECT_X;
	sbc->modes[7] = INDIRECT_Y;
	sbc->opcode = &opcode;
	return sbc;
}