#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int ans = -1;
	for (int i = 1; i <= N; i++) {
		int tmp = i;
		int div = i;
		while (div) {
			int re = div % 10;
			div /= 10;
			tmp += re;
		}
		if (tmp == N) {
			cout << i << '\n';
			return 0;
		}
	}
	
	cout << "0\n";
	return 0;
}