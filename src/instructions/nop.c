#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0xEA;
		}default:{
			return -1;
		}
	}
}

Instruction* registerNOPInstruction(){
	Instruction* nop = (Instruction*) malloc(sizeof(Instruction));
	nop->name = "NOP";
	nop->modes_count = 1;
	nop->modes = (MODES*) malloc(nop->modes_count * sizeof(int));
	nop->modes[0] = IMPLIED;
	nop->opcode = &opcode;
	return nop;
}