#include<iostream>
using namespace std;

int onec, zeroc;

int fibonacci(int n) {
	if (n == 0) {
		zeroc++;
		return 0;

	}
	else if (n == 1) {		
		onec++;
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main(){
	int t;
	cin >> t;
	while (t--){
		int a;
		cin >> a;
		fibonacci(a);
		printf("%d %d\n", zeroc, onec);
		onec = zeroc = 0;
	}
	return 0;
}