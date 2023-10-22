#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int N, M, start, target;
vector<pair<int, int>> road[10101];
vector<pair<int, int>> back_road[10101];
int chk[10101], cnt, indegree[10101];
bool path[10101];

int dijstra(int start, int target) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	chk[start] = 0;

	while (!pq.empty()) {
		int cur = pq.top().second;	
		int cost = pq.top().first;
		pq.pop();
		if (chk[cur] < cost) continue;
		for (auto x : road[cur]) {
			int next = x.first;
			int n_c = x.second;
			if (chk[next] > n_c + cost) {
				chk[next] = n_c + cost;
				pq.push({ chk[next], next });
			}
		}
	}

	return -chk[target];
}

void bfs(int now) {
	queue<int> q;
	q.push(now);
	path[now] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto x : back_road[cur]) {
			int next = x.first;
			int n_c = x.second;
			if (chk[cur] - chk[next] == n_c) { //만약 이전 정점이 최장 경로의 한 정점이라면 추가 
				cnt++;
				if (!path[next]) { //중복 방지 
					q.push(next);
					path[next] = true;
				}
			}
		}
	}

}

int topologize(int start, int target) {
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto x : road[cur]) {
			int next = x.first;
			int nc = x.second;
			if (--indegree[next] == 0) {
				q.push(next);
			}
			//최장 경로 갱신
			if (chk[next] < chk[cur] + nc) {
				chk[next] = chk[cur] + nc;
			}
		}

	}

	return chk[target];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road[a].push_back({ b, c });
		back_road[b].push_back({ a, c });
		indegree[b]++;
	}

	cin >> start >> target;

	//int s = dijstra(start, target); //최장 경로 계산
	int s = topologize(start, target);

	bfs(target); // 끝점에서부터 시작점까지 역추적 

	cout << s << '\n' << cnt << '\n';

	return 0;
}