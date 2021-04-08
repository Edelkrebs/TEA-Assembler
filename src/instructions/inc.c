#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case ZERO_PAGE: {
			return 0xE6;
		}case ZERO_PAGE_X: {
			return 0xF6;
		}case ABSOLUTE: {
			return 0xEE;
		}case ABSOLUTE_X: {
			return 0xFE;
		}default:{
			return -1;
		}
	}
}

Instruction* registerINCInstruction(){
	Instruction* inc = (Instruction*) malloc(sizeof(Instruction));
	inc->name = "INC";
	inc->modes_count = 4;
	inc->modes = (MODES*) malloc(inc->modes_count * sizeof(int));
	inc->modes[0] = IMPLIED;
	inc->opcode = &opcode;
	return inc;
}