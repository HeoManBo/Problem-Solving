#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int T, n, arr[2][101010];
int dp[101010][3]; // dp[i][j] ->


//  solve(row,C) -> row-1 열에 있는 스티커를 C가지 케이스에 따라 뗏을때 row열에는 무슨 스티커를 땔 수 있을까?
// C : 0 -> row열에 위/아래 스티커를 아무거나 때거나, 때지 않음 
// C : 1 - > row열의 위쪽 스티커를 때거나/때지 않음
// C : 2 -> row열의 아래쪽 스티커를 때거나/때지 않음 

int solve(int row, int C) {
	if (row == n) return 0; // 기저 사례
	int& ret = dp[row][C];
	if (ret != -1) return ret; //memorization

	ret = solve(row+1, 0); //때지 않음 떼지 않은 경우는 이전 row에서 어떤 행위를 하던 모두 할 수 있음

	if (C != 1) {  
		ret = max(ret, solve(row + 1, 1) + arr[0][row]);
	}
	if (C != 2) {  
		ret = max(ret, solve(row + 1, 2) + arr[1][row]);
	}
	return ret;
}

int main(void) {

	cin >> T;
	while (T--) {
		cin >> n;
		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < n; i++) {
				cin >> arr[j][i];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				dp[i][j] = -1;
			}
		}
		cout << solve(0, 0) <<  "\n";
		memset(arr, 0, sizeof(arr));
	}
}