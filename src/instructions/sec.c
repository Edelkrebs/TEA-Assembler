#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0x38;
		}default:{
			return -1;
		}
	}
}

Instruction* registerSECInstruction(){
	Instruction* sec = (Instruction*) malloc(sizeof(Instruction));
	sec->name = "SEC";
	sec->modes_count = 1;
	sec->modes = (MODES*) malloc(sec->modes_count * sizeof(int));
	sec->modes[0] = IMPLIED;
	sec->opcode = &opcode;
	return sec;
}
