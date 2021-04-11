#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case RELATIVE: {
			return 0x50;
		}default:{
			return -1;
		}
	}
}

Instruction* registerBVCInstruction(){
	Instruction* bvc = (Instruction*) malloc(sizeof(Instruction));
	bvc->name = "BVC";
	bvc->modes_count = 2;
	bvc->modes = (MODES*) malloc(bvc->modes_count * sizeof(int));
	bvc->modes[0] = RELATIVE;
	bvc->opcode = &opcode;
	return bvc;
}
