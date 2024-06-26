#include<bits/stdc++.h>

using namespace std;

int H, Y, dp[22];

int main(void)
{
	cin >> H >> Y;
	
	dp[0] = H;
	for (int i = 1; i <= Y; i++) {
		dp[i] = (int)(dp[i - 1] * 1.05);
		if (i >= 3) {
			dp[i] = max(dp[i], (int)(dp[i - 3] * 1.2));
		}
		if (i >= 5) {
			dp[i] = max((int)dp[i], (int)(dp[i - 5] * 1.35));
		}
	}

	cout << dp[Y] << '\n';

	return 0;
}