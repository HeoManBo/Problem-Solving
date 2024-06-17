#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int N, K, MAX = 0x3f3f3f3f;
vector<int> g[101010];
int dp[101010][2]; // dp[i][0], dp[i][1]; 0 : i번쨰 도시에 경찰 X, i번쨰 도시에 경찰서를 지을 때 i를 루트로한 서브트리에서 필요한 최소한의 경찰서 수
bool chk[101010];

void solve(int cur) {
	chk[cur] = true;

	dp[cur][0] = 0;
	dp[cur][1] = 1;

	for (int i = 0; i < g[cur].size(); i++) {
		int next = g[cur][i];
		if (!chk[next]) {
			solve(next);
			dp[cur][0] += dp[next][1]; //현재 경찰서를 안지으면 다음 장소에선 경찰서를 지어야 함
			dp[cur][1] += min(dp[next][0], dp[next][1]); //현재 경찰서를 지으면 다음 장소에서의 경찰서의 필요한 최소값 갱신
		}
	}

}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		dp[i][0] = dp[i][1] = MAX;
	}

	solve(1);

	cout << min(dp[1][0], dp[1][1]);
	return 0;
}
