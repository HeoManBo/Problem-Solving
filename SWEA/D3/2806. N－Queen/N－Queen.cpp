#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int T, N;
bool queen[11][11];
int ans = 0;

int dy[] = { -1, -1, 1, 1 };
int dx[] = { -1, 1, -1 , 1 };

bool canPlace(int y, int x) { //y,x에 퀸을 둘 수 있는지 확인한다.
	//같은 열에 있는지 확인
	for (int i = 1; i <= N; i++) {
		if (queen[i][x]) return false;
	}
	
	//같은 행에 있는지 확인
	for (int i = 1; i <= N; i++) {
		if (queen[y][i]) return false;
	}

	//대각선 확인
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		while (ny >= 1 && nx >= 1 && ny <= N && nx <= N) {
			if (queen[ny][nx]) return false;
			ny += dy[i];
			nx += dx[i];
		}
	}

}

void go(int y) {
	if (y == N + 1) { //1~N까지의 퀸을 두는 방법이 있다면
		ans++;
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (canPlace(y, i)) {
			queen[y][i] = true;
			go(y + 1);
			queen[y][i] = false;
		}
	}

}

int main(void) {
	//freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			queen[1][i] = true; //1열은 i번째 열에 추가
			go(2);
			queen[1][i] = false;
		}

		printf("#%d %d\n", i, ans);
		ans = 0;
		memset(queen, 0, sizeof(queen));
	}
}