#include <stdio.h>
#include <math.h>
void main() {
 //                           Question 1
	//double length;
	//printf("Enter length: ");
	//scanf_s("%lf", &length);
	//length = sqrt(2*(length*length));
	//printf("The slant length is: %lf", length);
//                                                     Question 2
//	double radius,pi = 3.14159265359;
//	printf("Enter radius: ");
//	scanf_s("%lf", &radius);
//	printf("\nVolume is : %lf", (((double)(4 / 3) * (radius*radius*radius)) * pi));
//	printf("\nParimeter is : %lf", (2.00*radius*pi));
//	printf("\nArea Is: %lf", (pi*(radius*radius)));
//                                                        Question 3
//	double a1, d,an;
//	int n;
//	printf("Enter a1: ");
//	scanf_s("%lf", &a1);
//	printf("\nEnter d: ");
//	scanf_s("%lf", &d);
//	printf("\nEnter n: ");
//	scanf_s("%d", &n);
//	printf("\n a%d", n);
//	an = a1 + d * (n - 1);
//	printf(" is : %.3f", (an));
//                                                           Question 4
//	printf("\nThe sum is: %.3f", ((((an+a1))*n)/2));
//                                                            Question 5
//	double a1, q, an;
//	int n;
//	printf("Enter a1: ");
//	scanf_s("%lf", &a1);
//	printf("\nEnter q: ");
//	scanf_s("%lf", &q);
//	printf("\nEnter n: ");
//	scanf_s("%d", &n);
//	printf("\n a%d", n);
//	printf(" is : %.3f", (a1*(pow(q, n - 1))));
//                                                   Question 6
//	double sum = ((a1 * ((pow(q, n)-1)) )/ (q-1));
//	printf("\nThe sum is: %.3f", sum);
//                                                  Question 7
	//int num,a1,a2,a3,sum;
	//printf("Enter 3 digits number: ");
	//scanf_s("%d", &num);
	//a3 = num / 100;
	//a2 = (num - (a3 * 100)) / 10;
	//a1 = (num - (a3 * 100)) - (a2 * 10);
	//sum = pow(a1, 2) + pow(a2, 2) + pow(a3, 2);
	//printf("\nThe sum is: %d", sum);
	//                                              Question 8
	//double d,x;
	//printf("Enter number ");
	//scanf_s("%lf", &d);
	//x = d - (int)d;
	//printf("\nD: %.2f", x);
	//                                              Question 9
	double wage, comp, total;
	printf("Enter wage ");
	scanf_s("%lf", &wage);
	printf("\nEnter comp ");
	scanf_s("%lf", &comp);
	total = (0.75 * wage) + (0.10 * comp);
	total = ceil(total);
	printf("\nThe total is: %d", (int)total);
}