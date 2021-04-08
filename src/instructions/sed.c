#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0xF8;
		}default:{
			return -1;
		}
	}
}

Instruction* registerSEDInstruction(){
	Instruction* sed = (Instruction*) malloc(sizeof(Instruction));
	sed->name = "SED";
	sed->modes_count = 1;
	sed->modes = (MODES*) malloc(sed->modes_count * sizeof(int));
	sed->modes[0] = IMPLIED;
	sed->opcode = &opcode;
	return sed;
}
