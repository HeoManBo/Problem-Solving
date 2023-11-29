#include<bits/stdc++.h>

using namespace std;

int N, cut, root, ans = 0;
vector<int> parent[55];

void solve(int now) {
	//자식이 없고 cut이 아닌 경우 
	if (now != cut && parent[now].size() == 0) {
		ans++;
		return;
	}

	for (int i = 0; i < parent[now].size(); i++) {
		int next = parent[now][i];
		if (parent[now].size() == 1 && next == cut) { //cut의 부모가 자식을 cut밖에 가지지 않는 경우 cut의 부모는 리프노드가 됨
			ans++;
			return;
		}
		if (next != cut) {
			solve(next);
		}
	}
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		if (p == -1) {
			root = i;
		}
		else {
			parent[p].push_back(i);
		}
	}

	cin >> cut;
	if (cut == root){ //루트를 자르면 트리가 아예 사라짐
		cout << "0\n";
	}
	else {
		solve(root);
		cout << ans << '\n';
	}


	return 0;
}