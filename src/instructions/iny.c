#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0xC8;
		}default:{
			return -1;
		}
	}
}

Instruction* registerINYInstruction(){
	Instruction* iny = (Instruction*) malloc(sizeof(Instruction));
	iny->name = "INY";
	iny->modes_count = 1;
	iny->modes = (MODES*) malloc(iny->modes_count * sizeof(int));
	iny->modes[0] = IMPLIED;
	iny->opcode = &opcode;
	return iny;
}