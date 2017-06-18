#include<iostream>
using namespace std;

int data[20][20];
int dp[20][20];

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int temp = 1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			data[i][j] = temp;
			temp++;
		}
	}

	if (k == 0){
		for (int i = 0; i < n; i++){
			dp[i][0] = 1;
		}
		for (int j = 0; j < m; j++){
			dp[0][j] = 1;
		}
		for (int i = 1; i < n; i++){
			for (int j = 1; j < m; j++){
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		cout << dp[n - 1][m - 1] << endl;
	}

	else{
		int r = 0, c = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (k == data[i][j]){
					r = i;
					c = j;
				}
			}
		}
		for (int i = 0; i < n; i++){
			dp[i][0] = 1;
		}
		for (int j = 0; j < m; j++){
			dp[0][j] = 1;
		}
		int ans1, ans2;
		for (int i = 1; i <= r; i++){
			for (int j = 1; j <= c; j++){
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		ans1 = dp[r][c];

		for (int i = r; i < n; i++){
			dp[i][c] = 1;
		}
		for (int j = c; j < m; j++){
			dp[r][j] = 1;
		}
		for (int i = r + 1; i < n; i++){
			for (int j = c + 1; j < m; j++){
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		ans2 = dp[n - 1][m - 1];
		cout << ans1*ans2 << endl;
	}
}
