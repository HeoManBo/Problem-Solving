#include<bits/stdc++.h>
using namespace std;

string N;
map<set<string>, int> chk;
int ans = 0;
void go(int l, int r, string cur, set<string> s) { // l,r -> 남은 채워야할 자리수 
	if (cur.length() == N.length()) { //자리수가 같을 떄
		if (cur == N) {
			chk[s] = 1;
		}
		return;
	}

	if (l > 0) {
		string next = N[l-1] + cur;
		s.insert(next);
		go(l - 1, r, next, s);
		s.erase(next);
	}

	if (r < N.length()) {
		string next = cur + N[r+1];
		s.insert(next);
		go(l, r + 1, next, s);
		s.erase(next);
	}


	return;
}

int main(void)
{
	cin >> N;

	for (int i = 0; i < N.size(); i++) {
		string cand = "";
		cand.push_back(N[i]);
		set<string> s = { cand };
		go(i, i, cand, s);
	}
	
	cout << chk.size() << '\n';

	return 0;
}