#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case ZERO_PAGE: {
			return 0x84;
		}case ZERO_PAGE_X: {
			return 0x94;
		}case ABSOLUTE: {
			return 0x8C;
		}default:{
			return -1;
		}
	}
}

Instruction* registerSTYInstruction(){
	Instruction* sty = (Instruction*) malloc(sizeof(Instruction));
	sty->name = "STY";
	sty->modes_count = 3;
	sty->modes = (MODES*) malloc(sty->modes_count * sizeof(int));
	sty->modes[0] = ZERO_PAGE;
	sty->modes[1] = ZERO_PAGE_X;
	sty->modes[2] = ABSOLUTE;
	sty->opcode = &opcode;
	return sty;
}