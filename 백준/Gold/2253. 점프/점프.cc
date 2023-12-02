#include<bits/stdc++.h>

using namespace std;

int N, M;
bool chk[20'001];
int dp[20'001][500];
const int INF = 0x3f3f3f3f;

int solve(int now, int step) {
	if (now > N) return INF;
	if (now == N) {
		return 0;
	}
	int& ret = dp[now][step];
	if (ret != -1) return ret;
	ret = INF;

	for (int next_step = step - 1; next_step <= step + 1; next_step++) {
		if (next_step == 0 || next_step == -1) continue;
		if (chk[now + next_step]) continue;
		ret = min(ret, solve(now + next_step, next_step) + 1);
	}

	return ret;
}


int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		chk[num] = true;
	}
	memset(dp, -1, sizeof(dp));	

	int ans = solve(1, 0);

	if (ans == INF) {
		cout << "-1\n";
	}
	else {
		cout << ans << '\n';
	}

	return 0;
}