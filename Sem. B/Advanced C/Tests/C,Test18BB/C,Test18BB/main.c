#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char* Question3(char** Arrstr, int n) {
	char* str = (char*) calloc(30,sizeof(char));
	int spacetojump, count = 0;
	int i = 0,j=0;
	for (i = 0; i < n; i++) {
		j = 0;
		spacetojump = i;
		while (spacetojump > 0) {
			while (Arrstr[i][j] != 32) {
				j++;
			}
			while (Arrstr[i][j] == 32) {
				j++;
			}
			spacetojump--;
		}
		while (j < strlen(Arrstr[i]) && Arrstr[i][j] != 32) {
			str[count++] = Arrstr[i][j++];
		}
		str[count++] = ' ';
	}

	return str;
}


void main() {


	char** arrstr = (char**)calloc(4, sizeof(char*));
	arrstr[0] = "Mike   lives   in London";
	arrstr[1] = "Jim   found   three pounds";
	arrstr[2] = "Tom has   a brother";
	arrstr[3] = "Arthur   bought    this car";
	Question3(arrstr, 4);

	printf("-");
	
	puts("printf" - "printf" ? "printf-printf" : "puts-puts");
}