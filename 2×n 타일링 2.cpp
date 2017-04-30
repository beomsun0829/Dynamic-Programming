#include<iostream>
using namespace std;

long int d[1010];

int main(){
	int n;
	scanf("%d", &n);
	d[1] = 1;
	d[2] = 3;
	for (int i = 3; i <= n; i++){
		d[i] = (d[i - 1] + 2 * d[i - 2])%10007;
		
	}
	printf("%d", d[n]);

	return 0;
}