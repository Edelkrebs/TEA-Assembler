#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMMEDIATE: {
			return 0xA2;
		}case ZERO_PAGE: {
			return 0xA6;
		}case ZERO_PAGE_Y: {
			return 0xB6;
		}case ABSOLUTE: {
			return 0xAE;
		}case ABSOLUTE_Y: {
			return 0xBE;
		}default:{
			return -1;
		}
	}
}

Instruction* registerLDXInstruction(){
	Instruction* ldx = (Instruction*) malloc(sizeof(Instruction));
	ldx->name = "LDX";
	ldx->modes_count = 8;
	ldx->modes = (MODES*) malloc(ldx->modes_count * sizeof(int));
	ldx->modes[0] = IMMEDIATE;
	ldx->modes[1] = ZERO_PAGE;
	ldx->modes[2] = ZERO_PAGE_Y;
	ldx->modes[3] = ABSOLUTE;
	ldx->modes[4] = ABSOLUTE_Y;
	ldx->opcode = &opcode;
	return ldx;
}