#include<bits/stdc++.h>
using namespace std;

string s[1010], filp[1010];
string join[1010];
int N, M;
int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			filp[i] += s[j][i];
		}
	}

	int count = 0; 
	for (int k = 1; k < N; k++) {
		set<string> chk;
		bool flag = true;
		for (int i = 0; i < M; i++) {
			string tmp = filp[i].substr(k, filp[i].length());
			if (chk.find(tmp) != chk.end()) {
				flag = false;
				break;
			}
			else {
				chk.insert(tmp);
			}
		}
		if (!flag) break;
		else count++;
	}

	cout << count << '\n';
	return 0;
}