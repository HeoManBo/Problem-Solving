#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<string.h>
using namespace std;

int dp[1010][10101];
int N, K;
int important[1010], needTime[1010];

int main(void) {
	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		cin >> important[i] >> needTime[i];
	}

	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			if (j - needTime[i] >= 0) {
				if (dp[i - 1][j] < dp[i - 1][j - needTime[i]] + important[i]) {
					dp[i][j] = dp[i - 1][j - needTime[i]] + important[i];
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
			else dp[i][j] = dp[i-1][j];
		}
	}

	cout << dp[K][N] << "\n";

	return 0;
}