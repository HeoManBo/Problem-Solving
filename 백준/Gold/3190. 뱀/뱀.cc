#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int N, K, L;
queue<pair<int, char>> m;
deque<pair<int, int>> dq;

// D, D, D, D
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0,-1, 0 };
int arr[111][111];
int dir = 0; //시작 dir

bool reachBody(int y, int x) {
	for (int i = 0; i < dq.size(); i++) {
		pair<int, int> pos = dq[i];
		if (pos.first == y && pos.second == x) {
			return true;
		}
	}
	
	return false;
}

void rotateSnake(char d) {
	if (d == 'D') { //오른쪽인 경우
		if (dir == 0) {
			dir = 1;
		}
		else if (dir == 1) {
			dir = 2;
		}
		else if (dir == 2) {
			dir = 3;
		}
		else if (dir == 3) {
			dir = 0;
		}
	}
	else if (d == 'L') { // 왼쪽 케이스
		if (dir == 0) {
			dir = 3;
		}
		else if (dir == 1) {
			dir = 0;
		}
		else if (dir == 2) {
			dir = 1;
		}
		else if(dir == 3){
			dir = 2;
		}
	}
}

int main(void)
{
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		arr[r][c] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int x;
		char c;
		cin >> x >> c;
		m.push({ x,c });
	}

	dq.push_back({ 1,1 }); //시작점
	int t = 1;

	while (true) {
		auto xx = dq.front();
		// 현재 헤드 위치
		int y = xx.first;
		int x = xx.second;
		
		// 다음 헤드 위치
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		// 벽에 부딪히는지 확인
		if (ny <= 0 || nx <= 0 || ny > N || nx > N) {
			break;
		}

		//몸에 부딪히는지 확인
		if (reachBody(ny, nx)) {
			break;
		}

		//다음 위치에 사과 있는지 확인
		dq.push_front({ ny,nx });
		if (arr[ny][nx] == 1) { 
			arr[ny][nx] = 0; //사과 섭취
		}
		else { //사과 없으면 맨 뒤에꺼 제거
			dq.pop_back();
		}
		
		if (m.size() != 0) {
			auto ro = m.front();
			if (ro.first == t) { //회전할 시간이면
				m.pop();
				rotateSnake(ro.second);
			}
		}

		t++;
	}

	cout << t << '\n';
	return 0;
}
