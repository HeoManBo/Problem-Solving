#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int N, M, A, B, C;
vector<pair<int, int>> graph[100'001];
int max_cost[100'001], total_cost[100'001];



int main(void)
{
	cin >> N >> M >> A >> B >> C;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	
	memset(max_cost, 0x3f, sizeof(max_cost));
	memset(total_cost, 0x3f, sizeof(total_cost));
	max_cost[A] = 0;
	total_cost[A] = 0;
	queue<pair<int, pair<int, int>>> q; // {a,{b,c}} a : 토탈 수치심 b : 최대 수치심 c : 현재 위치
	q.push({ 0, {0,A} });
	int ans = 0x3f3f3f3f;
	while (!q.empty()) {
		auto x = q.front(); q.pop();
		int TOTAL = -x.first;
		int MAX = x.second.first;
		int now = x.second.second;
		
		for (pair<int, int> xx : graph[now]) {
			int next = xx.first;
	 			int NEXT_TOTAL = TOTAL + xx.second; //다음 골목을 지날때 최대 수치심
			if (total_cost[next] > NEXT_TOTAL && NEXT_TOTAL <= C) {
				max_cost[next] = max(MAX, xx.second);
				total_cost[next] = NEXT_TOTAL;
				q.push({ -total_cost[next], {max_cost[next],next } });
				if (next == B) {
					ans = min(ans, max_cost[next]);
				}
			}	
		}
	}
	
	if (ans == 0x3f3f3f3f) {
		cout << "-1\n";
	}
	else {
		cout << ans << '\n';
	}

	return 0;
}