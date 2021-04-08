#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case ZERO_PAGE: {
			return 0x85;
		}case ZERO_PAGE_X: {
			return 0x95;
		}case ABSOLUTE: {
			return 0x8D;
		}case ABSOLUTE_X: {
			return 0x9D;
		}case ABSOLUTE_Y: {
			return 0x99;
		}case INDIRECT_X: {
			return 0x81;
		}case INDIRECT_Y: {
			return 0x91;
		}default:{
			return -1;
		}
	}
}

Instruction* registerSTAInstruction(){
	Instruction* sta = (Instruction*) malloc(sizeof(Instruction));
	sta->name = "STA";
	sta->modes_count = 8;
	sta->modes = (MODES*) malloc(sta->modes_count * sizeof(int));
	sta->modes[0] = IMMEDIATE;
	sta->modes[1] = ZERO_PAGE;
	sta->modes[2] = ZERO_PAGE_X;
	sta->modes[3] = ABSOLUTE;
	sta->modes[4] = ABSOLUTE_X;
	sta->modes[5] = ABSOLUTE_Y;
	sta->modes[6] = INDIRECT_X;
	sta->modes[7] = INDIRECT_Y;
	sta->opcode = &opcode;
	return sta;
}