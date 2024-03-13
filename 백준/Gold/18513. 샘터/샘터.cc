#include<iostream>
#include<map>
#include<set>
#include<queue>
using namespace std;

int N, K;
map<int, int> chk; 
int arr[101'101];
set<int> s;
int dx[] = { -1,1 };
int main(void)
{
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i]; //연못의 위치
		s.insert(arr[i]);
	}

	queue<pair<int,int>> q; // <연못 시작 위치, 거리>
	for (int i = 0; i < N; i++) {
		q.push({ arr[i], arr[i] });
	}

	int install = 0;
	long long dist = 0;
	while (!q.empty()) {
		int origin = q.front().first;
		int now = q.front().second;
		q.pop();

		bool stop = false;
		for (int i = 0; i < 2; i++) {
			int nx = now + dx[i];
			if (s.find(nx) != s.end()) continue; // 우물에 설치 
			if (chk[nx] == 0) {
				chk[nx] = abs(origin - nx);
				q.push({ origin, nx });
				install++;
				dist += abs(origin - nx);
				if (install == K) { // K 개 설치가 끝나면 break
					stop = true;
					break;
				}
			}
		}
		if (stop) break;
	}

	cout << dist << '\n';

	return 0;
}
