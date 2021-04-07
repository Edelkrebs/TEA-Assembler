#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case RELATIVE: {
			return 0x10;
		}default:{
			return -1;
		}
	}
}

Instruction* registerBPLInstruction(){
	Instruction* bpl = (Instruction*) malloc(sizeof(Instruction));
	bpl->name = "BPL";
	bpl->modes_count = 1;
	bpl->modes = (MODES*) malloc(bpl->modes_count * sizeof(int));
	bpl->modes[0] = RELATIVE;
	bpl->opcode = &opcode;
	return bpl;
}
