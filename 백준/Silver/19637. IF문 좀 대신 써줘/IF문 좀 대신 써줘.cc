#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int N, M;

map<int, string> m;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s; int r;
		cin >> s >> r;
		m.insert({ r,s });
	}

	for (int i = 0; i < M; i++) {
		int x; cin >> x;
		auto iter = m.lower_bound(x);
		cout << iter->second << '\n';
	}


	return 0;
}