#include<bits/stdc++.h>

using namespace std;

int N;
long long gas[111'111];
long long length[111'111];
long long ans = 0;

int main(void)
{
	cin >> N;
	length[0] = 0;
	for (int i = 1; i < N; i++) {
		cin >> length[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> gas[i];
	}

	ans = gas[0] * length[1]; //0번째 주유소에서 1번째까지 필요한 비용
	long long min_gas = gas[0];

	for (int i = 1; i < N-1; i++) {
		if (min_gas > gas[i]) { //이전에 넣었던 주유소보다 더 싸다면 
			min_gas = gas[i];
			ans += (min_gas * length[i+1]);
		}
		else { //이전에 넣었던 주유소가 더 싸다면 더 넣음
			ans += (min_gas * length[i+1]);
		}
	}
	cout << ans << '\n';

	return 0;
}