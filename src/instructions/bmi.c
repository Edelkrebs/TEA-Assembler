#include <instruction/instruction.h>
#include <stdlib.h>

static uint8_t opcode(MODES mode){
	switch(mode){
		case RELATIVE: {
			return 0x30;
		}default:{
			return -1;
		}
	}
}

static uint8_t size(MODES mode){
	switch(mode){
		case RELATIVE: {
			return 2;
		}default:{
			return -1;
		}
	}
}

__attribute__((unused)) static uint8_t* decode_instruction(uint16_t argument, MODES mode){
	return generate_opcode_string(size(mode), mode, opcode(mode), argument);
}

Instruction* registerBMIInstruction(){
	Instruction* bmi = (Instruction*) malloc(sizeof(Instruction));
	bmi->name = "BMI";
	bmi->modes_count = 1;
	bmi->modes = (MODES*) malloc(bmi->modes_count * sizeof(int));
	bmi->modes[0] = RELATIVE;
	bmi->opcode = &opcode;
	bmi->size = &size;	
	bmi->decode_instruction = &decode_instruction;
	return bmi;
}
