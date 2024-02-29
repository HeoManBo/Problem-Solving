#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> virus_pos;
int arr[55][55], ans = 123456789;
int cp[55][55];
bool selected[11];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };



int bfs() {
	int MIN = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cp[i][j] = arr[i][j];
			if (cp[i][j] == 0) {
				cp[i][j] = 9999;
			}
			else if (cp[i][j] == 1) {
				cp[i][j] = -1;	
			}
		}
	}
	for (int i = 0; i < virus_pos.size(); i++) {
		if (selected[i]) {
			q.push(virus_pos[i]);
			cp[virus_pos[i].first][virus_pos[i].second] = 0;
		}
		else if (!selected[i]) {
			cp[virus_pos[i].first][virus_pos[i].second] = 9999;
		}
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (cp[ny][nx] != -1 && cp[ny][nx] != 0 && cp[ny][nx] == 9999) { // 벽이 아니고 바이러스 시작 위치가 아닌 경우
				cp[ny][nx] = cp[y][x] + 1;
				MIN = max(cp[ny][nx], MIN);
				q.push({ ny,nx });
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (cp[i][j] == 9999) { // 바이러스를 못 퍼트린 곳이 있다면 
				return 123456789;
			}
		}
	}

	return MIN;
}

void pos_select(int now, int cnt) {
	if (cnt == M) { //M개 선택 완료한 경우
		ans = min(ans, bfs());
		return;
	}

	for (int i = now; i < virus_pos.size(); i++) {
		if (!selected[i]) { // 바이러스를 어따 놓을 것인지 선택 
			selected[i] = true;
			pos_select(i, cnt + 1);
			selected[i] = false;
		}
	}

}

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				virus_pos.push_back({ i,j }); 
			}
		}
	}

	pos_select(0, 0);

	cout << (ans == 123456789? -1 : ans)<< '\n';

	return 0;
}