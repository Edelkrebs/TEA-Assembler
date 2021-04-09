#ifndef __PARSER_H
#define __PARSER_H

#include <stdint.h>
#include <instruction/instruction.h>

uint16_t line_number;

typedef enum{
	PREPROCESSING,
	ASSEMBLING
} PARSING_STATE;

typedef enum{
	INSTRUCTION,
	VARIABLE,
	LABEL,
	DIRECTIVE,
	INVALID_LINE
} LINE_TYPE;

PARSING_STATE parsing_state;

void error(const char* message);
LINE_TYPE getLineType(const char* line);
uint16_t getArgument(const char* line, MODES mode);
MODES getMode(const char* argument);

void processInstruction(const char* without_whitespaces);
void processVariable(const char* without_whitespaces);
void processLabel(const char* without_whitespaces);
void processDirective(const char* without_whitespaces);

void parse_line(const char* line);

#endif