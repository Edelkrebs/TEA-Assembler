#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0x68;
		}default:{
			return -1;
		}
	}
}

Instruction* registerPLAInstruction(){
	Instruction* pla = (Instruction*) malloc(sizeof(Instruction));
	pla->name = "PLA";
	pla->modes_count = 1;
	pla->modes = (MODES*) malloc(pla->modes_count * sizeof(int));
	pla->modes[0] = IMPLIED;
	pla->opcode = &opcode;
	return pla;
}