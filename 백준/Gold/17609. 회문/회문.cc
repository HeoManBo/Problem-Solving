	#include <iostream>
	#include <queue>
	#include <vector>
	#include<map>
	#include <algorithm>
	using namespace std;

	int T;
	// map<string, bool> cache; // 해당 문자열이 이미 pelin인지 확인됐는지 확인한다.
	bool chk[111'111]; //잘린 문자열 확인 

	// S가 [l,r] 에서 pelin인지 확인한다.
	int isPelin(string& s, int l, int r, bool cut) {
		while (l < r) {
			if (s[l] != s[r]) {
				if (cut == false) { //자른적이 없다면 자르고 이동
					int ll = isPelin(s, l + 1, r, true); //왼쪽 잘라보기
					int rr = isPelin(s, l, r - 1, true); //오른 쪽 잘라보기
					return ((ll == 0) || (rr == 0)) ? 1 : 2; //자른 것 중 하나라도 pelin이 있으면 1 반환
				}
				else {
					return 2; // 다른데 이미 한번 자른적이 있다면 평문임.
				}
			}
			l++;
			r--;
		}

		return 0;
	}

	int main(void)
	{
		cin >> T;
		for (int i = 0; i < T; i++) {
			//cache.clear();
			string s;
			cin >> s;
			cout << isPelin(s, 0, s.length() - 1, false) << '\n';
		}
	}

