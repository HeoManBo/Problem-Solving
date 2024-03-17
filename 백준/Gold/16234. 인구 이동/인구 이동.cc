#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

int N, L, R;
int pop[55][55];
bool chk[55][55];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

bool inRange(int y, int x, int yy, int xx) { //두 마을의 인구 차이가 L <= X <= R 인지 확인함.
	int diff = abs(pop[y][x] - pop[yy][xx]);
	return diff >= L && diff <= R;
}

// [y][x] 나라에서 인구 이동이 발생하는지 확인한다.
bool makeAsso(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	chk[y][x] = true;
	vector<pair<int, int>> u; //이번에 연합될 리스트 모음
	u.push_back({ y,x });
	int sum = pop[y][x]; //연합의 전체 인ㄱ수 
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (!chk[ny][nx] && inRange(y, x, ny, nx)) { 
				chk[ny][nx] = true;
				q.push({ ny, nx });
				u.push_back({ ny,nx });
				sum += pop[ny][nx];
			}
		}
	}

	if (u.size() == 1) { //아무도 연합을 생성하지 못하면 false;
		return false;
	}

	//인구수 평균화
	int avg = sum / u.size();
	for (int i = 0; i < u.size(); i++) {
		pop[u[i].first][u[i].second] = avg;
	}

	return true;
}

int main(void)
{
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> pop[i][j];
		}
	}
	
	int day = 0;
	while (true) {
		bool flag = false;
		memset(chk, 0, sizeof(chk));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!chk[i][j] && makeAsso(i, j)) {
					flag = true;
				}
			}
		}

		if (flag) day++;
		else break;
	}

	cout << day << '\n';

	return 0;
}