#include<iostream>
#include<queue>
#include<map>
using namespace std;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, k; 
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cin >> k;
		priority_queue<int,vector<int>, less<int>> upper; //우선순위 높은 것
		priority_queue<int, vector<int>, greater<int>> lower; //우선순위 낮은 것 
		map<int, int> m; 
		//현재 뽑으려는 수가 큐에 남아있는지 확인함
		//(만약에 우선순위 낮은 것에서 빼면 높은 큐에는 아무런 연산을 하지 않으므로 정보가 없는 걸 확인하기 위해선 맵으로 큐에 해당 수가 몇개 남았는지 괸리해야함.

		for (int j = 1; j <= k; ++j) {
			char c;
			int num;
			cin >> c >> num;
			if (c == 'I') {
				upper.push(num);
				lower.push(num);
				m[num]++;
			}
			else if (c == 'D') {
				if (num == 1) { //최댓값 삭제
					if (!upper.empty()) {
						m[upper.top()]--;
						upper.pop();
					}
				}
				else {
					if (!lower.empty()) { //최소값 삭제
						m[lower.top()]--;
						lower.pop();
					}
				}
				// 만약 두 큐의 top 값이 같다면 한 쪽을 삭제했을 때 다른 쪽도 남지 않도록 처리함
				while (!upper.empty() && m[upper.top()] == 0) {
					upper.pop();
				}
				while (!lower.empty() && m[lower.top()] == 0) {
					lower.pop();
				}
			}
		}
		if (upper.empty() || lower.empty()) {
			cout << "EMPTY" << '\n';
		}
		else {
			cout << upper.top() << ' ' << lower.top() << ' ';
		}
	}

	return 0;
}