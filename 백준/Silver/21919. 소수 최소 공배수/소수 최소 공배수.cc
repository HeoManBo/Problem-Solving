#include<bits/stdc++.h>

using namespace std;

#define ll long long

int N;
int arr[11111];
bool chk[111'1111], chk2[111'1111];


void eratosthenes() {
	memset(chk, true, sizeof(chk));
	for (int i = 2; i <= 1000000; i++) {
		if (chk[i] == true) {
			for (int j = i + i; j <= 1000000; j += i) {
				chk[j] = false;
			}
		}
	}
}


int main(void) {
	cin >> N;
	eratosthenes();
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	vector<int> sosu;
	for (int i = 0; i < N; i++) {
		if (chk[arr[i]]) sosu.push_back(arr[i]);
	}
	long long ans = 1;
	if (sosu.size() == 0) cout << "-1\n";
	else {
		ans = 1;
		for (int i = 0; i < sosu.size(); i++) {
			if (!chk2[sosu[i]]) {
				chk2[sosu[i]] = true;
				ans *= sosu[i];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}