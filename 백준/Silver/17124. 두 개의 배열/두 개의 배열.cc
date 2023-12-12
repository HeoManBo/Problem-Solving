#include<bits/stdc++.h>
using namespace std;

int T, N, M;
int A[1'111'111], B[1'111'111], C[1'111'111];

int main(void) {
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int j = 0; j < M; j++) {
			cin >> B[j];
		}
		sort(B, B + M);
		long long ans = 0;
		for (int i = 0; i < N; i++) {
			int cmp = A[i];
			int l = 0, r = M - 1, tmp = 0x3f3f3f3f, value;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (tmp > abs(cmp - B[mid])) {
					tmp = abs(cmp - B[mid]);
					value = B[mid];
				}
				else if (tmp == abs(cmp - B[mid])) {
					if (value > B[mid]) {
						value = B[mid];
					}
				}

				if (cmp > B[mid]) {
					l = mid + 1;
				}
				else {
					r = mid - 1;
				}
			}
			ans += value;
		}

		cout << ans << '\n';
	}
	return 0;
}