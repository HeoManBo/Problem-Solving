#include<bits/stdc++.h>

using namespace std;

int N;
string s[2020];
string T;
bool chk[2222][2222];


int cmp(char a, char b) {
	return a > b;
}

void go(string& ss, int l, int r) {
	if (l > r) {
		if (ss < T) {
			T = ss;
		}
		return;
	}

	if (ss.substr(0, ss.length()) > T.substr(0, T.length())) { //가지 치기 
		return;
	}

	//1번 룰 
	ss += s[l];
	go(ss, l + 1, r);
	ss.pop_back();

	//2번 룰
	ss += s[r];
	go(ss, l, r - 1);
	ss.pop_back();

}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	T = "";
	for (int i = 0; i < N; i++) {
		cin >> s[i];
		T += s[i];
	}
	sort(T.begin(), T.end(), cmp); //가장 나중의 문자열 
	
	string ss = "";
	int l = 0, r = N - 1;
	while (l <= r) {
		if (s[l] > s[r]) {
			ss += s[r];	
			r--;
		}
		else if(s[l] < s[r]) {
			ss += s[l];
			l++;
		}
		else if (s[l] == s[r]) { //두 문자열이 같은 경우
			int tmp_l = l + 1;
			int tmp_r = r - 1;
			bool flag = false;
			while (tmp_l <= tmp_r) { //두 문자열 앞쪽을 비교한다.
				if (s[tmp_l] < s[tmp_r]) { // s[--l] < s[r] -> l쪽을 증가 
					ss += s[l++];
					flag = true;
					break;
				}
				else if(s[tmp_l] > s[tmp_r]){ // s[l] < s[--r] -> r쪽을 감소
					ss += s[r--];
					flag = true;
					break;
				}
				else { //또 두 문자가 같으면 앞쪽 비교
					tmp_l++;
					tmp_r--;
				}
			}
			if (!flag) { //사이의 모든 글자가 같으면 왼쪽에 하나 더한다 (오른쪽도 상과없음)
				ss += s[l++];
			}
		}
	}

	for (int i = 0; i < ss.size(); i++) {
		if (i != 0 && i % 80 == 0) {
			cout << '\n';
		}
		cout << ss[i];
	}



	return 0;
}