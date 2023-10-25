#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<string.h>
using namespace std;

//int dp[1010][10101];
int N, K;
int important[1010], needTime[1010];
//int dp[2][10101];
int dp[10101];

int main(void) {
	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		cin >> important[i] >> needTime[i];
	}

	//공간복잡도 O(K * N)
	/*for (int i = 1; i <= K; i++) {
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
	}*/
	
	//공간 복잡도 O(2 * N)
	/*for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			if (j - needTime[i] >= 0) {
				if (i % 2 == 1) {
					dp[1][j] = max(dp[0][j], dp[0][j - needTime[i]] + important[i]);
				}
				else {
					dp[0][j] = max(dp[1][j], dp[1][j - needTime[i]] + important[i]);
				}
			}
			else {
				if (i % 2 == 1) {
					dp[1][j] = dp[0][j];
				}
				else {
					dp[0][j] = dp[1][j];
				}
			}
		}
	}*/

	//공간복잡도 O(N)

	for (int i = 1; i <= K; i++) {
		for (int j = N; j >= 0; j--) {
			if (j - needTime[i] >= 0) {
				dp[j] = max(dp[j], dp[j - needTime[i]] + important[i]);
			}
		}
	}

	cout << dp[N] << "\n";

	return 0;
}