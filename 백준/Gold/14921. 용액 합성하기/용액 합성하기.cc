#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int N, arr[111'111];

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int l = 0, r = N - 1;
	int ans = arr[l] + arr[r];
	while (l < r) {
		int mid = (arr[l] + arr[r]);
		if (abs(mid) < abs(ans)) {
			ans = mid;
			if (mid == 0) break;
		}
		if (mid > 0) {
			r--;
		}
		else {
			l++;
		}
	}
	cout << ans << '\n';

	return 0;
}