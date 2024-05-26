#include<bits/stdc++.h>
using namespace std;

int N;
int arr[1111][1111];
int dp[1111][1111][4]; //이전에 뭘 마셨는지

int solve(int y, int x, int type) { //이번에 마셔야 할 우유 
	if (y > N || x > N) return 0; //맵 밖
	if (y == N && x == N) { //종점에 도착한경우
		if (type == arr[y][x]) {
			return 1;
		}
		return 0;
	}

	int& ret = dp[y][x][type];
	if (ret != -1) return ret;
	ret = 0;
	int chk = type == arr[y][x] ? 1 : 0; //y,x 좌표의 우유를 마실 수 있는지
	int next_type = type == arr[y][x] ? (arr[y][x]+1)%3 : type; //다음에 뭘 마셔야 할지

	//동쪽이동 
	ret = max(ret, solve(y, x + 1, next_type) + chk);
	//남쪽이동
	ret = max(ret, solve(y + 1, x, next_type) + chk);

	return ret;
}

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(1, 1, 0) << '\n';

	return 0;
}