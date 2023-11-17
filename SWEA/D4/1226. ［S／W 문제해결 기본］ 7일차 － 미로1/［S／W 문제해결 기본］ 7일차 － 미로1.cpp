	#include <iostream>
	#include<algorithm>
#include<queue>
	using namespace std;

	int arr[105][101];
	pair<int, int> start, target;
	int dy[] = { 0,0,1,-1 };
	int dx[] = { 1,-1,0,0 };

	int bfs() {
		queue<pair<int, int>> q;
		q.push(start);
		bool chk[17][17] = { false, };
		chk[start.first][start.second] = true;
		while (!q.empty()) {
			auto xx = q.front();
			q.pop();
			int y = xx.first;
			int x = xx.second;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (arr[ny][nx] == 0) {
					if (!chk[ny][nx]) {
						chk[ny][nx] = true;
						q.push({ ny,nx });
					}
				}
				else if (arr[ny][nx] == 3) {
					return true;
				}
			}
		}
		return 0;
	}


	int main(void) {
		int a;
		for (int i = 1; i <= 10; i++) {
			cin >> a;
			for (int i = 0; i < 16; i++) {
				for (int j = 0; j < 16; j++) {
					scanf("%1d", &arr[i][j]);
					if (arr[i][j] == 2) {
						start = { i,j };
					}
					if (arr[i][j] == 3) {
						target = { i,j };
					}
				}
			}

			printf("#%d %d\n", i, bfs());
		}
	}