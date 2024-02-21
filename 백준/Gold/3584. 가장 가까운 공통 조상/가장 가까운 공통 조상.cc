#include<bits/stdc++.h>

using namespace std;


int T;
int N;
int parent[10101];
bool chk[10101];
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			parent[i] = i;
			chk[i] = false;
		}
		for (int i = 0; i < N - 1; i++) {
			int a, b; cin >> a >> b;
			parent[b] = a; //b의 조상은 a
		}

		int a, b;
		cin >> a >> b;
		chk[a] = true;
		//a의 조상을 구하자
		while (parent[a] != a) {
			a = parent[a];
			chk[a] = true;
		}

		while (true) {
			if (chk[b]) {
				cout << b << "\n";
				break;
			}
			b = parent[b];
		}
	}
}