#include<bits/stdc++.h>

using namespace std;

int N, K;
int arr[222][222];
pair<int,int> virus[202][202]; // {i,j}에서의 first : 바이러스 번호 second : 바이러스가 몇 초에 침투했는지 
vector<pair<int, int>> init[1010];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

void v() { //각 바이러스가 몇 초에 퍼지는지 전부 체크한다.
	queue<pair<int, int>> q;

	for (int i = 1; i <= K; i++) {
		for (auto x : init[i]) {
			q.push(x);
		}
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny > N || nx > N || ny < 1 || nx < 1) continue;
			if (virus[ny][nx].first != -1) continue;
			virus[ny][nx].first = virus[y][x].first;
			virus[ny][nx].second = virus[y][x].second + 1;
			q.push({ ny, nx });
		}
	}

}

int main(void)
{
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			virus[i][j] = { -1, -1 };
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0) {
				virus[i][j] = { arr[i][j], 0 };
				init[arr[i][j]].push_back({ i,j });
			}
		}
	}


	v();

	int S, X, Y;
	cin >> S >> X >> Y;
	int ans = 0;
	for (int i = 1; i <= K; i++) {
		if (virus[X][Y].second != -1 && virus[X][Y].second <= S) {
			ans = virus[X][Y].first;
			break;
		}
	}

	cout << ans << '\n';

	return 0;
}