#include <fileio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFileToBuffer(const char* file_name){
	/*int line_index = 0;
	int index = 0; 											// Read the file into a 2D Buffer
	char* line_content = (char*) malloc(8192 * sizeof(char));
	for(index = 0; c != EOF; index++){ 		// With each line being represented
		c = fgetc(file);
		if(c == '\n'){ 						// By a line index and each position
			line_content[index] = '\0'; 		// In that line being represented by
			file_buffer[line_index] = line_content;
			line_content = (char*) malloc(8192 * sizeof(char));
			line_index++; 									// A index.
			index = 0; 										// If it hits 0, null terminate the line
			continue; 										// And begin reading the next one.
		} 									
		line_content[index] = c;				
		file_buffer[line_index] = line_content;										 			
	}*/
	FILE *file = fopen(file_name, "r");
	char *code;
	size_t n = 0;
	int c;
	
	if (file == NULL){
		printf("Couldn't find input file. Aborting.\n");
		exit(0);
	}
	
	code = malloc(8192);
	int line_index = 0;
	while ((c = fgetc(file)) != EOF){
		if((n == 0 && c == '\n') || (n == 0 && c == '\t') || (n == 0 && c == '\0') || (n == 0 && c == ' ')){
			n = 0;
			continue;		
		}
		if(c == '\n'){
			file_buffer[line_index] = code;
			code = malloc(8192);
			code[n + 1] = '\0';
			line_index++;
			n = 0;
			continue;
		}
		code[n++] = (char) c;
	}

	code[n + 1] = '\0';
	file_buffer[line_index] = code;
	line_count = line_index + 1;

	fclose(file);
}