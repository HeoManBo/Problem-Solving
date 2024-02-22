#include<bits/stdc++.h>

using namespace std;

int N, people[11'111];
vector<int> tree[11'111];
int dp[10101][2];
bool chk[10111];

void dfs(int now) {
	chk[now] = true; 
	dp[now][0] = 0; //현재 마을이 우수 마을이 되지 않은 경우
	dp[now][1] = people[now]; //현재 마을이 우수 마을이 된 경우

	for (int next : tree[now]) {
		if (!chk[next]) {
			dfs(next);
			dp[now][0] += max(dp[next][0], dp[next][1]); 
			dp[now][1] += dp[next][0]; //우수마을끼리는 인접 X
		}
	}

}

int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> people[i];
	}
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1);
	cout << max(dp[1][0], dp[1][1]) << '\n';

	return 0;
}