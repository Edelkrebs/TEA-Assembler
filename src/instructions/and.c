#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMMEDIATE: {
			return 0x29;
		}case ZERO_PAGE: {
			return 0x25;
		}case ZERO_PAGE_X: {
			return 0x35;
		}case ABSOLUTE: {
			return 0x2D;
		}case ABSOLUTE_X: {
			return 0x3D;
		}case ABSOLUTE_Y: {
			return 0x39;
		}case INDIRECT_X: {
			return 0x21;
		}case INDIRECT_Y: {
			return 0x31;
		}default:{
			return -1;
		}
	}
}

Instruction* registerANDInstruction(){
	Instruction* and = (Instruction*) malloc(sizeof(Instruction));
	and->name = "AND";
	and->modes_count = 8;
	and->modes = (MODES*) malloc(and->modes_count * sizeof(int));
	and->modes[0] = IMMEDIATE;
	and->modes[1] = ZERO_PAGE;
	and->modes[2] = ZERO_PAGE_X;
	and->modes[3] = ABSOLUTE;
	and->modes[4] = ABSOLUTE_X;
	and->modes[5] = ABSOLUTE_Y;
	and->modes[6] = INDIRECT_X;
	and->modes[7] = INDIRECT_Y;
	and->opcode = &opcode;
	return and;
}
