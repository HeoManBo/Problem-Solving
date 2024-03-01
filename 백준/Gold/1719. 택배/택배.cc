#include<bits/stdc++.h>

using namespace std;

int N, M, arr[222][222], path[222][222];
const int INF = 0x3f3f3f3f;
int main(void)
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) arr[i][j] = 0;
			else arr[i][j] = INF;
		}
	}
	
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
		arr[b][a] = c;
		path[a][b] = b;
		path[b][a] = a;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
                // arr[i][k] 의 최단 경로시작점은 path[i][k]이다. 
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					path[i][j] = path[i][k];
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) cout << "- ";
			else cout << path[i][j] << " ";
		}
		cout << '\n';
	}

		return 0;

}