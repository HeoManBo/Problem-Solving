#include<iostream>
#include<set>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

int T, N;
int ladder[111][111];
int dx[] = { 0, 1, -1 };
int dy[] = { 1, 0, 0 };

bool solve(int start, int y, int x) {
	int dir = 0;

	while (y != 100) {
		if (dir == 0) {
			if (x + 1 >= 1 && x + 1 <= 100 && ladder[y][x + 1] == 1) {
				dir = 1;
				x += dx[dir];
				y += dy[dir];
			}
			else if (x - 1 >= 1 && x - 1 <= 100 && ladder[y][x - 1] == 1) {
				dir = 2;
				x += dx[dir];
				y += dy[dir];
			}
			else {
				x += dx[dir];
				y += dy[dir];
				if (y == 100 && ladder[y][x] == 2) {
					return true;
				}
				if (y == 100 && ladder[y][x] == 1) {
					return false;
				}
			}
		}
		else if (dir == 1) {
			if (x + 1 >= 1 && x + 1 <= 100 && ladder[y][x + 1] == 1) {
				dir = 1;
				x += dx[dir];
				y += dy[dir];
			}
			else {
				dir = 0;
				x += dx[dir];
				y += dy[dir];
				if (y == 100 && ladder[y][x] == 2) {
					return true;
				}
				if (y == 100 && ladder[y][x] == 1) {
					return false;
				}
			}
		}
		else if (dir == 2) {
			if (x - 1 >= 1 && x - 1 <= 100 && ladder[y][x - 1] == 1) {
				dir = 2;
				x += dx[dir];
				y += dy[dir];
			}
			else {
				dir = 0;
				x += dx[dir];
				y += dy[dir];
				if (y == 100 && ladder[y][x] == 2) {
					return true;
				}
				if (y == 100 && ladder[y][x] == 1) {
					return false;
				}
			}
		}
	}
	if (y == 100 && ladder[y][x] == 2) {
		return true;
	}
	if (y == 100 && ladder[y][x] == 1) {
		return false;
	}
}

int main(void) {
	int T_num;
	for (int i = 1; i <= 10; i++) {
		cin >> T_num;
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				cin >> ladder[i][j];
			}
		}

		for (int i = 1; i <= 100; i++) {
			if (ladder[1][i] == 1) {
				if(solve(i, 1, i)) {
					printf("#%d %d\n", T_num, (i-1));
				}
			}
		}
	}

	return 0;
}