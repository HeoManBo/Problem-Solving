#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int N, M, K;
struct beer {
	int prefer;
	int alcohol;
};

int cmp(beer& a, beer& b) {
	if (a.prefer == b.prefer) {
		return a.alcohol < b.alcohol;
	}

	return a.prefer > b.prefer;
}

int cmp2(beer& a, beer& b) {
	return a.alcohol < b.alcohol;
}

beer beers[202020];

bool valid(int x) { //현재 간 레벨이 X일 때, 
	int p = 0, day = 0;
	for (int i = 0; i < K && day < N; i++) {
		if (beers[i].alcohol <= x) {
			p += beers[i].prefer;
			day++;
		}
	}

	return p >= M && day == N;
}

void binarySearch() {
	sort(beers, beers + K, cmp);
	long long l = 1;
	int ans = -1;
	long long r = INT32_MAX;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (valid(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	cout << ans << '\n';
}

void PQ() {
	sort(beers, beers + K, cmp2);
	priority_queue<int,vector<int>, greater<int>> pq; //현재 담긴 선호도 중 가장 낮은 놈
	int sum = 0, ans = -1;
	for (int i = 0; i < K; i++) {
		pq.push(beers[i].prefer);
		sum += beers[i].prefer;
		if (pq.size() > N) {
			int r = pq.top();
			pq.pop();
			sum -= r;
		}
		if (pq.size() == N && sum >= M) {
			ans = beers[i].alcohol;
			break;
		}
	}

	cout << ans << '\n';
}

int main(void)
{
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		cin >> beers[i].prefer >> beers[i].alcohol;
	}

	PQ();

	return 0;
}