#include<bits/stdc++.h>
#define MALE 1
#define FEMALE 2
using namespace std;

int N, arr[111'111];
long long presum[111'111];
long long dp[111'111][4];

int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		presum[i] = presum[i - 1] + arr[i];
	}

	if (presum[N] % 4 != 0) {
		cout << "0\n";
		return 0;
	}
	else {
		if (presum[N] == 0) {
			cout << ((long long)(N-1) * (N - 2) * (N - 3)) / 6 << '\n';
			return 0;
		}
	}

	return 0;
}