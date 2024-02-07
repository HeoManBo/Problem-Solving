#include<bits/stdc++.h>
using namespace std;

int N, M, H, milk_size;
int board[11][11];
pair<int, int> house;
vector<pair<int, int>> milk;
int ans = 0;
bool chk[11];


int dist(int y, int x, int yy, int xx) { //y,x에서 집까지의 거리
	return abs(y - yy) + abs(x - xx);
}

void solve(int y, int x, int power, int eat) {
	if (power >= dist(y, x, house.first, house.second)) {
		ans = max(ans, eat); //돌아올 수 있다면
	}	

	for (int i = 0; i < milk_size; i++) {
		if (!chk[i]) { //i번째 우유를 안먹었다면
			chk[i] = true;
			int d = dist(y, x, milk[i].first, milk[i].second); //다음 우유가 있는 곳까지 거리
			if (power - d >= 0) {
				solve(milk[i].first, milk[i].second, power - d + H, eat + 1);
			}
			chk[i] = false;
		}
	}
}




int main(void) {
	cin >> N >> M >> H;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num; cin >> num;
			if (num == 1) {
				house = { i,j };
			}
			else if (num == 2) {
				milk.push_back({ i,j });
			}
		}
	}
	milk_size = milk.size();
	solve(house.first, house.second, M, 0);

	cout << ans << '\n';

	return 0;
}