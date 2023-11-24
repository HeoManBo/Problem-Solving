#include<bits/stdc++.h>

using namespace std;

int arr[1'001'001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		int l = 0, r = n - 1;
		int min_neast=0x3f3f3f3f, ans = 0;
		while (l < r) {
			int K = arr[l] + arr[r];
			if (K > k) {
				r--;
			}
			else {
				l++;
			}

			if (abs(k - K) < min_neast) {
				min_neast = abs(k - K);
				ans = 1;
			}
			else if (abs(k - K) == min_neast) {
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}