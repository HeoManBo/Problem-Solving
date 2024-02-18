#include<bits/stdc++.h>

using namespace std;

int N, arr[6], total;
long long dp[6][6][11][11][11][11][11]; // dp[i] -> i번째 구슬을 놓을 때 do[i][i-1], dp[i][i-2] -> 이전에 뭘 놨는지

long long go(int now, int first, int second) { // first 이전에 놓은 구슬, second : first 이전에 놓은 구슬 
	if (now == total) { //모든 구슬을 이었다면 
		return 1;
	}

	long long& ret = dp[first][second][arr[1]][arr[2]][arr[3]][arr[4]][arr[5]];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 1; i <= N; i++) {
		if (arr[i] != 0) {
			if (i != first && i != second) {
				arr[i]--;
				ret += go(now + 1, second, i);
				arr[i]++;
			}
		}
	}

	return ret;
}

int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		total += arr[i]; //전체 구슬 개수 
	}
	memset(dp, -1, sizeof(dp));
	cout << go(0, 0, 0) << '\n';

	return 0;
}