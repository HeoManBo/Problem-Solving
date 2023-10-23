#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int N, M, K;
int board[222][222];
vector<int> cities;
int INF = 0x3f3f3f3f;
int main(void) {
	cin >> N >> M;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == j) board[i][j] = 0;
			else board[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		board[a][b] = c;
	}

	cin >> K;
	cities.resize(K+1);
	for (int i = 1; i <= K; i++) {
		cin >> cities[i];
	}

	//floyd-warshal
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
			}
		}
	}

	vector<int> ans;
	int max_value = INF;
	for (int i = 1; i <= N; i++) {
		//i번 도시까지 가는데 최대가 되는 위치를 구한다
		int cant_reached = false; //한 명이라도 갈 수 없는 도시라면 pass
		int MAXI = -1;
		for (int j = 1; j <= K; j++) {
			if (board[cities[j]][i] == INF || board[i][cities[j]] == INF) { //한 명이라도 갈 수 없는 도시라면 pass
				cant_reached = true;
				break;
			}
			//i번째 도시로 가는 친구의 최대 시간을 구함
			MAXI = max(MAXI, board[cities[j]][i] + board[i][cities[j]]);
		}
		if (!cant_reached) { //모든 친구들이 도달할 수 있다면
			//최대 시간중 최소시간 계산
			if (max_value > MAXI) {
				max_value = MAXI;
				ans.clear();
				ans.push_back(i);
			}
			else if (max_value == MAXI) {
				ans.push_back(i);
			}
		}
	}
	for (int citi : ans) {
		cout << citi << ' ';
	}
	cout << "\n";
	return 0;
}