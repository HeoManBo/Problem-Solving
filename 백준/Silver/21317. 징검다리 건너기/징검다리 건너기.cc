#include<iostream>
#include<string.h>

using namespace std;
int N, small_jump[22], big_jump[22], K;
int dp[22][2]; // dp[i][x] : i번째 돌 위치에서 마지막 돌 위치까지 가는데 필요한 최소 에너지, 2는 슈퍼점프를 썻는지 안썻는지 확인함.
int INF = 0x3f3f3f3f;

int solve(int now, int use) {
	if (now > N) return INF;
	if (now == N) { //끝에 도달했땀녀
		return 0; //도착시
	}
	int& ret = dp[now][use];
	if (ret != INF) return ret;
	//슈퍼 점프를 안썻다면
	if (use == 1) {
		ret = min(ret, solve(now + 3, 0) + K);
	}
	//작은 점프와 큰 점프를 각각 해본다.
	ret = min(ret, solve(now + 1, use) + small_jump[now]);
	//큰 점프
	ret = min(ret, solve(now + 2, use) + big_jump[now]);

	return ret;
}

int main(void)
{
	cin >> N;
	for (int i = 1; i <= N-1; i++) {
		cin >> small_jump[i] >> big_jump[i];
	}
	cin >> K;
	memset(dp, 0x3f, sizeof(dp));
	cout << solve(1, 1) << "\n";

	return 0;
}