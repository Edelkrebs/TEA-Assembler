#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case ACCUMULATOR: {
			return 0x2A;
		}case ZERO_PAGE: {
			return 0x26;
		}case ZERO_PAGE_X: {
			return 0x36;
		}case ABSOLUTE: {
			return 0x2E;
		}case ABSOLUTE_X: {
			return 0x3E;
		}default:{
			return -1;
		}
	}
}

Instruction* registerROLInstruction(){
	Instruction* rol = (Instruction*) malloc(sizeof(Instruction));
	rol->name = "ROL";
	rol->modes_count = 5;
	rol->modes = (MODES*) malloc(rol->modes_count * sizeof(int));
	rol->modes[0] = ACCUMULATOR;
	rol->modes[1] = ZERO_PAGE;
	rol->modes[2] = ZERO_PAGE_X;
	rol->modes[3] = ABSOLUTE;
	rol->modes[4] = ABSOLUTE_X;
	rol->opcode = &opcode;
	return rol;
}