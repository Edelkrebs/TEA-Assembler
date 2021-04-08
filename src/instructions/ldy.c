#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMMEDIATE: {
			return 0xA0;
		}case ZERO_PAGE: {
			return 0xA4;
		}case ZERO_PAGE_Y: {
			return 0xB4;
		}case ABSOLUTE: {
			return 0xAC;
		}case ABSOLUTE_Y: {
			return 0xBC;
		}default:{
			return -1;
		}
	}
}

Instruction* registerLDYInstruction(){
	Instruction* ldy = (Instruction*) malloc(sizeof(Instruction));
	ldy->name = "LDY";
	ldy->modes_count = 8;
	ldy->modes = (MODES*) malloc(ldy->modes_count * sizeof(int));
	ldy->modes[0] = IMMEDIATE;
	ldy->modes[1] = ZERO_PAGE;
	ldy->modes[2] = ZERO_PAGE_Y;
	ldy->modes[3] = ABSOLUTE;
	ldy->modes[4] = ABSOLUTE_Y;
	ldy->opcode = &opcode;
	return ldy;
}