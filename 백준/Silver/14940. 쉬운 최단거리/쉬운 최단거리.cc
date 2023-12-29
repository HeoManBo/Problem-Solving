#include<bits/stdc++.h>
using namespace std;

int arr[1111][1111];
int dist[1111][1111];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
pair<int, int> start;
int main(void) {
	memset(dist, 0x3f, sizeof(dist));
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				start = { i,j };
			}
		}
	}

	queue<pair<int, int>> q;
	q.push({ start.first, start.second });
	dist[start.first][start.second] = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (arr[ny][nx] == 0) continue;
			if (dist[ny][nx] != 0x3f3f3f3f) continue;
			dist[ny][nx] = dist[y][x] + 1;
			q.push({ ny,nx });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == 0x3f3f3f3f) {
				if (arr[i][j] == 0) {
					cout << "0 ";
				}
				else {
					cout << "-1 ";
				}
			}
			else {
				cout << dist[i][j] << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}