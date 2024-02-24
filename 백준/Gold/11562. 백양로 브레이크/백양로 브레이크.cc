#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;


int N, M;
int board[255][255], INF = 987654321;


void solve() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (board[i][j] > board[i][k] + board[k][j]) {
					board[i][j] = board[i][k] + board[k][j];
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) board[i][j] = 0;
			else board[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		int u, v, b;
		cin >> u >> v >> b;
		if (b == 0) {
			board[u][v] = 0;
			board[v][u] = 1;
		}
		else if(b == 1){
			board[u][v] = 0;
			board[v][u] = 0;
		}
	}

	solve();

	int k;
	cin >> k;
	while (k--) {
		int s, e;
		cin >> s >> e;
		cout << board[s][e] << "\n";
	}
	return 0;
}