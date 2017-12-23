#include<iostream>
using namespace std;

char data[1000010];

int main(){
	int n;
	int ans = 0;
	cin >> n;
	scanf("%s", data);
	data[n] = 'A';
	for (int i = 1; i < n; i++){
		if (data[i - 1] != data[i] && data[i] != data[i + 1]){
			if (data[i] == 'A')
				data[i] = 'B';
			else
				data[i] = 'A';
			ans++;
		}
	}
	for (int i = 1; i <= n; i++){
		if (data[i - 1] != data[i])
			ans++;
	}
	cout << ans << endl;
}