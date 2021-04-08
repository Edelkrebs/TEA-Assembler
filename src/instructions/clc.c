#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0x18;
		}default:{
			return -1;
		}
	}
}

Instruction* registerCLCInstruction(){
	Instruction* clc = (Instruction*) malloc(sizeof(Instruction));
	clc->name = "CLC";
	clc->modes_count = 1;
	clc->modes = (MODES*) malloc(clc->modes_count * sizeof(int));
	clc->modes[0] = IMPLIED;
	clc->opcode = &opcode;
	return clc;
}
