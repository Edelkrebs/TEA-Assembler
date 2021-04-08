#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0xE8;
		}default:{
			return -1;
		}
	}
}

Instruction* registerINXInstruction(){
	Instruction* inx = (Instruction*) malloc(sizeof(Instruction));
	inx->name = "INX";
	inx->modes_count = 1;
	inx->modes = (MODES*) malloc(inx->modes_count * sizeof(int));
	inx->modes[0] = IMPLIED;
	inx->opcode = &opcode;
	return inx;
}