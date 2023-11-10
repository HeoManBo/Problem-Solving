#include<iostream>

using namespace std;


int arr[1'000'000];

int main(void) {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int N;
		cin >> N;
		int max_price = -1;
		long long sum = 0;
		for (int j = 0; j < N; j++) {
			cin >> arr[j];
		}
		for (int j = N - 1; j >= 0; j--) {
			if (arr[j] > max_price) {
				max_price = arr[j];
			}
			else {
				sum += max_price - arr[j];
			}
		}
		printf("#%d %lld\n", i, sum);
	}
	return 0;
}