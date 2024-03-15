#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

int A, B;
bool prime[101'101];
vector<int> sosu;

void eratos() {
	for (int i = 2; i <= B; i++) {
		if (!prime[i]) {
			for (int j = i + i; j <= B; j += i) {
				prime[j] = true;
			}
		}
	}

	for (int i = 2; i <= B; i++) {
		if (!prime[i]) {
			sosu.push_back(i);
		}
	}
	prime[1] = true;
}

bool underPrime(int s) {
	int i = 0;
	int l = 0;

	while (s > 1) {
		if (s % sosu[i] == 0) {
			s /= sosu[i];
			l++;
		}
		else {
			i++;
		}
	}

	return !prime[l];
}

int main(void)
{
	cin >> A >> B;
	eratos();

	int cnt = 0;
	for (int i = A; i <= B; i++) {
		if (underPrime(i)) {
			cnt++;
		}
	}
	
	cout << cnt << '\n';
	return 0;
}