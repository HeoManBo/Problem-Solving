#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N;
string s;
int letter[26];
//부분 길이중 알파벳의 개수가 N개만 허용 


int main(void) {
	cin >> N;
	cin >> s;
	int len = s.size();
	int l = 0, r = 0, cnt = 0, ans=1;
	if (len <= N) {
		cout << len << "\n";
	}
	else {
		while (l <= r && r < len) {
			//right move
			if (cnt <= N) {
				if (letter[s[r] - 'a'] == 0) {
					letter[s[r] - 'a']++;
					cnt++;
				}
				else {
					letter[s[r] - 'a']++;
				}
				r++;
				if (r == len - 1 && cnt <= N) {
					ans = max(ans, r - l + 1);
					break;
				}
			}
			else { //left move
				letter[s[l] - 'a']--;
				if (letter[s[l] - 'a'] == 0) {
					cnt--;
				}
				l++;
			}
			if (cnt == N) {
				ans = max(ans, r - l);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}