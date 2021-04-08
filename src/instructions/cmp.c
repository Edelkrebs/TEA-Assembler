#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMMEDIATE: {
			return 0xC9;
		}case ZERO_PAGE: {
			return 0xC5;
		}case ZERO_PAGE_X: {
			return 0xD5;
		}case ABSOLUTE: {
			return 0xCD;
		}case ABSOLUTE_X: {
			return 0xDD;
		}case ABSOLUTE_Y: {
			return 0xD9;
		}case INDIRECT_X: {
			return 0xC1;
		}case INDIRECT_Y: {
			return 0xD1;
		}default:{
			return -1;
		}
	}
}

Instruction* registerCMPInstruction(){
	Instruction* cmp = (Instruction*) malloc(sizeof(Instruction));
	cmp->name = "CMP";
	cmp->modes_count = 8;
	cmp->modes = (MODES*) malloc(cmp->modes_count * sizeof(int));
	cmp->modes[0] = IMMEDIATE;
	cmp->modes[1] = ZERO_PAGE;
	cmp->modes[2] = ZERO_PAGE_X;
	cmp->modes[3] = ABSOLUTE;
	cmp->modes[4] = ABSOLUTE_X;
	cmp->modes[5] = ABSOLUTE_Y;
	cmp->modes[6] = INDIRECT_X;
	cmp->modes[7] = INDIRECT_Y;
	cmp->opcode = &opcode;
	return cmp;
}