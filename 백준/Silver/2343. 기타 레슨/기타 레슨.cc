#include<bits/stdc++.h>

using namespace std;

int N, K;
int video[111'111];
long long sum = 0;
long long l = -1, r;
int main(void)
{
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> video[i];
		sum += video[i];
		l = max((int)l, video[i]);
	}

	r = sum;

	while (l <= r) {
		int cnt = 0;
		long long tmp_sum = 0;
		long long mid = (l + r) / 2; //하나의 블루레이 크기
		for (int i = 0; i < N; i++) { //최대 크기가 X인 블루레이를 몇 개 만들 수 있을까?
			if (tmp_sum + video[i] > mid) {
				tmp_sum = 0;
				cnt++;
			}
			tmp_sum += video[i];
		}
		if (tmp_sum != 0) cnt += 1; //마지막 처리 
		if (cnt > K) { // 최대 크기가 X인 블루레이를 K개 보다 더 많이 만들 수 있다면 최대 크기를 늘려본다
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}


	cout << l << '\n';

	return 0;
}