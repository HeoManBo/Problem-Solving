#include<bits/stdc++.h>

using namespace std;

int N;
int arr[11'111];
int nation;
int sum, l=0x3f3f3f3f, r;
int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		r = max(r, arr[i]);
		sum += arr[i];
	}

	cin >> nation;
	if (nation > sum) {
		cout << r << '\n';
		return 0;
	}
	l = 1;
	int ans = 0;
	while (l <= r) {
		int upper = (l + r) / 2; //상한액
		int tmp = 0;
		for (int i = 0; i < N; i++) { //상한액으로 다 나눠줬을 때 nation에 최대한 근접하게 만든다
			if (upper < arr[i]) { //상한액 보다 더 많이 요구하면 상한액을 ㅗ배정
				tmp += upper;
			}
			else tmp += arr[i]; //상한액보다 적게 요구하면 그대로 배정
		}
		if (tmp > nation) { //상한액을 배정했는데도 예산보다 더 많이 필요하면
			r = upper - 1;
		}
		else {
			ans = max(ans, upper);
			l = upper + 1;
		}
	}
	cout << ans << '\n';

	return 0;
}