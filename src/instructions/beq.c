#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case RELATIVE: {
			return 0xF0;
		}default:{
			return -1;
		}
	}
}

Instruction* registerBEQInstruction(){
	Instruction* beq = (Instruction*) malloc(sizeof(Instruction));
	beq->name = "BEQ";
	beq->modes_count = 1;
	beq->modes = (MODES*) malloc(beq->modes_count * sizeof(int));
	beq->modes[0] = RELATIVE;
	beq->opcode = &opcode;
	return beq;
}
