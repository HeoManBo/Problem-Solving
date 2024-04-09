#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int dist[10'101];
int dp[10101][555]; // dp[now][m] 현재 i분에서 달리고 현재 지침 지수가 m일때 끝까지 달렸을 때 얻을 수 있는 최대 거리
int INF = -0x3f3f3f3f;
int go(int now, int m) {
	if (m > M || now > N+1) return INF; // 지침지수가 M보다 커지면
	if (now == N+1) { //끝까지 왔을때
		if (m == 0) { //지침 지수가 0이라면
			return 0;
		}
		else { //지침 지수가 0이 아니라면 XX
			return INF;
		}
	}
	int& ret = dp[now][m];

	if (ret != -1) return ret;

	//현재에서 그냥 달려봄
	ret = go(now + 1, m + 1) + dist[now];

	//현재에서 m이 0이 될때까지 휴식함
	if (m == 0) { //이미 기운이 0인데도 쉬는 경우 다음 단계
		ret = max(ret, go(now + 1, 0));
	}
	else { // 그렇지 않으면 m단계만큼 패스 
		ret = max(ret, go(now + m, 0));
	}
	
	return ret;
}

int main(void)
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> dist[i];
	}
	
	//memset(dp, -1, sizeof(dp));
	//cout << go(1, 0) << '\n';

	dp[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		dp[i][0] = max(dp[i][0], dp[i - 1][0]);
		for (int j = 0; j <= M; j++) {
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + dist[i]);
			dp[i + j][0] = max(dp[i + j][0], dp[i][j]);
		}
	}

	cout << max(dp[n][0], dp[n + 1][0]);

	return 0;
}
