#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case RELATIVE: {
			return 0xD0;
		}default:{
			return -1;
		}
	}
}

Instruction* registerBNEInstruction(){
	Instruction* bne = (Instruction*) malloc(sizeof(Instruction));
	bne->name = "BNE";
	bne->modes_count = 1;
	bne->modes = (MODES*) malloc(bne->modes_count * sizeof(int));
	bne->modes[0] = RELATIVE;
	bne->opcode = &opcode;
	return bne;
}
