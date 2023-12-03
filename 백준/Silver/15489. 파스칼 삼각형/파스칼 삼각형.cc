#include<bits/stdc++.h>

using namespace std;

int R, C, W;
int dp[33][33];
int main(void)
{
	cin >> R >> C >> W;
	dp[1][1] = 1;
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= i; j++) {
			if (i == 1 || j == 1) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
	int sum = 0;
	for (int i = 0; i < W; i++) {
		for (int j = 0; j <= i; j++) {
			sum += dp[R + i][C + j];
		}
	}

	cout << sum << '\n';

	return 0;
}