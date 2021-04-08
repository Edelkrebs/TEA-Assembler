#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0xD8;
		}default:{
			return -1;
		}
	}
}

Instruction* registerCLDInstruction(){
	Instruction* cld = (Instruction*) malloc(sizeof(Instruction));
	cld->name = "CLD";
	cld->modes_count = 1;
	cld->modes = (MODES*) malloc(cld->modes_count * sizeof(int));
	cld->modes[0] = IMPLIED;
	cld->opcode = &opcode;
	return cld;
}
