#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case RELATIVE: {
			return 0x90;
		}default:{
			return -1;
		}
	}
}

Instruction* registerBCCInstruction(){
	Instruction* bcc = (Instruction*) malloc(sizeof(Instruction));
	bcc->name = "BCC";
	bcc->modes_count = 1;
	bcc->modes = (MODES*) malloc(bcc->modes_count * sizeof(int));
	bcc->modes[0] = RELATIVE;
	bcc->opcode = &opcode;
	return bcc;
}
