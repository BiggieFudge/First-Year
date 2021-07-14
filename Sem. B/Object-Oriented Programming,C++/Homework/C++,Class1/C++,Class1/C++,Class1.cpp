using namespace std;
#include <iostream>
int Add(int a, int b) {
	return a + b;
}
int Sub(int a, int b) {
	return a - b;
}
int Mul(int a, int b) {
	return a * b;
}
int main(){
	int (*allfunc[])(int, int) = { Add,Sub,Mul };
	int a, b;
	cout << "Enter 2 Nums:";
	cin >> a >> b;
	for (int i = 0; i < 3; i++){
		
		cout << "\nFunction returned:" << (*allfunc[i])(a, b);
	}
	
	
}

