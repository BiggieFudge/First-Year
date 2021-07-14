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
			arr[i]=CheckTime(arr[i]);
	}
	return arr;
}
void printTimes(Time* arr,int n) {
	for (int i = 0; i < n; i++) {
		cout <<setfill('0')<<setw(2)<< arr[i].h << ":" << setfill('0') << setw(2) << arr[i].m <<":" << setfill('0') << setw(2) << arr[i].s<<endl;
	}
	
}
void main() {
	int x;
	Time* arr=EnterTimes(x);
	printTimes(arr, x);
	free(arr);
} 