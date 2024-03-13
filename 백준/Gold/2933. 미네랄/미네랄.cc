#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

int R, C;
string arr[101];
int N, height[111];
bool chk[111][111];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

bool throwStick(char dir, int h) {
	if (dir == 'L') { //왼쪽에서 투척 
		for (int col = 0; col < C; col++) {
			if (arr[h][col] == 'x') { //미네랄이 있으면
				arr[h][col] = '.';  // 깨트리고 
				return false; //반환
			}
		}
	}else if (dir == 'R') { //왼쪽에서 투척 
		for (int col = C-1; col >= 0; col--) {
			if (arr[h][col] == 'x') { //미네랄이 있으면
				arr[h][col] = '.';  // 깨트리고 
				return false; //반환
			}
		}
	}

	return true;
}

void marking(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	chk[y][x] = true;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
			if (arr[ny][nx] == 'x' && !chk[ny][nx]) { //이어져 있는 미네랄을 연결함 
				q.push({ ny,nx });
				chk[ny][nx] = true;
			}
		}
	}
}


void find_cluster(vector<pair<int,int>>& drop) {
	memset(chk, false, sizeof(chk));
	for (int i = 0; i < C; i++) { //땅바닥에 있는 미네랄에 붙어있는 미네랄을 모두 찾음
		if (arr[R - 1][i] == 'x' && !chk[R - 1][i]) {
			marking(R - 1, i);
		}
	}

	// 떨궈야하는 미네랄을 찾음
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 'x' && !chk[i][j]) {
				drop.push_back({ i,j });
			}
		}
	}

}

int cal_drop_height(vector<pair<int, int>>& drop) {
	int ans = 111;
	for (auto xx : drop) {
		int y = xx.first;
		int x = xx.second;
		int cnt = 0;
		for (int i = y + 1; i < R; i++) {
			if (arr[i][x] == 'x' && chk[i][x]) { //바닥과 연결된 미네랄과 만난 경우 break;
				break;
			}
			else if(arr[i][x] == '.')cnt++;
		}
		ans = min(ans, cnt);
	}

	return ans;
}

void drop_mineral(int cnt) {
	//밑에서부터 내린다
	for (int i = 0; i < C; i++) {
		for (int j = R - 1; j >= 0; j--) {
			if (arr[j][i] == 'x' && !chk[j][i]) {
				arr[j + cnt][i] = 'x';
				arr[j][i] = '.';
			}
		}
	}
}

void draw() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
	//cout << "\n\n\n";
}

int main(void)
{
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> arr[i];
	}

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> height[i];
		height[i] = R - height[i];
	}

	for (int i = 1; i <= N; i++) {
		int h = height[i - 1];
		char turn;
		if (i % 2 == 1) turn = 'L';
		else turn = 'R'; 


		if (throwStick(turn, h)) continue; //막대를 던진 높이에 미네랄이 없는 경우 
		vector<pair<int, int>> drop;
		find_cluster(drop);
		//draw();

		if (drop.size() > 0) { //떨궈야 하는 미네랄이 있으면 
			//떨궈야하는 최소 높이를 구한다 (중간에 걸리는 CASE로 인해 끝까지 내리면 안됨)
			int cal = cal_drop_height(drop);
			drop_mineral(cal);
			//draw();
		}

	}
	draw();


	return 0;
}