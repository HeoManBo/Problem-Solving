#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<string.h>
using namespace std;

struct info {
	int height; //빌딩 높이
	int num;  //빌딩 번호
};

int N;
vector<info> building;
int cnt[101010][2]; // [x][0] : x번째에서 오른쪽으로 바라봤을 때의 탑의 개수 [x][1] : 왼쪽
int nearnest[101010]; //가장 가까운 탑의 idx 

int main(void) {
	cin >> N;
	building.resize(N);
	for (int i = 0; i < N; i++) {
		int height; cin >> height;
		building[i] = {  height, i+1 };
		nearnest[i] = -101010;
	}
	
	stack<info> left_see_st;

	for (int i = 0; i < N; i++) { //오른쪽으로 가면서 왼쪽을 바라볼 때 
		while (!left_see_st.empty() && left_see_st.top().height <= building[i].height) {
			left_see_st.pop(); //자기보다 작거나 같은 높이의 건물은 볼 수 없음
		}
		cnt[i][1] = left_see_st.size();
		if (!left_see_st.empty()) nearnest[i] = left_see_st.top().num;
		left_see_st.push(building[i]);
	}

	stack<info> right_see_st;
	for (int i = N - 1; i >= 0; i--) { //왼쪽으로 가면서 오른쪽을 바라봄
		while (!right_see_st.empty() && right_see_st.top().height <= building[i].height) {
			right_see_st.pop(); //자기보다 작거나 같은 높이의 건물은 볼 수 없음
		}
		cnt[i][0] = right_see_st.size();
		if (!right_see_st.empty()) {
			if (right_see_st.top().num - building[i].num < building[i].num - nearnest[i]) nearnest[i] = right_see_st.top().num;
		}
		right_see_st.push(building[i]);
	}

	for (int i = 0; i < N; i++) {
		int total = cnt[i][0] + cnt[i][1];
		if (total == 0) {
			cout << "0\n";
		}
		else {
			cout << total << ' ' << nearnest[i] << '\n';
		}
	}

	return 0;
}