#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void main() {
	//                                        Question 1
	/*int n;
	printf("Enter Number: ");
	scanf_s("%d", &n);
	for (int i=1; i <= n ;i++){
		if (i % 15 == 0) printf("\nFizzBuzz");
		else if (i % 5 == 0) printf("\nBuzz");
		else if (i % 3 == 0) printf("\nFizz");
		else printf("\n%d", i);
	}*/

	//                                           Question 2
	/*int x;
	double n;
	printf("Enter Number between 0 and 1000 : ");
	scanf_s("%lf", &n);
	x = ((int)(n / 25))*25;
	printf("(%d,%d]", x, x+25);*/
	
	//                                              Question 3
	/*int money;
	printf("Enter how much you want to change : ");
	scanf_s("%d", &money);
	printf("\n%d  , 20 NIS", money / 20);
	money = money -20*(money / 20);
	printf("\n%d  , 10 NIS", money / 10);
	money = money - 10*(money / 10);
	printf("\n%d  , 5 NIS", money / 5);
	money = money - 5*(money / 5);
	printf("\n%d  , 2 NIS", money / 2);
	money = money - 2*(money / 2);
	printf("\n%d  , 1 NIS", money);
*/
//                                            Question 4
	/*int n, x,sum=0;
	printf("Enter n : ");
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		printf("Enter num: ");
		scanf_s("%d", &x);
		if (x % 3 == 0) sum = sum + x;
	}
	printf("\nThe Sum is:%d", sum);
	*/
	//                                          Question 5
	/*int n,acheret=1,sum=0, x = 1;
	printf("Enter n: ");
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {

		sum = sum + (x);
		acheret = acheret * (x);
		x=x+1;
	}

	printf("\nResult is:%lf", (double)acheret/sum );
	*/
	//                                                   Question 6
	/*int num, high, low, sum=0;
	printf("Enter number: ");
	scanf_s("%d", &num);
	if (num == -1) {
		printf("No Numbers entered"); 
		return 0;}
	else {
		high = num;
		low = num;}
	while (num != -1) {
		sum++;
		if (num > high) high = num;
		if (num < low) low = num;
		printf("\nEnter number: ");
		scanf_s("%d", &num);
	}
	printf("%d numbers, max=%d, min=%d", sum, high, low);
	*/
	//                                                Question 7
	/*int num;
	long bin = 0;
	printf("Enter number: ");
	scanf_s("%d", &num);
	while (num != 0) {
		if (num % 2 == 0) printf("0,");
		else if (num % 2 == 1)  printf("1,");
		num =  num / 2;
	}
	*/
	//                                      Question 8
	/*double a1, q, sum ,qpow=1, an;
	int n;
	printf("Enter a1: ");
	scanf_s("%lf", &a1);
	printf("\nEnter q: ");
	scanf_s("%lf", &q);
	printf("\nEnter n: ");
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		qpow = qpow *q;
	}
	an = a1 * (qpow / q);
	sum = (a1 *(qpow - 1)) / (q - 1);
	printf("\na%d = %.1f , S= %.1f", n, an ,sum);*/
//                                                   Question 9
/*	int n;	
	double sum=1;
	printf("Enter n: ");
	scanf_s("%d", &n);
	if (n % 2 == 0) { 
		printf("Entered even number"); 
		return 0;
	}
	for (int i = 3; i <= n; i = i + 2) {

		sum = sum + ((i - 1) / (double)i);
	}
	printf("S: %lf", sum);*/
 //                                                Question 10
	/*int i=0,x,n,max,maxp=0,low,lowp=0;
	printf("Enter n: ");
	scanf_s("%d", &n);
	max = n % 10;
	low = n % 10;
	while (n != 0) {
		x = n % 10;
		if (x >= max) {
			max = x;
			maxp = i;
		}
		if (x <= low) {
			low = x;
			lowp = i;
		}
		i++;
		n = n / 10;
	}
	printf("Max=%d at position:%d, Min=%d, at position: %d", max,maxp,low,lowp);
	*/
//                                       Question 11
/*	int i = 0, x, n, max, maxp = 0, low, lowp = 0;
	printf("Enter n: ");
	scanf_s("%d", &n);
	max = n % 10;
	low = n % 10;
	while (n != 0) {
		x = n % 10;
		if (x > max) {
			max = x;
			maxp = i;
		}
		if (x < low){
			low = x;
			lowp = i;
			}
		
		i++;
		n = n / 10;
	}
	printf("Max=%d at position:%d, Min=%d, at position: %d", max, maxp, low, lowp);*/
//                                                       Question 12
/*	int x,n, even=1 , uneven = 1;
	double sum;
	printf("Enter n: ");
	scanf_s("%d", &n);
	while (n != 0) {
		x = n % 10;
		if (x % 2 == 0) even *= x;
		else uneven *= x;
		n /= 10;
	}
	sum = even / (double)uneven;
	printf("Sum is:%.2f", sum);*/
//                                                   Question 13
//	int guess, answer, count;
//	srand(time(NULL));
//	answer = rand() % 10;
//	count = 0;
//	printf("Enter guess: ");
//	scanf_s("%d", &guess);
//	while (guess != answer) {
//		count++;
//		printf("incorrect guess\n ");
//		printf("Enter guess: ");
//		scanf_s("%d", &guess);
//}
//	printf("Correct\n");
//	switch (count) {
//	case 1:
//			printf("I believe you have cheated…");
//			break;
//	case 2:
//	case 3:
//		printf("Excellent game!");
//		break;
//	case 4:
//	case 5:
//		printf("You played well!");
//		break;
//	case 6:
//	case 7:
//		printf("Average game.");
//	case 8:
//	case 9:
//	case 10:
//		printf("Poor game");
//		break;
//	default:
//		printf("Seriously? There are only ten choices…");
}