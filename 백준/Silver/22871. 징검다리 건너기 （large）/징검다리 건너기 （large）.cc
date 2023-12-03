#include<bits/stdc++.h>

using namespace std;

int N;
int arr[5555];
long long dp[5555]; //dp[i] : i번째에서 N번째 돌까지 최대 K 값중 최소 값

long long go(int cur) {
	if (cur == N) { //끝 지점에 왔다면
		return 0;
	}

	long long& ret = dp[cur];
	if (ret != -1) return ret;
	ret = 1e10;

	for (long long i = cur+1; i <= N; i++) {
		long long power = (i - cur) * (1 + abs(arr[cur] - arr[i])); //i번쨰 돌까지 필요한 힘 
		ret = min(ret, max(go(i), power));
	}

	return ret;
}

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << go(1) << '\n';

	return 0;
}