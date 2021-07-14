#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include<assert.h>
void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();
void Ex6();
void Ex7();
void Ex7();
void Ex8();
void Ex9();
void Ex10();
int IsS1inS2(char* , char* );
int Fermuchia(char*, char*);
char* Tzimzum(char*);
char* fun4(char*);
int isPali(char*);
char* MinicharstoPali(char*, int *);
int IsIdentical(char*,char*);
char* StringFrom(char*, int, int);
int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 10; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-10 : ");
				scanf_s("%d", &select);
			} while ((select < 0) || (select > 11));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			case 6: Ex6(); break;
			case 7: Ex7(); break;
			case 8: Ex8(); break;
			case 9: Ex9(); break;
			case 10: Ex10(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}



void Ex1() {
	char s1[20],s2[20];
	printf("Enter S1:\n");
	scanf_s(" %[^\n]s", s1, sizeof(s1) - 1);
	printf("Enter S2:\n");
	scanf_s(" %[^\n]s", s2, sizeof(s2) - 1);
	printf("Function returned:%d\n", IsS1inS2(s1, s2));
}

int IsS1inS2(char* s1, char* s2) {
	int* Counter = (int*)calloc(strlen(s1), sizeof(int));
	int i=0,index = 0;
	while (i < strlen(s1)) {
		if (index == strlen(s2)) {
			index = 0;
			i++;
		}
		if (s1[i] == s2[index]) {
			s2[index] = 0;
			Counter[i]=1;
			index = -1;
			i++;
		}
		index++;
	}
	for (int i = 0; i < strlen(s1); i++) {
		if (Counter[i] == 0)
			return 0;
	}
	return 1;
}


void Ex2() {
	char s1[20], s2[20];
	printf("Enter S1:\n");
	scanf_s(" %[^\n]s", s1, sizeof(s1) - 1);
	printf("Enter S2:\n");
	scanf_s(" %[^\n]s", s2, sizeof(s2) - 1);
	printf("Function returned:%d\n", Fermuchia(s1, s2));

}
int Fermuchia(char* s1, char* s2) {
	int Is1 = 0,Is2=0;
	while (Is1 < strlen(s1)) {
		if (Is2 > strlen(s2)) {
			return 0;
		}
		if (s1[Is1] == s2[Is2]) {
			s2[Is2] = ' ';
			Is1++;
			Is2 = -1;
		}
		Is2++;
	}
	for (Is2 = 0; Is2 < strlen(s2); Is2++) {
		if (s2[Is2] != ' ')
			return 0;
	}
	return 1;

}
void Ex3() {
	char s1[30];
	printf("Enter S1:\n");
	scanf_s(" %[^\n]s", s1, sizeof(s1) - 1);
	Tzimzum(s1);
}

char* Tzimzum(char* s1) {
	int i = 0;
	char previous = '0';
	while (i < strlen(s1)) {
		while (s1[i] != previous) {
			previous = s1[i];
			i++;
		}
		for (int j = i; j < strlen(s1); j++) {
			s1[j] = s1[j + 1];
		}
		
	}
	puts(s1);
	return s1;

}
void Ex4() {
	char str[30];
	printf("Enter S1:\n");
	scanf_s(" %[^\n]s", str , sizeof(str) - 1);
	printf("Function Returned:");
	puts(fun4(str));
}

char* fun4(char* str) {
	int index1 = 0, index2 = 1,count=0,saveindex2;
	while (index1 < strlen(str)) {
		if (str[index1] == str[index2]) {
			while (str[index1] == str[index2]) {
				count++;
				index2++;
			}
			saveindex2 = index2;
			str[index1 + 1] = count + 49;
			for (int i = index1 + 2; i < strlen(str) && count > 1; i++)
			{
				str[i] = str[saveindex2];
				saveindex2++;
			}
			index1 += 2;
			index2 = index1+1;
			count = 0;
		}
		else {
			index1++;
			index2++;
		}



		
	}
	return str;
}
void Ex5() {
	char str[30];
	printf("Enter String to check for palindrome (Only lower Case plox):\n");
	scanf_s(" %[^\n]s", str, sizeof(str) - 1);
	printf("Function Returned:%d", isPali(str));

}


int isPali(char* str) {
	int* counter=(int*) calloc (26,sizeof(int));
	int index = 0;
	int whereincounter;
	while (index < strlen(str)) {
		whereincounter = str[index] - 'a';
		counter[whereincounter]++;
		index++;
	}
	int one = 0;
	for (int i = 0; i < 26; i++){
		while (counter[i] == 0 && i<26)
			i++;
		if (counter[i] % 2 == 1)
			one++;
		if (one > 1 || strlen(str)<2)
			return 0;
	}
	return 1;



}
void Ex6() {
	char str[30];
	int n = 0;
	printf("Enter String to check for palindrome (Only lower Case plox):\n");
	scanf_s(" %[^\n]s", str, sizeof(str) - 1);
	printf("Function Returned:{");
	puts(MinicharstoPali(str, &n));
	printf("And:%d\n",n);
}

char* MinicharstoPali(char* str,int *n) {
	int* counter = (int*)calloc(26, sizeof(int));
	assert(counter);
	int index = 0;
	int whereincounter;
	while (index < strlen(str)) {
		whereincounter = str[index] - 'a';
		counter[whereincounter]++;
		index++;
	}
	char*  CharToremove = (char*) calloc(25,sizeof(char));
	int HowManyToRemove=0,max=0,maxl=0;
	index = 0;
	for (int i = 0; i < 26; i++) {
		if (counter[i] % 2 == 1) {
			CharToremove[index] = (i + 'a') ;
			index++;
			CharToremove[index]= ',';
			index++;
			HowManyToRemove+= counter[i];
			if (max < counter[i]) {
			max = counter[i];
			maxl = index-2;
		}
		}
		
	}
	if (max != 0) {
		HowManyToRemove-=max;
		CharToremove[maxl] = '$';
	}
	CharToremove[index-1] = '}';
	*n = HowManyToRemove;
	return CharToremove;

}




void Ex7() {
	char str1[30],str2[30];
	int n = 0;
	printf("Enter String to check for palindrome (Only lower Case plox):\n");
	scanf_s(" %[^\n]s", str1, sizeof(str1) - 1);
	printf("Enter String to check for palindrome (Only lower Case plox):\n");
	scanf_s(" %[^\n]s", str2, sizeof(str2) - 1);
	printf("Function Returned:%d\n",IsIdentical(str1,str2));
}
int IsIdentical(char* str1,char* str2) {
	for (int i = 0; i < strlen(str1); i++){
		if (tolower(str1[i]) != tolower(str2[i]))
			return 0;
	}
	return 1;
}

void Ex8() {
	char str[30];
	int index,length;
	printf("Enter String:\n");
	scanf_s(" %[^\n]s", str, sizeof(str) - 1);
	printf("Enter index:\n");
	scanf_s("%d", &index);
	printf("Enter length:\n");
	scanf_s("%d", &length);
	printf("Function Returned:");
	puts(StringFrom(str, index, length));
}
char* StringFrom(char* str, int index, int lengh) {
	char* StringToreturn=(char*) calloc(30,sizeof(char));
	assert(StringToreturn);
	int j = 0;
	for (int i = index; i < index+lengh; i++){
		if (i == strlen(str)) {
			StringToreturn = "NULL";
			break;
		}
		StringToreturn[j] = str[i];
		j++;
	}
	return StringToreturn;
}
void Ex9(){

}
void Ex10(){}