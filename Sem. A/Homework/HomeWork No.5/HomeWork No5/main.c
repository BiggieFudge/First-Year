#include <stdio.h>
int square(num) {
	num = num * num;
	return num;
}
int cube(num) {
	num = num * num * num;
	return num;
}
int power(num, pwr) {
	int sum = 1;
	for (int i = 1; i <= pwr; i++) {
		sum = sum * num;
	}
	return sum;
}
int iseven(num) {
	if (num % 2 == 0) return 1;
	else return 0;
}
int isodd(num) {
	if (num % 2 == 0) return 0;
	else return 1;
}
long totalsum(digit) {
	long sum = 1;
	for (int i = 1; i < digit; i++) {
		sum = (sum * 10) + 1;
	}
	return sum;
}
char tolowercase(ch) {
	if ((ch <= 'Z') && (ch >= 'A')) return ch +32;
	else return '0';
}
char touppercase(ch) {
	if ((ch <= 'z') && (ch >= 'a')) return ch - 32;
	else return '0';


}int threedigitssum(num1, num2, num3) {
	if ((num1 > 0) && (num1 < 9) && (num2 > 0) && (num2 < 9) && (num3 > 0) && (num3 < 9)) return (num1 + num2 + num3);
	else return 0;
}


int  sumofdividers(num1, num2) {
	int sum = 0;
	for (int i = 1; i <= num1; i++) {
		if ((num1%i == 0) && (num2%i == 0)) sum += i;
	}
	return sum;
}
int sumofdividerseven(num) {
	int sum = 0;
	for (int i = 1; i <= num; i++) {
		if (num%i == 0) sum += i;
	}
	if (sum % 2 == 0) return 0;
	else return 1;
}
int lowestdivider(num) {
	double half=num /2;
	if (roundf(half) == half ) return num;
	int lowest = 1;
	for (int i = 2; i <= num; i++) {
		if (num % i == 0) {
			lowest = i;
			return i;
		}}}
int highestdivider(num) {
	double half = num / 2;
	if (roundf(half) == half) return 1;
	int highest = 1;
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			highest = i;
		}}
	return highest;}
int GCD(num1, num2) {
	int num;
	for (int i = 1; i <= num1 && i<=num2; i++) {
		if ((num1%i == 0) && (num2%i == 0)) num = i;
	}
	return num;
}
int chimchum(num1, num2) {
	if (num2 == 0) {
		printf("Can't divide by 0");
		return 0;}
	int i = GCD(num1, num2);
	printf("%d/%d = %d/%d", num1,num2,num1/i,num2/i );
}
int  LCM(num1, num2) {

}
void main(){
	//                            Question 1
	/*
	int num, pwr;
	printf("Enter num: ");
	scanf_s("%d", &num);
	printf("\nEnter pwr: ");
	scanf_s("%d", &pwr);
	printf("\nSquare is:%d", square(num));
	printf("\nCube is:%d", cube(num));
	printf("\nPwr is:%d", power(num,pwr));
	*/
	//                              Question 2
	/*
	int num;
	printf("Enter num: \n");
	scanf_s("%d", &num);
	printf("\nEven:%d", iseven(num));
	printf("\nOdd:%d", isodd(num));
	*/
	//                                     Question 3
	/*
	int digit;
	printf("Enter num: \n");
	scanf_s("%d", &digit);
	printf("Sum is:%ld \n", totalsum(digit));
	*/
	//                                       Question 4
	/*
	char ch;
	printf("Enter Char:");
	scanf_s("%c",&ch);
	printf("\nTo upper case: %c", touppercase(ch));
	printf("\nTo lower case: %c", tolowercase(ch));
	*/
	//                                          Question 5
	/*
	int num1,num2,num3;
	printf("Enter n1:");
	scanf_s("%d", &num1);
	printf("\nEnter n2:");
	scanf_s("%d", &num2);
	printf("\nEnter n3:");
	scanf_s("%d", &num3);
	printf("\n%d", threedigitssum(num1, num2, num3));
	*/
	//                                               Question 6
	/*
	int num1, num2;
	printf("Enter n1:");
	scanf_s("%d", &num1);
	printf("\nEnter n2:");
	scanf_s("%d", &num2);
	printf("Sum is:%d", sumofdividers(num1, num2));
	*/
	//                                                  Question 7
	/*
	int num;
	printf("Enter num:");
	scanf_s("%d", &num);
	printf("sum dividers odd:%d", sumofdividerseven(num));
	*/
	//                                                  Question 8
	/*
	int num;
	printf("Enter num:");
	scanf_s("%d", &num);
	printf("Lowest divider is:%d", lowestdivider(num));
	*/
	//                                                     Question 9
	/*
	int num;
	printf("Enter num:");
	scanf_s("%d", &num);
	printf("Highest divider is:%d", highestdivider(num));
	*/
	//                                              Question 10
	/*
	int numerator,denominator;
	printf("Enter numerator:");
	scanf_s("%d", &numerator);
	printf("\nEnter denominator:");
	scanf_s("%d", &denominator);
	chimchum(numerator, denominator);*/
	//                                              Question 11
	int num1, num2;
	printf("Enter n1:");
	scanf_s("%d", &num1);
	printf("\nEnter n2:");
	scanf_s("%d", &num2);
	printf("Least common multilple is:%d", (num1*num2)/GCD(num1, num2));
	}


