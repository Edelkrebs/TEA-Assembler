#ifndef __PARSER_H
#define __PARSER_H

#include <stdint.h>
#include <instruction/instruction.h>

uint16_t line_number;

void error(const char* message);
uint16_t getArgument(const char* line, MODES mode);
MODES getMode(const char* argument);
void parse_line(const char* line);

#endif