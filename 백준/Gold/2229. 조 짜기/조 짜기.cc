#include<bits/stdc++.h>

using namespace std;

int n;
int arr[1010];
int dp[1010];
int mx, mn;

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		mx = mn = arr[i];
		for (int j = i; j >= 0; j--) {
			mx = max(mx, arr[j]);
			mn = min(mn, arr[j]);
			dp[i + 1] = max(dp[i + 1], dp[j] + mx - mn);
		}
	}
	cout << dp[n];
	return 0;
}
