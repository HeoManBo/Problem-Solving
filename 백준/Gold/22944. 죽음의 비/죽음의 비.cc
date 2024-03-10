#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

struct info {
	int y;
	int x;
	int health;
	int defence;
	int cnt;
};

int N, H, D;
pair<int, int> start;
string road[555];
int power[555][555];
int ans = 0x3f3f3f3f;
int dy[] = { 0,0, 1,-1 };
int dx[] = { 1,-1,0,0 };

int main(void)
{
	cin >> N >> H >> D;
	for (int i = 0; i < N; i++) {
		cin >> road[i];
		for (int j = 0; j < N; j++) {
			if (road[i][j] == 'S') {
				start = { i,j }; //시작점 
			}
		}
	}
	memset(power, -1, sizeof(power));
	power[start.first][start.second] = H;
	queue<info> q;
	q.push({ start.first, start.second, H,  0, 0 });
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int h = q.front().health;
		int d = q.front().defence;
		int cnt = q.front().cnt;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

			// 도착한 경우
			if (road[ny][nx] == 'E') {
				ans = min(ans, cnt + 1);
				continue;
			}

			// 그외의 경우는 체력을 깎거나 방어를 깎음
			int nd = d;
			int nh = h;

			// 우산
			if (road[ny][nx] == 'U') {
				nd = D;
			}

			if (nd >= 1) { //방어력이 1이상 남아있는 경우
				nd -= 1;
			}
			else { 
				nh -= 1;
			}

			//죽은 경우 
			if (nh == 0) continue;

			if (power[ny][nx] < nd + nh) {
				power[ny][nx] = nd + nh;
				q.push({ ny, nx, nh, nd, cnt+1 });
			}
		}
	}

	cout << (ans == 0x3f3f3f3f ? -1 : ans) << '\n';
	return 0;
}