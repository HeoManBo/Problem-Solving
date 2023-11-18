#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<short> map[10101];
bool check[10101];
int getComputer[10101];
int max_num = -1;
void dfs(int start, int now) {

	check[now] = true;
	for (int i = 0; i < map[now].size(); i++) {
		int next = map[now][i];
		if (!check[next]) {
			getComputer[start]++;
			check[next] = true;
			dfs(start, next);
		}
	}
}

int main(void)
{
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		map[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		dfs(i, i);
		memset(check, 0, sizeof(check));
		if (getComputer[i] > max_num) {
			max_num = getComputer[i];
		}
	}
	vector<int> ans;
	for (int i = 1; i <= N; i++) {
		if (getComputer[i] == max_num) {
			ans.push_back(i);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i : ans) {
		printf("%d ", i);
	}
	return 0;
}