#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMPLIED: {
			return 0x08;
		}default:{
			return -1;
		}
	}
}

Instruction* registerPHPInstruction(){
	Instruction* php = (Instruction*) malloc(sizeof(Instruction));
	php->name = "PHP";
	php->modes_count = 1;
	php->modes = (MODES*) malloc(php->modes_count * sizeof(int));
	php->modes[0] = IMPLIED;
	php->opcode = &opcode;
	return php;
}