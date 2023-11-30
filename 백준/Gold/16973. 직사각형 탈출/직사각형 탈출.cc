#include<bits/stdc++.h>

using namespace std;

int N, M, H, W, sr, sc, fr, fc;
int arr[1111][1111];
int chk[1111][1111];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };


bool canMove(int l, int r, int idx) { //왼쪽 좌표가 l,r 일때 l + H, r + W 까지 아무것도 없는지 확인한다.
	if (l + H > N+1 || r + W > M+1) //맵 밖을 넘어서는 경우
		return false;

	//완탐은 시간 초과;
	//for (int i = l; i < l + H; i++) {
	//	for (int j = r; j < r + W; j++) {
	//		if (arr[i][j] == 1) return false;
	//	}
	//}
	int row, col;
	//동서남북에 따른 case 조사
	switch (idx) {
		case 0: //동
			r += (W - 1);
			for (int i = l; i < l + H; i++) {
				if (arr[i][r] == 1) return false;
			}
			break;
		case 1: //서
			for (int i = l; i < l+H; i++) {
				if (arr[i][r] == 1) return false;
			}
			break;
		case 2: //남
			l += (H - 1);
			for (int i = r; i < r + W; i++) {
				if (arr[l][i] == 1) return false;
			}
			break;
		case 3: //북
			for (int i = r; i < r + W; i++) {
				if (arr[l][i] == 1) return false;
			}
	}

	return true;
}



int bfs() {
	queue<pair<int, int>> q;
	q.push({ sr, sc }); //왼쪽 위 
	chk[sr][sc] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		if (y == fr && x == fc) {
			return chk[y][x] - 1;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue; //맵 밖
			if (arr[ny][nx] == 1 || chk[ny][nx]) continue; //벽이 있는 경우 / 이미 확인한 경우
			if (canMove(ny, nx, i)) {
				q.push({ ny, nx });
				chk[ny][nx] = chk[y][x] + 1;
			}
		}

	}

	return -1;
}

int main(void)
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	cin >> H >> W >> sr >> sc >> fr >> fc;

	cout << bfs() << '\n';

	return 0;
}