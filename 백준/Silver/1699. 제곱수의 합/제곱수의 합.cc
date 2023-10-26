#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

int N;
int dp[101010]; // dp[x] : x를 표현하는데 필요한 항의 최소 갯수 
int INF = 987654321;
int solve(int now) {
	if (now < 0) return INF;
	if (now == 0) return 0;

	int& ret = dp[now];
	if (ret != -1) return ret;
	ret = INF;

	for (int i = sqrt(now); i >= 1; i--) {
		ret = min(ret, solve(now - i * i) + 1);
	}

	return ret;
}

int main(void) {
	cin >> N;
	memset(dp, -1, sizeof(dp));

	cout << solve(N) << '\n';

	return 0;
}