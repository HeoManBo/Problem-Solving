#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>
using namespace std;
string str;
int N;
long long  arr[101];
long long  dp[101][21]; // 현재 수가 올바른 등식을 만들 수 있는 가지의 수   

long long solve(int idx, int sum) {
	if (idx == N-1) {
		return sum == arr[idx] ? 1 : 0;
	}
	long long& ret = dp[idx][sum];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	//더하기의 경우 더해서 넘겨본다
	if (sum + arr[idx] <= 20) {
		ret += solve(idx + 1, sum + arr[idx]);
	}
	//빼기의 경우 빼서 넘겨본다
	if (sum - arr[idx] >= 0) {
		ret += solve(idx + 1, sum - arr[idx]);
	}
	return ret;
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(1, arr[0]) << "\n";
	return 0;
}