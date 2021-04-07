#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case RELATIVE: {
			return 0xB0;
		}default:{
			return -1;
		}
	}
}

Instruction* registerBCSInstruction(){
	Instruction* bcs = (Instruction*) malloc(sizeof(Instruction));
	bcs->name = "BCS";
	bcs->modes_count = 1;
	bcs->modes = (MODES*) malloc(bcs->modes_count * sizeof(int));
	bcs->modes[0] = RELATIVE;
	bcs->opcode = &opcode;
	return bcs;
}
