#include <stdio.h>
#include <math.h>
#include <string.h>

// קוד של אהובה
int gcd(int n, int m)
{
	int t;
	while (m > 0)
	{
		t = m;
		m = n % m;
		n = t;

	}
	return n;
}
//גמר קוד של אהובה

double power(double x, int n)
{
	if (n == 0) return 1;
	return power(x, n / 2)*power(x, n / 2)*(x*(n%2));

}
int lucas(num) {
	if (num == 0) return 2;
	if (num == 1) return 1;
	else
		return lucas(num - 1)+lucas (num-2);
}
int lucass(num) {
	int n1 = 2, n2 = 1, n3=1;
	if (num == 0) {
		 return n1;
	}
	for (int i = 2; i <= num; i++) {
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;

	}
	return n3;
}
int paul(num) {
	if (num == 0) return 0;
	if (num == 1) return 1;
	else return 2 * paul(num - 1)+paul(num - 2);

}
int paulfor(num) {
	int a=0, b=1, c;
	for (int i = 2; i <= num; i++) {
		c = 2 * (b)+a;
		a = b;
		b = c;
		
	}
	return c;
}

int quest4(num) {
	if (num <= 2) return 1;
	if (num % 2 == 0) return quest4(num - 1) + quest4(num - 2) + quest4(num - 3);
	else return quest4(num - 1) - quest4(num - 3);

}
int quest4for(num) {
	int a =1, b =1, c=1,answer=1;
	for (int i = 3; i <= num; i++) {
		
		if (i % 2 == 0) 
			answer = a + b + c;
		else
			answer = c - a;
		a = b;
		b = c;
		c = answer;
	}
	return answer;

}
int quest5(num) {
	if (num != 0) {
		int x;
		printf("Enter Number");
		scanf_s("%d", &x);
		if (quest5(num - 1) < x)
			return x;
	}
}
int quest6(num) {
	if (num != 0) {
		int x;
		printf("Enter Number");
		scanf_s("%d", &x);
		if (quest6(num - 1) > x)
			return x;
	}
}

int quest7(int num) {
	if (num == 0)
		return 0;

	else 
		return (num %2) + 10 * quest7(num / 2);


}
void quest8(int num, char c1, char c2) {
	if (num > 0) {
		printf("%c", c1);
		quest8(num - 1, c1, c2);
		printf("%c%c", c2, c2);
	}

}
int quest9A(int num) {
	int x = (num % 10);
	x--;
	x = x % 10;
	if ((num >0) && (num <=9))
		return num-1;

		else
			return quest9A(num / 10) * 10 + ((num % 10)-1);
}
	
int quest9B(int num) {
	int x = num % 10;
	x++;
	x = x % 10;
	if ((num > 0) && (num <= 9))
		return x;
	
		
	else
		return quest9B(num / 10) * 10 + x;
}
int quest10(int num) {
	if (num <= 9)
		return ((num % 2));
	else 
		return (((num % 2) + (quest10(num / 10)))%2);
	
}
int quest11(int num) {
	int x = num % 10, y = (num % 100) / 10;
	if (num < 10) 
		return !(num%2);
	
	
	if ((x%2 == 0) && (y%2 == 1))
		return quest11(num/100);
	else 
		return 0;
	}



int quest12(int num) {
	if (num < 10)
		return 1;
	
	int x = num % 10;
	int y = (num % 100) / 10;
	if (((x % 2 == 0) && (y % 2 == 1)) || ((x % 2 == 1) && (y % 2 == 0)))
		quest12(num / 10);
	else
		return 0;
	

}
void main() {
	//                                              Question 1
/*	int n;
	double num;
	printf("Enter num: ");
	scanf_s("%lf", &num);
	printf("\nEnter n: ");
	scanf_s("%d", &n);
	printf("answer is:%lf", power(num, n));
*/	//                                               Question 2
	/*int num;
	printf("enter num: ");
	scanf_s("%d", &num);
	printf("\nlucas number is:%d", lucas(num));
	
	printf("\nAnswer is:%d", lucass(num));
	*/
//                                                        Question 3
/*	int num;
	printf("enter num: ");
	scanf_s("%d", &num);
	printf("P_%d = %d", num, paul(num));
	printf("\nP_%d = %d", num, paulfor(num));
	*/
	//                                                    Question 4
	//int num;
	//printf("enter num: ");
	//scanf_s("%d", &num);
	//printf("S_%d = %d", num, quest4(num));
	//printf("\nS_%d = %d", num, quest4for(num));
	//                                                  Question 5
	/*int num;
	printf("enter num: ");
	scanf_s("%d", &num);
	printf("Max num is:%d", quest5(num));*/
	//                                                   Question 6
	/*int num;
	printf("enter num:");
	scanf_s("%d", &num);
	printf("low num is:%d", quest6(num));*/
	//                                                   Question 7
	/*int num;
	printf("enter num:");
	scanf_s("%d", &num);
	printf("binary num is:%d", quest7(num));*/

	//                                                    Question 8
	/*int num;
	char c1, c2;
	printf("Enter num:");
	scanf_s("%d", &num);
	printf("Enter c1:");
	scanf_s(" %c", &c1);
	printf("Enter c2:");
	scanf_s(" %c", &c2);
	quest8(num,c1,c2);*/

//                                                                   Question 9
	/*int num;
	printf("Enter num:");
	scanf_s("%d", &num);
	printf("\n A: %d", quest9A(num));
	printf("\n B: %d", quest9B(num));*/
	//                                                           Question 10
	/*int num;
	printf("Enter num:");
	scanf_s("%d", &num);
	printf("\n Answer is: %d", !quest10(num));*/
	//                                                     Question 11
	int num;
	printf("Enter num:");
	scanf_s("%d", &num);
	printf("\n Answer is: %d", quest11(num)); 

	//                                                 Question 12
	/*int num;
	printf("Enter num:");
	scanf_s("%d", &num);
	printf("\n Answer is: %d", quest12(num));*/
	}