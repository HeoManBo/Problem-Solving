#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
#include<queue>
using namespace std;

struct info {
	int y;
	int x;
	int memory;
	int dir;
};

int T, R, C;
char arr[22][22];
bool mm[22][22][20][4];
int can = 0;
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

void bfs() {
	queue<info> q;
	q.push({ 1,1,0,0 });
	mm[1][1][0][0] = true;
	while (!q.empty()) {
		auto xx = q.front();
		q.pop();
		int y = xx.y;
		int x = xx.x;
		int m = xx.memory;
		int dir = xx.dir;

		if (arr[y][x] == '@') {
			can = 1;
			return;
		}

		char cmd = arr[y][x];
		int nd=dir, nm = m;

		if (cmd == '^') {
			nd = 3;
		}
		else if (cmd == 'v') {
			nd = 2;
		}
		else if (cmd == '>') {
			nd = 0;
		}
		else if (cmd == '<') {
			nd = 1;
		}
		else if (cmd == '_') nd = (m == 0 ? 0 : 1);
		else if (cmd == '|') nd = (m == 0 ? 2 : 3);
		else if (isdigit(cmd)) nm = cmd - '0';
		else if (cmd == '+') nm = (m == 15 ? 0 : nm + 1);
		else if (cmd == '-') nm = (m == 0 ? 15 : nm - 1);

		if (cmd == '?') {
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 1) ny = R;
				else if (ny > R) ny = 1;
				if (nx < 1) nx = C;
				else if (nx > C) nx = 1;

				if (!mm[ny][nx][nm][i]) {
					mm[ny][nx][nm][i] = true;
					q.push({ ny, nx, nm, i });
				}

			}
		}	
		else {
			int ny = y + dy[nd];
			int nx = x + dx[nd];

			if (ny < 1) ny = R;
			else if (ny > R) ny = 1;
			if (nx < 1) nx = C;
			else if (nx > C) nx = 1;

			if (!mm[ny][nx][nm][nd]) {
				mm[ny][nx][nm][nd] = true;
				q.push({ ny, nx, nm, nd });
			}
		}
	}

	return;
}


void init() {
	can = 0;
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			arr[i][j] = '\0';
		}
	}
	memset(mm, false, sizeof(mm));
}

int main(void) {
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int golbange = 0;
		init();

		cin >> R >> C;
		for (int i = 1; i <= R; i++) {
			string s;
			cin >> s;
			for (int j = 1; j <= s.size(); j++) {
				arr[i][j] = s[j - 1];
				if (arr[i][j] == '@') {
					golbange++;
				}
			}
		}

		if (golbange == 0) {
			cout << '#' << i << ' ' << "NO\n";
			continue;
		}

		bfs();

		if (can) {
			cout << '#' << i << ' ' << "YES\n";
		}
		else {
			cout << '#' << i << ' ' << "NO\n";
		}
	}
	
	return 0;
}

//void go(int y, int x, int dir) {
//	if (can) return;
//	if (mm[y][x][memory][dir]) return;
//
//	if (y < 1) return go(R, x, dir);
//	if (y > R) return go(1, x, dir);
//	if (x < 1) return go(y, C, dir);
//	if (x > C) return go(y, 1, dir);
//
//	if (arr[y][x] == '@') {
//		can = 1;
//		return;
//	}
//
//	mm[y][x][memory][dir] = true;
//
//	// 숫자인 경우
//	if (isdigit(arr[y][x])) {
//		memory = arr[y][x] - '0';
//		 go(y + dy[dir], x + dx[dir], dir);
//	}
//	else if (arr[y][x] == '<') {
//		dir = 1;
//		 go(y + dy[dir], x + dx[dir], dir);
//	}
//	else if (arr[y][x] == '>') {
//		dir = 0;
//		go(y + dy[dir], x + dx[dir], dir);
//	}
//	else if (arr[y][x] == '^') {
//		dir = 3;
//		 go(y + dy[dir], x + dx[dir], dir);
//	}
//	else if (arr[y][x] == 'v') {
//		dir = 2;
//		 go(y + dy[dir], x + dx[dir], dir);
//	}
//	else if (arr[y][x] == '_') {
//		if (memory == 0) {
//			dir = 0;
//			 go(y + dy[dir], x + dx[dir], dir);
//		}
//		else {
//			dir = 1;
//			 go(y + dy[dir], x + dx[dir], dir);
//		}
//	}
//	else if (arr[y][x] == '|') {
//		if (memory == 0) {
//			dir = 2;
//			 go(y + dy[dir], x + dx[dir], dir);
//		}
//		else {
//			dir = 3;
//			 go(y + dy[dir], x + dx[dir], dir);
//		}
//	}
//	else if (arr[y][x] == '?') {
//		bool flag[4] = { false, };
//		for (int i = 0; i < 4; i++) {
//			int ny = y + dy[i];
//			int nx = x + dx[i];
//			dir = i;
//			go(ny, nx, dir);
//		}
//	}
//	else if (arr[y][x] == '.') {
//		return go(y + dy[dir], x + dx[dir], dir);
//	}
//	else if (arr[y][x] == '+') {
//		if (memory == 15) {
//			memory = 0;
//		}
//		else {
//			memory++;
//		}
//		go(y + dy[dir], x + dx[dir], dir);
//	}
//	else if (arr[y][x] == '-') {
//		if (memory == 0) {
//			memory = 15;
//		}
//		else {
//			memory--;
//		}
//		go(y + dy[dir], x + dx[dir], dir);
//	}
//}
