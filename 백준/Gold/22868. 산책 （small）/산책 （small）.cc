#include<bits/stdc++.h>
using namespace std;

int N, M, S, E, dist[10'001];
vector<int> graph[10'001];
vector<int> path[10'001]; // path[i] : i번 노드까지 가중치의 합이 가장 작은 이전 노드들의 모음 
bool chk[10'001]; //돌아갈때 건너면 안되는 노드번호 = true
vector<vector<int>> p;

//int solve(int S, int E) {
//	memset(dist, 0x3f, sizeof(dist));
//	priority_queue<pair<int, int>> pq;
//	pq.push({ 0, S });
//	dist[S] = 0;
//
//	while (!pq.empty()) {
//		int now = pq.top().second;
//		int cost = -pq.top().first;
//		pq.pop();
//		if (dist[now] < cost) continue; //가지치기
//
//		for (int next : graph[now]) {
//			int nc = cost + 1;
//			if (!chk[next]) { //돌아갈때 금지된 길이 아니고
//				if (dist[next] > nc) {
//					dist[next] = nc;
//					pq.push({ -dist[next], next });
//					path[next].clear();
//					path[next].push_back(now);
//				}
//				else if (dist[next] == nc) {
//					path[next].push_back(now);
//				}
//			}
//		}
//	}
//
//	return dist[E];
//}
//
//void remove_path(int now, vector<int>& s) {
//	if (now == S) {
//		s.push_back(now);
//		p.push_back(s);
//		s.pop_back();
//		return;
//	}
//	s.push_back(now);
//	for (int i = 0; i < path[now].size(); i++) {
//		int next = path[now][i];
//		remove_path(next, s);
//	}
//	s.pop_back();
//}
//
//void wrong_answer() {
//	cin >> N >> M;
//	for (int i = 0; i < M; i++) {
//		int a, b;
//		cin >> a >> b;
//		graph[a].push_back(b);
//		graph[b].push_back(a);
//	}
//	for (int i = 1; i <= N; i++) {
//		sort(graph[i].begin(), graph[i].end());
//	}
//	cin >> S >> E;
//	int go = solve(S, E);
//	for (int i = 0; i < path[E].size(); i++) {
//		vector<int> s;
//		s.push_back(E);
//		int next = path[E][i];
//		remove_path(next, s);
//		reverse(s.begin(), s.end());
//	}
//	sort(p.begin(), p.end());
//	for (int i = 1; i < p[0].size() - 1; i++) { //시작점과 끝점은 제외 
//		chk[p[0][i]] = true;
//	}
//	int back = solve(E, S);
//	cout << go + back << '\n';
//}

int bfs(int S, int E, vector<int>& path) {
	memset(dist, 0x3f, sizeof(dist));
	chk[S] = true;
	queue<pair<int, int>> q;
	q.push({ S, 0 });
	while (!q.empty()) {
		int now = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int next : graph[now]) {
			if (!chk[next]) {
				chk[next] = true;
				path[next] = now;
				q.push({ next, c + 1 });
			}
			if (next == E) {
				return c + 1;
			}
		}
	}
}

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	cin >> S >> E;
	vector<int> path(N+1, 0);
	int go = bfs(S, E, path);
	memset(chk, 0, sizeof(chk));
	int e = path[E]; 
	while (e != 0) {
		chk[e] = true;
		e = path[e];
	}
	int back = bfs(E, S, path);

	cout << go + back << '\n';
	return 0;
}	