#include<bits/stdc++.h>

using namespace std;

string N;
int dp[50505];


int solve(int idx) {
	if (N[idx] - '0' == 0) return 0; //한 자리수가 0인 경우는 알파벳이 X 
	if (idx == N.size()) { //1가지가 가능하므로 return 1;
		return 1;
	}

	int& ret = dp[idx];
	
	if (ret != -1) {
		return ret;
	}
	ret = 0;

	if (idx + 1 <= N.size()) {
		int first = stoi(N.substr(idx, 1)); //첫번째 자리수
		if (first >= 1 && first <= 26) {
			ret = solve(idx + 1) % 1000000;
		}
	}

	if (idx + 2 <= N.size()) {
		int second = stoi(N.substr(idx, 2)); //십의 자리수
		if (second >= 1 && second <= 26) {
			ret = (ret + solve(idx + 2)) % 1000000;
		}
	}

	return ret;
}


int main(void) {
	cin >> N;
	memset(dp, -1, sizeof(dp));
	if (N[0] == '0') cout << "0\n";
	else {
		cout << solve(0) % 1000000 << "\n";
	}
	return 0;
}