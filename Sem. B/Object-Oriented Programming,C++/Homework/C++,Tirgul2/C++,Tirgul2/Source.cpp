#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
typedef struct {
	int s;
	int m;
	int h;
}Time;
Time CheckTime(Time t) {
	if (t.s >= 60) {
		t.m += t.s / 60;
		t.s = t.s % 60;
	}
	if (t.m >= 60) {
		t.h += t.m / 60;
		t.m = t.m % 60;
	}
	return t;
}

Time* EnterTimes(int &x) {
	cout << "Enter how many values:";
	cin >> x;
	Time* arr = new Time[x];
	if (arr == NULL)
		exit(-1);
	for (int i = 0; i < x; i++) {
		cout << "Enter hour,min,sec:";
		cin >> arr[i].h >> arr[i].m >> arr[i].s;
		if (arr[i].m >= 60 || arr[i].s >= 60)
			arr[i] = CheckTime(arr[i]);
	}
	return arr;
}
void printTimes(Time* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << setfill('0') << setw(2) << arr[i].h << ":" << setfill('0') << setw(2) << arr[i].m << ":" << setfill('0') << setw(2) << arr[i].s << endl;
	}

}

void swapPoint(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swapRef(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
Time clon(const Time& mt) {
	return mt;
}

typedef struct {
	int m;
	int d;
	int y;
}Date;


int Checkdate(Date& d1) {
	if ((d1.d <= 31 && d1.d >= 1) && (d1.m >= 1 && d1.m <= 12))
		return 0;
	else {
		swapRef(d1.d, d1.m);
		return 1;
	}
}
Date* SaveDates(int &n) {
	cout << "Enter How many dates to save:" << endl;
	cin >> n;
	Date* arr = new Date[n];
	for (int i = 0; i < n; i++){
		cout << "Enter Day, month, year:";
		cin >> arr[i].d >> arr[i].m >> arr[i].y;
		cout << endl << "Saved day:" << arr[i].d << endl;
	}
	return arr;
}
int printDates(Date* arr, int n) {
	int counter = 0;
	for (int i = 0; i < n; i++){
		if(Checkdate(arr[i])==1)
			counter++;
		cout << "arr[" << i << "]:" << "day" << arr[i].d << ". month:" << arr[i].m << ". year:" << arr[i].y<<endl;
	}
	cout << "Function calculated:" << counter;
	return counter;
}
void main() {
	int a = 5, b = 3;
	swapPoint(&a, &b);
	cout << "a=" << a << ". b=" << b << "." <<endl;
	swapRef(a, b);
	cout << "a=" << a << ". b=" << b<<"."<<endl;
	Date d1;
	d1.d = 12;
	d1.m = 4;
	cout << "Function returned:" << Checkdate(d1)<<endl;
	cout <<"Day:" <<d1.d<<". Month:" << d1.m<<"." << endl;
	int n;
	Date* arr = SaveDates(n);
	printDates(arr, n);


	delete(arr);
}