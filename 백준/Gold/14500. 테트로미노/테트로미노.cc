#include<bits/stdc++.h>

using namespace std;

int N, M;
int board[555][555];
int ans = -1;

//board y,x 에서 폴리오미노 마다 다 회전/대칭을 해보고 최대값을 얻는다. 
int cal(int y, int x, int type) {
	if (type == 0) { //type == 0 -> 정 사각형 폴리오미노 -> 회전이나 대칭이 의미가 없음
		return board[y][x] + board[y][x + 1] + board[y + 1][x] + board[y+1][x + 1];
	}
	else if(type == 1) { //type == 1 ==== 형태의 폴리오미노 가로형태와 세로 형태밖에 없음.
		int vertical = board[y][x] + board[y + 1][x] + board[y + 2][x] + board[y + 3][x];
		int horizontal = board[y][x] + board[y][x + 1] + board[y][x + 2] + board[y][x + 3];
		return max(vertical, horizontal);
	}
	else if (type == 2) { // type == 2 : ㅗ 모양 , ㅏ,ㅓ,ㅗ,ㅜ 가 있음 (y,x)에 정 중앙을 놓음 
		int one = board[y][x] + board[y+1][x] + board[y - 1][x] + board[y][x+1]; // ㅏ
		int two = board[y][x] + board[y+1][x] + board[y - 1][x] + board[y][x-1]; // ㅓ
		int three = board[y][x] + board[y][x + 1] + board[y][x - 1] + board[y - 1][x]; // ㅗ
		int four = board[y][x] + board[y][x + 1] + board[y][x - 1] + board[y + 1][x]; // ㅜ
		return max(max(one, two), max(three, four));
	}
	else if (type == 3) { // ㄴ 자 형태, ㄴ, ㄱ, r 뒤집은 형태 
		int one = board[y][x] + board[y][x + 1] + board[y][x + 2] + board[y - 1][x]; // ㄴ 
		int two = board[y][x] + board[y - 1][x] + board[y - 1][x - 1] + board[y - 1][x - 2]; // ㄱ
		int three = board[y][x] + board[y - 1][x] + board[y - 1][x + 1] + board[y-1][x + 2]; // r
		int four = board[y][x] + board[y - 1][x] + board[y][x - 1] + board[y][x - 2]; // ㄴ 뒤집은 형태
		int five = board[y][x] + board[y][x - 1] + board[y - 1][x] + board[y - 2][x];
		int six = board[y][x] + board[y][x - 1] + board[y + 1][x] + board[y + 2][x];
		int seven = board[y][x] + board[y + 1][x] + board[y + 2][x] + board[y][x + 1];
		int eight = board[y][x] + board[y][x + 1] + board[y - 1][x] + board[y - 2][x];
		int first_max = max(max(one, two), max(three, four));
		int second_max = max(max(five, six), max(seven, eight));
		return max(first_max, second_max);
	}
	else if (type == 4) { //z 형태
		int one = board[y][x] + board[y][x + 1] + board[y - 1][x] + board[y - 1][x - 1]; // z
		int two = board[y][x] + board[y - 1][x] + board[y - 1][x + 1] + board[y][x - 1]; // z 뒤집은거 
		int three = board[y][x] + board[y + 1][x] + board[y][x + 1] + board[y - 1][x + 1]; // z 위로 뒤집음
		int four = board[y][x] + board[y][x - 1] + board[y + 1][x] + board[y - 1][x - 1]; // z 위로한거 위로한거 
		return max(max(one, two), max(three, four));
	}
}

int main(void) {
	cin >> N >> M;
	for (int i = 5; i < N+5; i++) {
		for (int j = 5; j < M+5; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 5; i < N+5; i++) {
		for (int j = 5; j < M + 5; j++) {
			for (int k = 0; k < 5; k++) {
				int a = cal(i, j, k);
				ans = max(ans, a);
			}
		}
	}

	cout << ans << "\n";

	return 0;
}