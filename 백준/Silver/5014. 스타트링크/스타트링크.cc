#include<bits/stdc++.h>
using namespace std;

int F, S, G, U, D;
int chk[111'1111];

int main(void) {
	cin >> F >> S >> G >> U >> D;

	queue<int> q;
	q.push(S);
	memset(chk, -1, sizeof(chk));
	chk[S] = 0;
	bool flag = false;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == G) {
			flag = true;
			break;
		}
		// UP / DOWN 구분 
		if (cur + U <= F && chk[cur + U] == -1) {
			chk[cur + U] = chk[cur] + 1;
			q.push(cur + U);
		}
		//DOWN
		if (cur - D >= 1 && chk[cur - D] == -1) {
			chk[cur - D] = chk[cur] + 1;
			q.push(cur - D);
		}
	}
	if (flag) {
		cout << chk[G] << '\n';
	}
	else {
		cout << "use the stairs";
	}

	return 0;
}