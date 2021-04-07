#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0x00;
		}default:{
			return -1;
		}
	}
}

Instruction* registerBRKInstruction(){
	Instruction* brk = (Instruction*) malloc(sizeof(Instruction));
	brk->name = "BRK";
	brk->modes_count = 1;
	brk->modes = (MODES*) malloc(brk->modes_count * sizeof(int));
	brk->modes[0] = IMPLIED;
	brk->opcode = &opcode;
	return brk;
}
