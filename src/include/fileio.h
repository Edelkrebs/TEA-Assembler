#ifndef __FILEIO_H
#define __FILEIO_H

#include <stdint.h>

char file_buffer[8192][8192];
uint32_t line_count;

void readFileToBuffer(const char* file_name);

#endif