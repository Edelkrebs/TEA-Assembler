#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case ABSOLUTE: {
			return 0x6C;
		}case ABSOLUTE_INDIRECT: {
			return 0x4C;
		}default:{
			return -1;
		}
	}
}

Instruction* registerJMPInstruction(){
	Instruction* jmp = (Instruction*) malloc(sizeof(Instruction));
	jmp->name = "JMP";
	jmp->modes_count = 1;
	jmp->modes = (MODES*) malloc(jmp->modes_count * sizeof(int));
	jmp->modes[0] = ABSOLUTE;
	jmp->modes[1] = ABSOLUTE_INDIRECT;
	jmp->opcode = &opcode;
	return jmp;
}