#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

using ll = long long;

int main(void)
{
	ll n, l, w, h;
	cin >> n >> l >> w >> h;
	double left = 0.0, right = 1'000'000'000;
	
	for (int i = 1; i < 10000; i++) {
		double mid = (left + right) / 2;
		//개수 구하기
		ll count = ((ll)(l / mid)) * ((ll)(w / mid)) * ((ll)(h / mid));
		if (count >= n) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	printf("%.10lf", left);

	return 0;
}