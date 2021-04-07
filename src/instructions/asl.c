#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case ACCUMULATOR: {
			return 0x0A;
		}case ZERO_PAGE: {
			return 0x06;
		}case ZERO_PAGE_X: {
			return 0x16;
		}case ABSOLUTE: {
			return 0x0E;
		}case ABSOLUTE_X: {
			return 0x1E;
		}default:{
			return -1;
		}
	}
}

Instruction* registerASLInstruction(){
	Instruction* asl = (Instruction*) malloc(sizeof(Instruction));
	asl->name = "ASL";
	asl->modes_count = 5;
	asl->modes = (MODES*) malloc(asl->modes_count * sizeof(int));
	asl->modes[0] = ACCUMULATOR;
	asl->modes[1] = ZERO_PAGE;
	asl->modes[2] = ZERO_PAGE_X;
	asl->modes[3] = ABSOLUTE;
	asl->modes[4] = ABSOLUTE_X;
	asl->opcode = &opcode;
	return asl;
}
