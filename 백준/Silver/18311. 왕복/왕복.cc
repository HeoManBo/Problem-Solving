#include <iostream>
#include <queue>
#include <vector>
#include<map>
#include <algorithm>
using namespace std;

int N;
long long K;
int dist[111'111];

int main(void)
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> dist[i];
	}

	for (int i = 1; i <= N; i++) {
		K -= dist[i];
		if (K < 0) {
			cout << i << '\n';
			return 0;
		}
		else if (K == 0) {
			if (i == N) {
				cout << i << '\n';
			}
			else {
				cout << (i + 1) << '\n';
			}
			return 0;
		}
	}

	for (int i = N; i >= 1; i--) {
		K -= dist[i];
		if (K < 0) {
			cout << i << '\n';
			return 0;
		}
		else if (K == 0) {
			cout << (i - 1) << '\n';
			return 0;
		}
	}

	
	return 0;
}



