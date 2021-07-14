#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <math.h>
void main() {
	//          Ctrl + K + U -to remove //'notes'
//                                          Question 1
	//int x;
	//printf("Enter number: ");
	//scanf_s("%d", &x);
	//if (x < 0)  x = x * (-1);
	//printf("\nAbsoulte number is %d", x);
//                                         Question 2
	//double price, total;
	//int quan;
	//printf("Enter price: ");
	//scanf_s("%lf", &price);
	//printf("\nEnter quantity: ");
	//scanf_s("%d", &quan);
	//if (quan >= 50) price = price * 0.5;
	//if (quan > 25 && quan < 50) price = price * 0.8;
	//if (quan > 10 && quan < 25) price = price * 0.95;
	//printf("\nThe total is: %lf", ((double)quan*price));
                                                        //Question 3 ??????????
	//int x;
	//printf("Enter number: ");
	//scanf_s("%d", &x);
	//if (x % 2 == 0 && x % 3 == 0 && x % 5 != 0)  printf("Valid Number");
	//else if (x % 2 != 0 && x % 7 != 0 && x % 11 != 0) printf("Valid Number");
	//else
	//	printf("Invalid Number");
	//                                                   Question 4
	//int x,y,z;
	//printf("Enter first number: ");
	//scanf_s("%d", &x);
	//printf("\nEnter second number: ");
	//scanf_s("%d", &y);
	//printf("\nEnter third number: ");
	//scanf_s("%d", &z);
	//if ((y%x==0 || x % y ==0) && (z%x == 0 || x%z==0) && (z%y==0 || y%z==0)) printf("Valid Numbers");
	//else
	//	printf("Invalid Numbers");
	//                                                   Question 5
	//SYSTEMTIME t;
	//GetLocalTime(&t);
	//int birthday,birthmonth,birthyear,age;
	//printf("Enter birth day: ");
	//scanf_s("%d", &birthday);
	//printf("\nEnter birth month: ");
	//scanf_s("%d", &birthmonth);
	//printf("\nEnter birth year: ");
	//scanf_s("%d", &birthyear);
	//if ((t.wMonth>birthmonth) || ((t.wMonth == birthmonth) && (t.wDay >= birthday))) age = (t.wYear - birthyear) ;
	//else age = (t.wYear - birthyear) -1;
	//printf("\nYou are %d", age);
	//printf(" years old.");
//                                                         Question 6
	//int x,y;
	//printf("Enter first number: ");
	//scanf_s("%d", &x);
	//printf("\nEnter second number: ");
	//scanf_s("%d", &y);
	//if (x > 0 && y > 0) printf("(%d,%d) is in Quadrant 1(+,+)", x, y);
	//else if (x < 0 && y > 0) printf("(%d,%d) is in Quadrant 2(-,+)", x, y);
	//else if (x < 0 && y < 0) printf("(%d,%d) is in Quadrant 3(-,-)", x, y);
	//else if (x > 0 && y < 0) printf("(%d,%d) is in Quadrant 4(+,-)", x, y);
	//else printf("(%d,%d) is on the line" , x ,y);
	//                                                        Question 7
	//int x1,x2,y1,y2;
	//double num;
	//printf("Enter x1: ");
	//scanf_s("%d", &x1);
	//printf("\nEnter x2: ");
	//scanf_s("%d", &x2);
	//printf("\nEnter y1: ");
	//scanf_s("%d", &y1);
	//printf("\nEnter y2: ");
	//scanf_s("%d", &y2);
	//num = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	//printf("The Distance between the 2 points is: %.3f", num);
	//                                                          Question 8
	//double a, b, c;
	//double x1,x2;
	//printf("Enter a: ");
	//scanf_s("%lf", &a);
	//printf("\nEnter b: ");
	//scanf_s("%lf", &b);
	//printf("\nEnter c: ");
	//scanf_s("%lf", &c);
	//x1 = ((-1.0)*b + (sqrt(pow(b, 2) - (4.0 * a*c))) )/ (2.0 * a);
	//x2 = ((-1.0)*b - (sqrt(pow(b, 2) - (4.0 * a*c))) )/ (2.0 * a);
	//if (!isnan(x1) && !isnan(x2))	printf("The answers are: %lf, %lf", x1, x2);
	//else printf("not an square eqaution");
	//                                                    Question 9      ????????????????
	double hypo, height;
	printf("Enter hypo: ");
	scanf_s("%lf", &hypo);
	printf("\nEnter height: ");
	scanf_s("%lf", &height);
	if ((hypo/2)>height)
		printf("S=%lf", (height*hypo) / 2.0);
	else
		printf("Illegal entry");
//                                                      Question 10
	//int birthday,birthmonth,birthyear;
	//printf("Enter birth day: ");
	//scanf_s("%d", &birthday);
	//printf("\nEnter birth month: ");
	//scanf_s("%d", &birthmonth);
	//printf("\nEnter birth year: ");
	//scanf_s("%d", &birthyear);
	//if ((birthmonth == 12 && birthday >= 22) || (birthmonth == 1 && birthday <= 20)) printf("Gdi");
	//else if ((birthmonth == 1 && birthday >= 21) || (birthmonth == 2 && birthday <= 18)) printf("Dli");
	//else if ((birthmonth == 2 && birthday >= 19) || (birthmonth == 2 && birthday <= 20)) printf("Dagim");
	//else if ((birthmonth == 3 && birthday >= 21) || (birthmonth == 4 && birthday <= 20)) printf("Tale");
	//else if ((birthmonth == 4 && birthday >= 21) || (birthmonth == 4 && birthday <= 20)) printf("Shor");
	//else if ((birthmonth == 5 && birthday >= 21) || (birthmonth == 6 && birthday <= 21)) printf("Teomim");
	//else if ((birthmonth == 6 && birthday >= 22) || (birthmonth == 7 && birthday <= 22)) printf("Sartan");
	//else if ((birthmonth == 7 && birthday >= 23) || (birthmonth == 8 && birthday <= 22)) printf("Arie");
	//else if ((birthmonth == 8 && birthday >= 23) || (birthmonth == 9 && birthday <= 22)) printf("Virgin");
	//else if ((birthmonth == 9 && birthday >= 23) || (birthmonth == 10 && birthday <= 23)) printf("Moznaim");
	//else if ((birthmonth == 10 && birthday >= 24) || (birthmonth == 11 && birthday <= 21)) printf("Akrab");
	//else  printf("Keshet");
}