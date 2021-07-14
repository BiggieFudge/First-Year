#include <stdio.h>

typedef struct {
	int id;
	int* testsheet;
	int numoftest;
}student_init_data;

typedef struct {
	int id;
	double avg;
}student_processed_data;

typedef struct {
	student_processed_data* spd1;
	student_processed_data* spd2;
	int n1, n2;
	double avgtotal;
}statistics;
int* Input_Data(int num);
double Student_Average(int* arr,int n);
double Total_Average(double *arr,int n);
void Classification(student_init_data sid[], statistics* s1, int n);
void Print_Tab(statistics s1);
void Free_Memory(statistics s1, student_init_data* sarr,int n);