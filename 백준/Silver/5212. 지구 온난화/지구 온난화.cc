#include<bits/stdc++.h>
using namespace std;

int R, C;
char board[11][11], after[11][11];
int dy[] = { 0,0, 1,-1 };
int dx[] = { 1,-1,0,0 };

bool disappear(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= R || nx >= C) {
			cnt++;
		}
		else if (board[ny][nx] == '.') {
			cnt++;
		}
	}

	return cnt >= 3;
}

int main(void)
{
	cin >> R >> C;
	getchar();
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%c", &board[i][j]);
			after[i][j] = board[i][j];
		}
		getchar();
	}

	//삭제 
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == 'X') {
				if (disappear(i, j)) {
					after[i][j] = '.';
				}
			}
		}
	}
	
	int ly = 22, lx=  22, ry = -1, rx = -1; //섬이 있는 위치

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (after[i][j] == 'X') {
				lx = min(lx, j);
				ly = min(ly, i);
				ry = max(ry, i);
				rx = max(rx, j);
			}
		}
	}

	for (int i = ly; i <= ry; i++) {
		for (int j = lx; j <= rx; j++) {
			cout << after[i][j]; 
		}
		cout << '\n';
	}
	

	return 0;
}