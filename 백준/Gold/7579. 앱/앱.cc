#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int N, M;
int memory[101];
int cost[101];
int dp[101][10101];
//memory를 dp로 두면 메모리를 너무 많이 차지함
//cost를 dp로 두는 방법은 어떨까?
int main(void) {
	cin >> N >> M;
	int maxCost = 0;
	for (int i = 1; i <= N; i++) {
		cin >> memory[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		maxCost += cost[i];
	}
	//dp[i][j] = i번째 앱을 탐색했을때
	//j비용을 소모해 얻을 수 있는 최대 메모리
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= maxCost; j++) {
			if (j - cost[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + memory[i]);
			}
			dp[i][j] = max(dp[i][j],dp[i-1][j]);
		}
	}

	for (int i = 0; i <= maxCost; i++) {
		if (dp[N][i] >= M) {
			cout << i << "\n";
			break;
		}
	}
	return 0;
}