#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<pair<int, int>> info;
int N, L, P;

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		info.push_back({ a,b });
	}

	sort(info.begin(), info.end()); //입력은 무작위 이므로 정렬이 필요함 
	cin >> L >> P;
	info.push_back({ L, 0 });
	int now = 0;
	priority_queue<int> pq;
	int cnt = 0;
	for (int i = 0; i < info.size(); i++) {
		if (now + P >= info[i].first) { //다음 주유소까지 현재 기름으로 갈 수 있다면
			P -= (info[i].first - now);
			now = info[i].first;
			pq.push(info[i].second); //지나치는 주유소의 기름양을 저장해둔다. 
		}
		else { //만약 갈 수 없다면 기름을 꺼내면서 갈 수 있을때까지 더한다.
			while (!pq.empty()) {
				//꺼낸다
				int gas = pq.top();
				pq.pop();
				cnt++;
				if (now + (P + gas) >= info[i].first) { //만약 갈 수 있다면 진행
					P += gas;
					P -= (info[i].first - now);
					now = info[i].first;
					pq.push(info[i].second);
					break;
				}
				else {
					P += gas;
				}
			}

			if (pq.empty()) { //지나친 주유소의 기름을 다 썻는데도 갈 수 없다면 -1
				cout << "-1\n";
				return 0;
			}
		}
	}
	//마지막에서 또 찾음
	if (now < L) {
		cout << "-1\n";
	}
	else {
		cout << cnt << '\n';
	}

	return 0;
}