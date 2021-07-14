#include <stdio.h>
void main(){
//                                      Question 1
//	int currentyear = 2020, age;
//	printf("Enter your age\n");
//	scanf_s("%d", &age);
//	printf("The year you were born is: %d", currentyear - age);
//                                       Question 2
//	printf("*     *\n");
//	printf(" *   *\n");
//	printf("  * *\n");
//	printf("   *\n");
//	printf("  * *\n");
//	printf(" *   *\n");
//	printf("*     *\n");
//                                     Question 3
	//long idnum;
	//double wage;
	//int hoursaday, daysaweek, yearstart, yearend;
	//printf("Hello \nPlease enter id number\n");
	//scanf_s("%ld", &idnum);
	//printf("Enter your wage\n");
	//scanf_s("%lf", &wage);
	//printf("Enter how many hours you worked in a day\n");
	//scanf_s("%d", &hoursaday);
	//printf("Enter how many days you worked in a week\n");
	//scanf_s("%d", &daysaweek);
	//printf("Enter the year you finished working\n");
	//scanf_s("%d", &yearend);
	//printf("Enter the year you started working\n");
	//scanf_s("%d", &yearstart);
	//int years = yearend - yearstart;
	//double com = (double)years * ((wage * (double)hoursaday)* (double)daysaweek * 4.00);
	//printf("ID: %ld", idnum);
	//printf("\nyou should recieve: %.2f", com);
//                                 Question 4
//	int quana, quanb;
//	double pricea, priceb;
//	printf("Enter quantity and price for item A: \n");
//	scanf_s("%d", &quana);
//	scanf_s("%lf", &pricea);
//	printf("Enter quantity and price for item B: \n");
//	scanf_s("%d", &quanb);
//	scanf_s("%lf", &priceb);
//	double avg = (((double)quana*pricea) + ((double)quanb*priceb)) / (quana + quanb);
//	printf("Alice paid in average %lf", avg);
//	printf(" NIS per item");
//                                 Question 5
	double distance,speed,time;
	printf("Enter distance between cities.\n");
	scanf_s("%lf", &distance);
	printf("Enter car speed\n");
	scanf_s("%lf", &speed);
	time = distance / speed;
	printf("It will take the car: %lf", time);
	printf(" hours to get to point B");
}