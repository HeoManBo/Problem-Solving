#include<bits/stdc++.h>
using namespace std;

int N;
int dp[111'111];

int main(void)
{
	cin >> N;
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = sqrt(i); j >= 1; j--) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[N] << '\n';

	return 0;
}