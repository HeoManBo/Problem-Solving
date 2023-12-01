#include<bits/stdc++.h>

using namespace std;

int N;
unsigned B[1111];
int cnt = 0;

bool chkAllZero() {
	for (int i = 0; i < N; i++) {
		if (B[i] != 0) return false;
	}

	return true;
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	while(true){
		int zero_count = 0;
		for (int i = 0; i < N; i++) {
			if (B[i] % 2 == 1) { //홀수면 짝수로 만들어 버림 
				B[i] -= 1;
				cnt++;
			}

			if (B[i] == 0) zero_count++;
		}
		if (zero_count == N) {
			break;
		}
		else {
			cnt++;
			for (int i = 0; i < N; i++) {
				B[i] = (B[i] >> 1);
			}
		}
	}

	cout << cnt << '\n';

	return 0;
}

