#include <stdio.h>
#include <math.h>

int digits(int);
int palindrom(int);
int reverse(int);
int numcheck(num) {
	while (num > 0){
		int yehidot = num % 10;
		num = num / 10;
		int asarot = num % 10;
		if (yehidot % 2 != 0) return 0;
		if (asarot % 2 == 0) return 0;

			num = num / 10;
	}
	return 1;
}
int divideby3(long num) {
	if (num > 0) {
		if ((num % 10) == 3)
			return 1;

		return divideby3(num / 10);
	}
	else	
		return 0;
}
int palindrom(int num) {
	if (num == reverse(num))
		return 1;
	else 
		return 0;
}
int reverse(int num) {
	int digit = digits(num);
	if (num == 0)
		return 0;
	return ((num % 10 * pow(10, digit-1)) + reverse(num / 10));
}
int digits(int num) {
	int i = 0;
	for ( ; num > 0; num /= 10)
		i++;
	return i;
}

void main() {
	//                                    Question 4
	/*long num;
	printf("Enter Number:");
	scanf_s("%ld", &num);
	printf("\nNumber check:%d", numcheck(num));*/
//                                                 Mabedet bait 3   Question 5
	/*int year, month, day;
	printf("Enter year:");
	scanf_s("%ld", &year);
	printf("Enter month:");
	scanf_s("%ld", &month);
	printf("Enter month:");
	scanf_s("%ld", &day);
	
	switch (month) {
	case 2:
		if ((month == 2) && (day == 28)) {
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))  day++; 
			else {
				month++;
				day = 1;
			}
		}
		else 
			day = 1;
		
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
		if (day == 31) {
			month++;
			day = 1;
		}
		else
			day++;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day == 30) {
			month++;
			day = 1;
		}
		else
			day;
		break;
	case 12:
		if (day == 31) {
			year++;
			month = 1;
			day = 1;
		}
		break;
	}

	printf("\n %d %d %d", year, month, day);*/
	//                                                mabedet bait 4 question 2
	/*int num,x1=0, x2=-1;
	int flag = 1;
	printf("Enter number:");
	scanf_s(" %d", &num);
		do {
			printf("Enter x2:\n");
			scanf_s(" %d", &x1);
			num--;
			if (x2 >= x1)
				flag = 0;
			x2 = x1;
		} while (num >= 1);
	
		if (flag == 1)
			printf("Very ascending\n");
		else
			printf("Not very ascending\n");*/
	/*int num;
	printf("Enter number:");
	scanf_s(" %d", &num);
	printf("%d", palindrom(num));*/
	

}