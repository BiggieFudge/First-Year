#include <stdio.h>
#include <stdlib.h>
#include "tstStruct.h"
#include <assert.h>

int* Input_Data(int num) {
	int* arr = (int*)calloc(num, sizeof(int));
	assert(arr);
	for (int i = 0; i < num; i++){
		printf("Enter arr[%d]:  ", i);
		scanf_s("%d", &arr[i]);
	}
	return arr;
}



double Student_Average(int* arr,int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	return ((double)(sum) / (double)n);
}

double Total_Average(double *arr,int n) {
	double sum = 0;
	for (int i = 0; i < n; i++){
		sum += arr[i];
	}
	return ((double)(sum) / (double)n);
}


void Classification(student_init_data sid[], statistics* s1,int n) {
	double* student_average = (double*)calloc(n, sizeof(double));
	student_processed_data* spd1 = (student_processed_data*)calloc(n, sizeof(student_processed_data));
	student_processed_data* spd2 = (student_processed_data*)calloc(n, sizeof(student_processed_data));
	int i1 = 0, i2 = 0;
for (int i = 0; i < n; i++){
		student_average[i] = Student_Average(sid[i].testsheet,sid[i].numoftest);
	}
	double avg = Total_Average(student_average,n);
	for (int i = 0; i < n; i++){
		if (student_average[i] >= avg) {
			spd1[i1].id = sid[i].id;
			spd1[i1].avg = student_average[i];
			i1++;
		}
		else {
			spd2[i2].id = sid[i].id;
			spd2[i2].avg = student_average[i];
			i2++;
		}
	}
	s1->avgtotal = avg;
	s1->n1 = i1;
	s1->n2 = i2;
	s1->spd1 = spd1;
	s1->spd2 = spd2;
	return;
}



void Print_Tab(statistics s1) {
	printf("avg total is:%lf\n", s1.avgtotal);
	printf("Students above avg:\n");
	for (int i = 0; i < s1.n1; i++){
		printf("spd[%d]=%lf\n", i, s1.spd1[i].avg);
	}
	printf("Students below avg:\n");
	for (int i = 0; i < s1.n2; i++) {
		printf("spd[%d]=%lf\n", i, s1.spd2[i].avg);
	}
}

void Free_Memory(statistics s1,student_init_data* sarr,int n) {
	for (int i = 0; i < n; i++){
		free(sarr[i].testsheet);
	}
	free(s1.spd1);
	free(s1.spd2);

}