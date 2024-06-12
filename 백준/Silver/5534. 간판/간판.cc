#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int ans = 0;



int main(void)
{
	int N;
	cin >> N;
	string board;
	cin >> board;
	int ans = 0;
	for (int iter = 0; iter < N; iter++) {
		string old_board;
		cin >> old_board;
		
		// 첫 번째 문자와 두 번째 문자를 찾아서 두 간격을 계속 유지했을 때,
		// board를 만들 수 있는지 확인함
		bool found = false;
		for (int i = 0; i < old_board.size(); i++) {
			if (old_board[i] != board[0]) continue;  //첫번째 문자 위치 찾기

			for (int j = i + 1; j < old_board.size(); j++) {
				if (old_board[j] != board[1]) continue; //두번째 문자 위치 찾기
				int interval = j - i; // 첫 번째 문자와 두 번째 문자 사이의 간격
				int idx = 2, cnt = 2;
				for (int k = j + interval; k < old_board.size(); k += interval) {
					if (old_board[k] != board[idx]) {
						break;
					}
					else {
						idx++;
					}
				}

				if (idx == board.size()) {
					ans++;
					found = true;
				}
				
				if (found) {
					break;
				}
			}

			if (found) {
				break;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
