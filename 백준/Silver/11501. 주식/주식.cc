#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int arr[1'001'001];

int main(void) {
	int T, N;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		long long ans=0, max_stock = 0;
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> arr[j];
		}
		for (int k = N - 1; k >= 0; k--) {
			if (arr[k] < max_stock) {
				ans += max_stock - arr[k];
			}
			else {
				max_stock = arr[k];
			}
		}
		cout << ans << '\n';
	}

	return 0;
}