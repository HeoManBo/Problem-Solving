#include<bits/stdc++.h>
using namespace std;

string s[1010], filp[1010];
string join[1010];
int N, M;


bool isValid(int x) { //[x, length)구간을 자른 문자열에 중복이 있는지 확인한다.
	set<string> chk;
	for (int i = 0; i < M; i++) {
		string tmp = filp[i].substr(x, filp[i].length());
		if (chk.find(tmp) != chk.end()) {
			return false;
		}
		else {
			chk.insert(tmp);
		}
	}

	return true;
}

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

	/*int count = 0; 
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
	*/

	int l = 0, r = N-1; //자를 문자열 길이
	int ans = 0;

	while (l <= r) {
		int mid = (l + r) / 2;

		bool flag = isValid(mid);

		if (flag) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << ans << '\n';
	return 0;
}
