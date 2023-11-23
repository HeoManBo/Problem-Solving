#include<bits/stdc++.h>
#include<sstream>
using namespace std;

int N, M, R;
int arr[111][111];
int tmp_arr[111][111];
int sp_arr[4][111][111];

void flip_up_down() {
	for (int i = 0; i < N/2; i++) {
		for (int j = 0; j < M; j++) {
			int tmp = arr[i][j];
			arr[i][j] = arr[N - i - 1][j];
			arr[N - 1 - i][j] = tmp;
		}
	}
}

void flip_left_right() {
	for (int i = 0; i < N ; i++) {
		for (int j = 0; j < M/2; j++) {
			int tmp = arr[i][j];
			arr[i][j] = arr[i][M-j-1];
			arr[i][M-j-1] = tmp;
		}
	}
}

void rotate_right() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp_arr[j][N-i-1] = arr[i][j];
		}
	}
    int t = N;
	N = M;
	M = t;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = tmp_arr[i][j];
		}
	}
}

void rotate_left() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp_arr[M-j-1][i] = arr[i][j];
		}
	}
	int t = N;
	N = M;
	M = t;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = tmp_arr[i][j];
		}
	}
}

void divided_arr() {
	for (int i = 0; i < N / 2; i++) { //1번
		for (int j = 0; j < M / 2; j++) {
			sp_arr[0][i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < N/2; i++) { //2
		for (int j = M/2; j < M; j++) {
			sp_arr[1][i][j-M/2] = arr[i][j];
		}
	}

	for (int i = N / 2; i < N; i++) { //3
		for (int j = M/2; j < M; j++) {
			sp_arr[2][i-(N/2)][j -(M/2)] = arr[i][j];
		}
	}

	for (int i = N/2; i < N; i++) { //4
		for (int j = 0; j < M / 2; j++) {
			sp_arr[3][i-(N/2)][j] = arr[i][j];
		}
	}
}

void r() {
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M / 2; j++) {
			arr[i][(M / 2) + j] = sp_arr[0][i][j];
		}
	}

	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M / 2; j++) {
			arr[(N/2)+i][(M / 2) + j] = sp_arr[1][i][j];
		}
	}

	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M / 2; j++) {
			arr[(N/2)+i][j] = sp_arr[2][i][j];
		}
	}

	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M / 2; j++) {
			arr[i][j] = sp_arr[3][i][j];
		}
	}
}

void l() {
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M / 2; j++) {
			arr[i][(M / 2) + j] = sp_arr[2][i][j];
		}
	}

	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M / 2; j++) {
			arr[(N / 2) + i][(M / 2) + j] = sp_arr[3][i][j];
		}
	}

	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M / 2; j++) {
			arr[(N / 2) + i][j] = sp_arr[0][i][j];
		}
	}

	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M / 2; j++) {
			arr[i][j] = sp_arr[1][i][j];
		}
	}
}


int main(void)
{
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < R; i++) {
		int com; cin >> com;
		if (com == 1) {
			flip_up_down();
		}
		else if (com == 2) {
			flip_left_right();
		}
		else if (com == 3) {
			rotate_right();
		}
		else if (com == 4) {
			rotate_left();
		}
		else if (com == 5 || com == 6) {
			divided_arr();
			if (com == 5) {
				r();
			}
			else {
				l();
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}