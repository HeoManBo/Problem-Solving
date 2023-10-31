#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

struct horse {
	int y;
	int x;
	int dir;
	int num;
};

int color[22][22];
vector<horse> map[22][22];
int N, K;
vector<horse> info;

int dy[] = { -1,0,0,-1,1 };
int dx[] = { -1,1,-1,0,0 };

void white(struct horse& h);
void red(struct horse& h);

bool isIn(int y, int x) {
	return y >= 1 && y <= N && x >= 1 && x <= N;
}

void blue(struct horse& h) {
	//이동 방향을 반대로 바꿈
	if (h.dir == 1) {
		h.dir = 2;
		info[h.num - 1].dir = 2;
	}
	else if (h.dir == 2) {
		h.dir = 1;
		info[h.num - 1].dir = 1;
	}
	else if (h.dir == 3) {
		h.dir = 4;
		info[h.num - 1].dir = 4;
	}
	else {
		h.dir = 3;
		info[h.num - 1].dir = 3;
	}

	int ny = h.y + dy[h.dir];
	int nx = h.x + dx[h.dir];

	if (color[ny][nx] == 2 || !isIn(ny,nx)) { //방향을 바꾼 뒤에도 이동하려는 칸이 파란색 or 맵 밖인 경우
		return;
	}

	if (color[ny][nx] == 0) { 
		white(h);
	}

	if (color[ny][nx] == 1) {
		red(h);
	}

}

void white(struct horse& h) {
	int ny = h.y + dy[h.dir];
	int nx = h.x + dx[h.dir];
	int y = h.y;
	int x = h.x;
	int h_num = h.num;
	h.y = ny;
	h.x = nx;
	info[h_num-1].y = ny;
	info[h_num-1].x = nx;
	if (map[y][x].size() > 1) { //해당 위치에 말이 여러 개 있는 경우 
		int horse_position = 0;
		for (int i = 0; i < map[y][x].size(); i++) { //말의 위치를 찾는다.
			if (h_num == map[y][x][i].num) {
				horse_position = i;
				break;
			}
		}
		//해당 말 위치에서부터 위에있는 말들을 꺼낸다
		vector<horse> move_hourses;
		for (int i = horse_position; i < map[y][x].size(); i++) {
			info[map[y][x][i].num - 1].y = ny;
			info[map[y][x][i].num - 1].x = nx;
			move_hourses.push_back(info[map[y][x][i].num-1]);
		}
		//꺼낸 말을 지금 위치에서 제거
		for (int i = 0; i < move_hourses.size(); i++) {
			map[y][x].pop_back();
		}
		// 다음 위치에 쌓음 
		for (int i = 0; i < move_hourses.size(); i++) {
			map[ny][nx].push_back(info[move_hourses[i].num - 1]);
		}
	}
	else if(map[y][x].size() == 1){ // 해당 위치에 움직이려는 말이 하나 밖에 없으면 
		map[ny][nx].push_back(info[h_num - 1]);
		map[y][x].pop_back();
	}
}

void red(struct horse& h) {
	int ny = h.y + dy[h.dir];
	int nx = h.x + dx[h.dir];
	int y = h.y;
	int x = h.x;
	int h_num = h.num;
	h.y = ny;
	h.x = nx;
	info[h_num-1].y = ny;
	info[h_num-1].x = nx;
	if (map[y][x].size() > 1) { //해당 위치에 말이 여러 개 있는 경우 
		int horse_position = 0;
		for (int i = 0; i < map[y][x].size(); i++) { //말의 위치를 찾는다.
			if (h_num == map[y][x][i].num) {
				horse_position = i;
				break;
			}
		}
		//해당 말 위치에서부터 위에있는 말들을 꺼낸다
		vector<horse> move_hourses;
		for (int i = horse_position; i < map[y][x].size(); i++) {
			info[map[y][x][i].num - 1].y = ny;
			info[map[y][x][i].num - 1].x = nx;
			move_hourses.push_back(info[map[y][x][i].num - 1]);
		}
		//꺼낸 말을 지금 위치에서 제거
		for (int i = 0; i < move_hourses.size(); i++) {
			map[y][x].pop_back();
		}
		// 다음 위치에 쌓음 이때 빨간색이므로 거꾸로 쌓음 
		for (int i = move_hourses.size() - 1; i >= 0; i--) {
			map[ny][nx].push_back(info[move_hourses[i].num-1]);
		}
	}
	else if(map[y][x].size()==1){ // 해당 위치에 움직이려는 말이 하나 밖에 없으면 
		map[ny][nx].push_back(info[h_num-1]);
		map[y][x].pop_back();
	}
}

bool go(struct horse& h) {
	int ny = h.y + dy[h.dir];
	int nx = h.x + dx[h.dir];
	
	if (isIn(ny,nx)) {
		if (color[ny][nx] == 0) { //흰색인 경우 
			white(h);
		}
		else if (color[ny][nx] == 1) { //빨간색 인경우 
			red(h);
		}
		else if (color[ny][nx] == 2) { //파란색 인경우 
			blue(h);
		}
	}
	else { //다음에 이동하려는 위치가 맵밖이면 파란색으로 처리 
		blue(h);
	}

	if (map[h.y][h.x].size() >= 4) { //이동 후 해당 좌표의 말의 개수가 4개 이상이라면 
		return true;
	}

	return false;
}

int main(void) {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> color[i][j];
		}
	}

	for (int i = 1; i <= K; i++) {
		int row, col, dir;
		cin >> row >> col >> dir;
		info.push_back({ row,col,dir, i});
		map[row][col].push_back(info[(i-1)]);
	}

	for (int k = 1; k <= 1000; k++) {
		for (int i = 0; i < info.size(); i++) {
			if (go(info[i])) {
				cout << k << '\n';
				return 0;
			}
		}
	}

	cout << "-1\n";
	return 0;
}