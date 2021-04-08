#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0xBA;
		}default:{
			return -1;
		}
	}
}

Instruction* registerTSXInstruction(){
	Instruction* tsx = (Instruction*) malloc(sizeof(Instruction));
	tsx->name = "TSX";
	tsx->modes_count = 1;
	tsx->modes = (MODES*) malloc(tsx->modes_count * sizeof(int));
	tsx->modes[0] = IMPLIED;
	tsx->opcode = &opcode;
	return tsx;
}