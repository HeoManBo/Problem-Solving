#include<iostream>
#include<cstring>

using namespace std;

int N, M, K;  
string m[111], s; 
int dp[111][111][111]; // s[i][j] 문자가 주어진 문자열에 K 번째로 같을때, 추후 만들 수 있는 문자의 개수 
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int solve(int y, int x, int idx) {
	if (idx == s.length()) { //모든 문자열이 같으면
		return 1;
	}

	int& ret = dp[y][x][idx];
	if (ret != -1) return ret;
	
	ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y;
		int nx = x;
		//4 방향에 대해
		for (int k = 1; k <= K; k++) {
			ny += dy[i];
			nx += dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) break;
			if (m[ny][nx] == s[idx]) {
				ret += solve(ny, nx, idx + 1);
			}
		}
	}

	return ret;
}



int main(void)
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> m[i];
	}
	memset(dp, -1, sizeof(dp));
	cin >> s;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (m[i][j] == s[0]) { //첫 번째 문자열이 같으면 탐색 시도
				ans += solve(i, j, 1);
			}
			else {
				dp[i][j][1] = 0;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}