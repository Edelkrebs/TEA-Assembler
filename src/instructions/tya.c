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

Instruction* registerTYAInstruction(){
	Instruction* tya = (Instruction*) malloc(sizeof(Instruction));
	tya->name = "TYA";
	tya->modes_count = 1;
	tya->modes = (MODES*) malloc(tya->modes_count * sizeof(int));
	tya->modes[0] = IMPLIED;
	tya->opcode = &opcode;
	return tya;
}