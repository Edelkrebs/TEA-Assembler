#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case IMMEDIATE: {
			return 0xA9;
		}case ZERO_PAGE: {
			return 0xA5;
		}case ZERO_PAGE_X: {
			return 0xB5;
		}case ABSOLUTE: {
			return 0xAD;
		}case ABSOLUTE_X: {
			return 0xBD;
		}case ABSOLUTE_Y: {
			return 0xB9;
		}case INDIRECT_X: {
			return 0xA1;
		}case INDIRECT_Y: {
			return 0xB1;
		}default:{
			return -1;
		}
	}
}

Instruction* registerLDAInstruction(){
	Instruction* lda = (Instruction*) malloc(sizeof(Instruction));
	lda->name = "LDA";
	lda->modes_count = 8;
	lda->modes = (MODES*) malloc(lda->modes_count * sizeof(int));
	lda->modes[0] = IMMEDIATE;
	lda->modes[1] = ZERO_PAGE;
	lda->modes[2] = ZERO_PAGE_X;
	lda->modes[3] = ABSOLUTE;
	lda->modes[4] = ABSOLUTE_X;
	lda->modes[5] = ABSOLUTE_Y;
	lda->modes[6] = INDIRECT_X;
	lda->modes[7] = INDIRECT_Y;
	lda->opcode = &opcode;
	return lda;
}