#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case ACCUMULATOR: {
			return 0x6A;
		}case ZERO_PAGE: {
			return 0x66;
		}case ZERO_PAGE_X: {
			return 0x76;
		}case ABSOLUTE: {
			return 0x6E;
		}case ABSOLUTE_X: {
			return 0x7E;
		}default:{
			return -1;
		}
	}
}

Instruction* registerRORInstruction(){
	Instruction* ror = (Instruction*) malloc(sizeof(Instruction));
	ror->name = "ROR";
	ror->modes_count = 5;
	ror->modes = (MODES*) malloc(ror->modes_count * sizeof(int));
	ror->modes[0] = ACCUMULATOR;
	ror->modes[1] = ZERO_PAGE;
	ror->modes[2] = ZERO_PAGE_X;
	ror->modes[3] = ABSOLUTE;
	ror->modes[4] = ABSOLUTE_X;
	ror->opcode = &opcode;
	return ror;
}