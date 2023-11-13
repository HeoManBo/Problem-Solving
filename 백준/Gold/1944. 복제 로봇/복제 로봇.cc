#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

/*
* BFS를 이용해 키와 S의 모든 간선의 길이를 구하고
* 크루스칼을 통해 구한다. 
*/

int N, M;
char maze[55][55];
pair<int, int> start;
vector<pair<int, int>> keys;
vector<pair<int, pair<int, int>>> edges;
int keyNumber[55][55], parent[255];
bool chk[55][55];
int dy[] = { 0,0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

//크루스칼
int find(int u) {
	if (u == parent[u]) {
		return u;
	}
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	int pu = find(u);
	int pv = find(v);

	if (pu == pv) return;

	parent[pv] = pu;
	return;
}

void bfs(int sy, int sx, int ky, int kx, int node1, int node2) {
	memset(chk, 0, sizeof(chk));
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0, {sy, sx} });
	chk[sy][sx] = true;
	while (!q.empty()) {
		auto xx = q.front();
		q.pop();
		int cnt = xx.first;
		int y = xx.second.first;
		int x = xx.second.second;
		if (y == ky && x == kx) { //원하는 키의 위치에 도달했으면 거리 저장 
			edges.push_back({ cnt, {node1, node2} });
			return;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
				if (!chk[ny][nx] && maze[ny][nx] != '1') {
					chk[ny][nx] = true;
					q.push({ cnt + 1, {ny, nx} });
				}
			}
		}
	}
	return;
}

void find_distance() {
	int sx = start.second;
	int sy = start.first;
	//S -> 각 Key 까지의 거리를 구한다
	for (int i = 0; i < keys.size(); i++) {
		int ky = keys[i].first;
		int kx = keys[i].second;
		bfs(sy, sx, ky, kx, 0, keyNumber[ky][kx]);
	}
	//각 키에서 키까지의 거리를 구한다
	for (int i = 0; i < keys.size(); i++) {
		int ky = keys[i].first;
		int kx = keys[i].second;

		for (int j = i + 1; j < keys.size(); j++ ) {
			int ty = keys[j].first;
			int tx = keys[j].second;
			bfs(ky, kx, ty, tx, keyNumber[ky][kx], keyNumber[ty][tx]);
		}
	}
}

int main(void)
{
	int key_cnt = 1;
	cin >> N >> M;
	string s;
	getchar();
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 1; j <= N; j++) {
			maze[i][j] = s[j - 1];
			if (maze[i][j] == 'S') {
				start = { i,j };
			}
			if (maze[i][j] == 'K') {
				keys.push_back({ i,j });
				keyNumber[i][j] = key_cnt++;
			}
		}
		getchar();
	}

	find_distance();

	for (int i = 0; i <= 255; i++) {	
		parent[i] = i;
	}

	int ans = 0;

	sort(edges.begin(), edges.end());
	int connection = 0;

	for (int i = 0; i < edges.size(); i++) {
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		int c = edges[i].first;
		if (find(u) != find(v)) {
			merge(u, v);
			ans += c;
			connection++;
		}
	}
	
	if (connection == M) cout << ans << '\n';
	else cout << "-1\n";

	return 0;
}