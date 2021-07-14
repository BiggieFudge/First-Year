
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>




char** Question1(char* Sentence, char Letter,int* size) {


	char** LettersToReturn = NULL;
	

	int num = 0, i = 0,j=1;

	LettersToReturn = (char**)calloc(1, sizeof(char*));


	while (i < strlen(Sentence)) {
		
		if (Sentence[i] == Letter || Sentence[i]  == Letter -32) {
			num++;
			if (num > 1) {
				LettersToReturn = (char**)realloc(LettersToReturn, num * sizeof(char*));
			}
			j = 1;
			LettersToReturn[num - 1] = (char*)calloc(1, sizeof(char));
			while (Sentence[i] != 32) {
				if (j > 1)
					LettersToReturn[num - 1] = (char*)realloc(LettersToReturn[num - 1], j * sizeof(char));
				
				LettersToReturn[num - 1][j-1] = Sentence[i];
				
				
				i++; j++;

			}
			LettersToReturn[num - 1] = (char*)realloc(LettersToReturn[num - 1], (j) * sizeof(char));
			LettersToReturn[num - 1][j-1] = '\0';
			

		}
		else {
			i++;
		}
		
	}
	
	if (num == 0)
		return NULL;
	LettersToReturn = (char**)realloc(LettersToReturn, num * sizeof(char*));
	*size = num;
	return LettersToReturn;

}

void freeArray(int **a, int m) {
	int i;
	for (i = 0; i < m; ++i) {
		free(a[i]);
	}
	free(a);
}



char* Question2(char* Sentence) {
	char* str = NULL;
	int i = 0;
	int length = 0;
	
	while (i < strlen(Sentence)) {

		if ((Sentence[i] < 48 || Sentence[i] > 57) && Sentence[i] != 32) {
			str = (char*)realloc(str, (length + 1) * sizeof(char));
			str[length++] = Sentence[i];
	
		}
		i++;
	}
	str = (char*)realloc(str, (length + 1) * sizeof(char));
	str[length] = '\0';
	return str;
}

void createFile(char* filename) {
	FILE *file;

	fopen_s(&file, filename, "w+");

	char str[20];
	printf("Enter String to add to file(PRESS Ctrl+Z TO FINISH)\n");
	while (fgets(str, sizeof str, stdin)) {
	
		fprintf_s(file ,str);
		
		
	}
	fclose(file);
}


char commonestLetter(char* filename) {
	FILE *file;
	fopen_s(&file,filename, "r");
	int* numarr = (int*)calloc(26, sizeof(int));
	char c;
	int max=0,maxi=0;
	
	while (fscanf_s(file, " %c", &c) != EOF) {

		if (c >= 'A' && c <= 'Z') {
			numarr[c - 65]++;
		}
		else if (c >= 'a'&& c <= 'z') {
			numarr[c - 97]++;
		}
		
	}
	fclose(file);
	int i = 0;
	for (; i < 26; i++) {
		if ((numarr[i] != 0)&& (numarr[i] >= max)) {
			max = i;
			maxi = i;
		}
	}

	free(numarr);
	return maxi+64;
}


void main() {

	//Question 1
	/*int size =0;
	char** WordsToPrint = (char**)calloc(1, sizeof(char*));
	WordsToPrint = Question1("Rony Goodman got a good mark", 'g', &size);
	WordsToPrint = (char**)realloc(WordsToPrint, size * sizeof(char*));
	freeArray(WordsToPrint, size);*/

	//Question 2
	/*char* Print = Question2("123 Students & 5 Lectures");
	free(Print);*/


	//Question 3
	char ch;

	FILE *fp;
	
	createFile("input.txt");

	ch = commonestLetter("input.txt");
	if (ch)	printf("The commonest letter is %c", ch);
	else		printf("No letters in the file");

}