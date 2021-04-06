#ifndef __INSTRUCTION_H
#define __INSTRUCTION_H

#define REGISTER_INSTRUCTION(x, y) extern Instruction* register##x##Instruction();\
								   	  instructionset[y] = register##x##Instruction();\

#include <stdint.h>
 
typedef enum{
	ACCUMULATOR,
	IMMEDIATE,
	ZERO_PAGE,
	ZERO_PAGE_X,
	ZERO_PAGE_Y,
	IMPLIED,
	RELATIVE,
	ABSOLUTE,
	ABSOLUTE_X,
	ABSOLUTE_Y,
	INDIRECT_X,
	INDIRECT_Y,
	ABSOLUTE_INDIRECT
} MODES;

typedef struct {
	const char* name;
	MODES* modes;
	uint8_t modes_count;
	uint8_t (*opcode)(MODES mode);
	uint8_t (*size)(MODES mode);
	uint8_t* (*decode_instruction)(uint16_t argument, MODES mode);
} Instruction;

Instruction* instructionset[255];

uint8_t* generate_opcode_string(uint8_t size, MODES mode, uint8_t opcode, uint16_t argument);
void initInstructionset();
Instruction* getInstruction(const char* name);

#endif