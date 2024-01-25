#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int N, snow[666];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> snow[i];
	}

	sort(snow, snow + N);

	int ans = 0x3f3f3f3f;
	for (int i = 0; i < N - 3; i++) {
		for (int j = i+3; j < N; j++) {
			int elsa = snow[i] + snow[j]; //엘사 눈사람
			int l = i + 1;
			int r = j - 1;
			while (l <= r) {
				int anna = snow[l] + snow[r];
				ans = min(ans, abs(elsa - anna));
				if (elsa > anna) { //엘사가 눈사람이 더 크면 안나의 눈사람들 더 키운다
					l++;
				}
				else { //안나의 눈사람이 더 크면 엘사의 눈사람을 더 키운다 
					r--; 
				}
			}
		}
	}
	cout << ans << '\n';

	return 0;
}