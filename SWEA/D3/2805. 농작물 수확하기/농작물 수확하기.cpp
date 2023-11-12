#include<iostream>
#include<set>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

int T, N;
int arr[50][50];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
int ans = 0, center ;
void solve(int y, int x) {
	int dist = abs(center - y); //중앙에서 얼마나 떨어져 있는지
	for (int i = dist + 1; i <= (N - dist); i++) {
		ans += arr[y][i];
	}
}

int main(void) {
	cin >> T;
	for (int iter = 1; iter <= T; iter++) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%1d", &arr[i][j]);
			}
		}
		center = (N / 2) + 1;
		for (int i = center - 1; i >= 1; i--) {
			solve(i, center);
		}
		for (int i = center + 1; i <= N; i++) {
			solve(i, center);
		}
		for (int i = 1; i <= N; i++) {
			ans += arr[center][i];
		}
		printf("#%d %d\n", iter, ans);
		ans = 0;
	}

	return 0;
}