#include<iostream>
using namespace std;

int a[10010];
int d[10010][3];

int max(int a, int b){
	return a > b ? a : b;
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	d[0][1] = a[0];

	for (int i = 1; i <= n; i++){
		d[i][0] = max(max(d[i - 1][0], d[i - 1][1]), d[i - 1][2]);
		d[i][1] = d[i - 1][0] + a[i];
		d[i][2] = d[i - 1][1] + a[i];
	}
	printf("%d", d[n][0]);
} 
