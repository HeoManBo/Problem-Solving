#include<bits/stdc++.h>
using namespace std;


long long W, S, X, Y;

int main(void)
{
	cin >> X >> Y >> W >> S;
	long long cost1, cost2, cost3;
	//일자로만 가기
	cost1 = W * (X+Y);

	//대각으로만 가기
	if ((X + Y) % 2 == 0) cost2 = max(X, Y) * S;
	else cost2 = (max(X, Y) - (long long)1) * S + W;

	cost3 = S * min(X, Y) + W * abs(Y - X); // (K,K)만큼 대각으로 가고, 남은 거리만큼 직선으로 이동

	cout << min(cost1, min(cost2, cost3)) << "\n";

	return 0;
}