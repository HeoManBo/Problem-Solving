#include<bits/stdc++.h>
using namespace std;

int H, W;
int board[111][111];
int totalTime, cnt;
bool chk[111][111];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

bool melting() {
	chk[0][0] = true; //이점과 만나는 치즈들은 녹아야 한다.
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	int local_cnt = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= H || nx >= W) {
				continue;
			}
			if (chk[ny][nx] == false) {
				if (board[ny][nx] == 0) {
					q.push({ ny,nx });
					chk[ny][nx] = true;
				}
				else { //치즈라면 녹이기
					board[ny][nx] = 0;
					chk[ny][nx] = true;
					local_cnt++;
				}
			}
		}
	}

	if (local_cnt == 0) {
		return false;
	}

	cnt = local_cnt;
	totalTime++;
	return true;
}

int main(void)
{
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> board[i][j];
		}
	}

	while (true) {
		if (!melting()) {
			break;
		}
		memset(chk, false, sizeof(chk));
	}

	cout << totalTime << '\n' << cnt << '\n';
	return 0;
}