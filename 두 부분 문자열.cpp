#include<iostream>
#include<string.h>
using namespace std;

char a[1010];
char b[1010];
int dp[1010][1010];

int max(int a, int b){
	return a > b ? a : b;
}

int lcs(int i, int j){
	if (i == -1 || j == -1){
		return 0;
	}
	if (dp[i][j] != -1){
		return dp[i][j];
	}
	else if (a[i] == b[j]){
		return dp[i][j] = lcs(i - 1, j - 1) + 1;
	}
	else if (a[i] != b[j]){
		return dp[i][j] = max(lcs(i - 1, j), lcs(i, j - 1));
	}
}

int main(){
	for (int i = 0; i < 1002; i++){
		for (int j = 0; j < 1002; j++){
			dp[i][j] = -1;
		}
	}
	scanf("%s", a);
	scanf("%s", b);
	cout << strlen(a) + strlen(b) - lcs(strlen(a) - 1, strlen(b) - 1) << endl;
}