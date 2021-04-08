#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0xA8;
		}default:{
			return -1;
		}
	}
}

Instruction* registerTAYInstruction(){
	Instruction* tay = (Instruction*) malloc(sizeof(Instruction));
	tay->name = "TAY";
	tay->modes_count = 1;
	tay->modes = (MODES*) malloc(tay->modes_count * sizeof(int));
	tay->modes[0] = IMPLIED;
	tay->opcode = &opcode;
	return tay;
}