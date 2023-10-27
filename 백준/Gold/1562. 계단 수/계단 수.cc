#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

long long dp[100][10][1024]; // dp[i][j][k] : 현재 i번쨰 문자열 길이고, 현재 수는 j일때 0~9까지의 포함 유무 
int N;
long long DIV = 1'000'000'000;

long long solve(int length, int now, int include) {
	if (length == N) { //N번째 길이에 도달하고 0~9까지 수를 모두 포함했으면 
		if (include == ((1 << 10) - 1)) {
			return 1;
		}
		return 0;
	}
	
	long long& ret = dp[length][now][include];
	if (ret != -1) return ret;
	ret = 0;
	if (now < 9) { //9미만이면 +! 붙이기 가능 
		ret += solve(length + 1, now + 1, include | (1 << (now + 1))); 
	}
	if (now > 0) { //0초과면 -1 붙이기 가능
		ret += solve(length + 1, now - 1, include | (1 << (now - 1)));
	}
	ret %= DIV;
	return ret;
}

int main(void) {
	cin >> N;
	memset(dp, -1, sizeof(dp));
	long long ans = 0;
	for (int i = 1; i <= 9; i++) {
		ans += (solve(1, i, 1 << i));
		ans %= DIV;
	}
	cout << ans << '\n';

	return 0;
}