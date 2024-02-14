#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> arr;

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		arr.push_back(n);
	}
	sort(arr.begin(), arr.end());
	long long ans = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			int tmp = arr[i] + arr[j];
			long long u = upper_bound(arr.begin() + j + 1, arr.end(), -tmp) - arr.begin();
			long long v = lower_bound(arr.begin() + j + 1, arr.end(), -tmp) - arr.begin();
			ans += (u - v);
		}
	}
	cout << ans << '\n';

	return 0;
}