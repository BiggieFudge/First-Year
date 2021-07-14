#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void Question1(char* infile, char* outfile_true, char* outfile_false) {
	/*char buffer[1];
	FILE *fp = fopen(infile, "rb");
	FILE *outT = fopen(outfile_true, "wb");
	FILE *outF = fopen(outfile_false, "wb");
	if (fp==NULL)
		return;
	
	int* num=NULL;
	int sum = 0,i=0;
	while (fp) {
		
		sum = 0,i=0;
		while (fread(buffer,sizeof(buffer),1,fp)) {
			if (buffer[0] == 32) {
				break;
			}
			i++;
			sum += buffer[0];
		}
		
		fread(num, sizeof(int), 1, fp);

		fseek(fp, i + 4, SEEK_CUR);
		if (*num == sum){
			for (int k = 0; k < i; k++) {
				fread(buffer, sizeof(buffer), 1, fp);
				fwrite(buffer, sizeof(buffer), 1, outT);
			}
		}
			
		else{
			for (int k = 0; k < i; k++) {
				fread(buffer, sizeof(buffer), 1, fp);
				fwrite(buffer, sizeof(buffer), 1, outT);
			}
		}
		fread(&num, sizeof(int), 1, fp);
		
	}



	fclose(fp);
	fclose(outT);
	fclose(outF);*/
}
char* Question3(char* str) {

	char* newstr = (char*)calloc(strlen(str), sizeof(char));
	int j = strlen(str)-1;
	while (str[j] != 32) {
		if (j == 0) {
			return str;
		}
		j--;
	}
	j++;
	int i = 0;
	while (i < strlen(str)) {
		if (j == strlen(str)) {
			newstr[i++] = ' ';
			j = 0;
		}
		newstr[i++] = str[j++];
	}
	newstr[i] = '\0';


}
int x;

int f() {
	static int x;
	printf("%d", x);
	printf("%d", ++x);
}

typedef struct list {
	int data;
	int column;
	struct List* next;
}List;



void Question4(List** node, int colmus, int size) {

	int** A = (int**)calloc(size, sizeof(int*));
	int* row; 
	List* temp;

	for (int i = 0; i < size; i++) {
		row = (int*)calloc(colmus, sizeof(int));
		temp = node[i];
		while (temp) {
			row[temp->column] = temp->data;
			temp = temp->next;
		}
		A[i] = row;
	}

	return A;
}


int** push(List** list, int data,int column) {
	List* newlist = (List*)calloc(1, sizeof(List));
	newlist->column = column;
	newlist->data = data;
	newlist->next = NULL;
	List* temp = *list;
	if (*list==NULL) {
		*list = newlist;
	}
	else {
	while (temp->next!=NULL) {
		temp = temp->next;
	}
	temp->next = newlist;
}
}

typedef struct person {
	char* first_name;
	char* last_name;
	unsigned id;
}Person;


int Question2(Person* arr, int n) {
	int check;

	for (int i = 0; i < n - 1; i++) {
		check = strcmp(arr[i].last_name, arr[i + 1].last_name);

		if (check == 0) {
			check = strcmp(arr[i].first_name, arr[i + 1].first_name);
			if (arr[i].id > arr[i + 1].id)
				return 0;
		}
		if (check > 0)
			return 0;
	}
	return 1;
}



void main() {

	/*FILE *fp = fopen("infile.bin", "wb");
	char* str = (char*)calloc(15, sizeof(char));
	str = "abc 294\n";
	fwrite(str, strlen(str),1, fp);
	str = "3+2+1=6 352\n";
	fwrite(str, strlen(str), 1, fp);
	str = "A  65";
	fwrite(str, strlen(str), 1, fp);
	fclose(fp);

	Question1("infile.bin", "outfileT.bin", "outfileF.bin");

	Question3("Uno  Deusch  Troi");*/

	//printf("%d",  //prints 2
	//	printf("%d%d", //prints 22 
	//		/*returns 2<----*/printf("%d", 11), //prints 11 
	//		printf("%d", 11)//prints 11));


	//American Quesrtions
	/*f();
	printf("%d", x);
	printf("%d", ++x);
	f();*/
	/*int i = 64;
	for (; i; i >>= 1) {
		printf("Hi\n");
	}*/

	int x = 1;
	printf("%d", &x);
	List** list = (List**)calloc(4, sizeof(List*));
	List* temp = NULL;
	
	push(&temp, 4, 2);
	push(&temp, 7, 4);
	list[0] = temp;
	temp = NULL;
	push(&temp, 1, 1);
	list[1] = temp;
	temp = NULL;
	push(&temp, 2, 2);
	list[2] = temp;
	temp = NULL;
	push(&temp, 3, 3);
	list[3] = temp;
	temp = NULL;
	
	Question4(list, 5, 4);


	Person* arr = (Person*)calloc(4, sizeof(Person));
	arr[0].last_name = "Abc";
	arr[0].first_name = "Abc";
	arr[0].id=207207572;
	arr[1].last_name = "Bbc";
	arr[1].first_name = "Bbc";
	arr[1].id = 207207573;
	arr[2].last_name = "CcD";
	arr[2].first_name = "CcD";
	arr[2].id = 207207574;
	arr[3].last_name = "DdE";
	arr[3].first_name = "DdE";
	arr[3].id = 207207574;

	Question2(arr, 4);
}