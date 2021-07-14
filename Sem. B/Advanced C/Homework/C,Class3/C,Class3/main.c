#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include "tstStruct.h"
void printarray(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("\narr[%d]=%d", i, arr[i]);
	}
}



void main() {
	student_init_data sarr[3];
	for (int i = 0; i < 3; i++){
		printf("Student num:%d\n", i+1);
		printf("Enter ID:");
		scanf_s("%d", &sarr[i].id);
		printf("Enter num of tests:");
		scanf_s("%d", &sarr[i].numoftest);
		sarr[i].testsheet = Input_Data(sarr[i].numoftest);
	}
	statistics s1;
	Classification(sarr, &s1,3);
	Print_Tab(s1);
	Free_Memory(s1,sarr,3);


}