#include<iostream>
#include<vector>
using namespace std;


int N, M;
int info[5][16];
int place[16][2];
int wood[111][3];
int selected[16]; //각 개구리가 선택한 연못의 번호

bool check() {
	//for (int i = 1; i <= N; i++) {
	//	int now = selected[i]; // i번 개구리가 선택한 연못
	//	//연결된 연못을 보면서 살펴본다.
	//	for (int j = 0; j < wood[now].size(); j++) {
	//		int connected = wood[now][j].first; //연결된 연못 번호
	//		int hobby = wood[now][j].second; //공유할 취미
	//		int neighbor = selected[connected]; //연결된 연못에 있는 개구리 번호 
	//		if (info[hobby][i] != info[hobby][neighbor]) { //흥미도가 일치하지 않으면 연결 실패 
	//			return false;
	//		}
	//	}
	//}
	for (int i = 0; i < M; i++) {
		int a = wood[i][0];
		int b = wood[i][1];
		int hobby = wood[i][2];
		int f1 = selected[a];
		int f2 = selected[b];
		if (info[hobby][f1] != info[hobby][f2]) {
			return false;
		}
	}

	return true;
}

//각각의 통나무마다 대화 주제가 결정되어 있는데, 대화는 그 주제에 대해 두 개구리의 흥미도가 일치하면 이루어진다.
void assign(int now) {
	if (now == N + 1) { //모든 개구리의 연못 배치가 끝났으면
		if (check()) { //가능한지 확인 
			cout << "YES\n";
			for (int i = 1; i <= N; i++) {
				cout << selected[i] << ' ';
			}
			cout << '\n';
			exit(0);
		}
		return;
	}

	for (int i = 0; i < 2; i++) {
		if (selected[place[now][i]] == 0) {
			selected[place[now][i]] = now;
			assign(now + 1);
			selected[place[now][i]] = 0;
		}
	}

	return;
}

int main(void)
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> info[1][i] >> info[2][i] >> info[3][i] >> info[4][i];
	}

	for (int i = 1; i <= N; i++) {
		cin >> place[i][0] >> place[i][1];
	}

	for (int i = 0; i < M; i++) {
		int a, b, subject;
		cin >> a >> b >> subject;
		/*wood[a].push_back({ b, subject });
		wood[b].push_back({ a, subject });*/
		wood[i][0] = a;
		wood[i][1] = b;
		wood[i][2] = subject;
	}

	assign(1);

	cout << "NO\n";
	return 0;
}