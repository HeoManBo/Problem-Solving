#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAXN 500000
using namespace std;
int N;
int dp[1000001];
int solve(int N) {
	if (N == 1) {
		return 0;
	}
	int& ret = dp[N];
	if (ret != -1) {
		return ret;
	}
	ret = 987654321;
	if (N % 3 == 0 && N % 2 == 0) {
		ret = min(solve(N / 2), solve(N / 3)) + 1;
	}
	else if (N % 3 == 0) {
		ret = solve(N / 3) + 1;
	}
	else if (N % 2 == 0) {
		ret = solve(N/2) + 1;
	}
	ret = min(ret, solve(N - 1) + 1);
	return ret;
}

int main(void) {
	cin >> N;
	solve(N);
	memset(dp, -1, sizeof(dp));
	cout << solve(N);
}