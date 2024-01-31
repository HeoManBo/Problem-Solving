#include<bits/stdc++.h>
using namespace std;

int arr[6][3], result[6][3];
int ans[4];
const int team1[] = { 0,0,0,0,0,1,1,1,1,2,2,2,3,3,4 };
const int team2[] = { 1,2,3,4,5,2,3,4,5,3,4,5,4,5,5 };

void go(int tc, int round) {
	if (round == 15) {
		if (ans[tc]) return;

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				if (arr[i][j] != result[i][j]) {
					return;
				}
			}
		}
		ans[tc] = true;
		return;
	}

	int t1 = team1[round];
	int t2 = team2[round];

	//t1승리, t2 패배
	result[t1][0]++;
	result[t2][2]++;
	go(tc, round + 1);
	result[t1][0]--;
	result[t2][2]--;

	//t1,t2 무승부
	result[t1][1]++;
	result[t2][1]++;
	go(tc, round + 1);
	result[t1][1]--;
	result[t2][1]--;

	//t1패배, t1 승리
	result[t1][2]++;
	result[t2][0]++;
	go(tc, round + 1);
	result[t1][2]--;
	result[t2][0]--;
}

int main(void)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 3; k++) {
				cin >> arr[j][k];
			}
		}
		go(i, 0);
		memset(result, 0, sizeof(result));
	}

	for (int i = 0; i < 4; i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}