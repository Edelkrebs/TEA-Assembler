#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case ABSOLUTE: {
			return 0x20;
		}default:{
			return -1;
		}
	}
}

Instruction* registerJSRInstruction(){
	Instruction* jsr = (Instruction*) malloc(sizeof(Instruction));
	jsr->name = "JSR";
	jsr->modes_count = 1;
	jsr->modes = (MODES*) malloc(jsr->modes_count * sizeof(int));
	jsr->modes[0] = ABSOLUTE;
	jsr->modes[1] = ABSOLUTE_INDIRECT;
	jsr->opcode = &opcode;
	return jsr;
}