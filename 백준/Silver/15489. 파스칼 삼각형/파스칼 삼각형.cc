#include<bits/stdc++.h>
using namespace std;

int arr[33][33];

int main(void) {
	int R,C,W;
	cin >> R >> C >> W;
	arr[1][1] = 1;
	
	for (int i = 2; i <= 30; i++) {
		for (int j = 1; j <= i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	int w = 0;
	int ans = 0;
	for (int r = R; r < R + W; r++) {
		for (int j = C; j <= C+w; j++) {
			ans += arr[r][j];
		}
		w++;
	}

	cout << ans << '\n';

	return 0;
}