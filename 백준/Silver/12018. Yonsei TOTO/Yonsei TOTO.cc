#include<bits/stdc++.h>

using namespace std;

struct Info {
	int p;
	int L;
	vector<int> mile;
};

int N, M;
Info info[111];

int cmp(Info& i, Info& j) {
	return i.mile[0] < j.mile[0]; //최저 마일리지가 작은 순으로 
}

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> info[i].p >> info[i].L;
		for (int j = 0; j < info[i].p; j++) {
			int num; cin >> num;
			info[i].mile.push_back(num);
		}
	}

	int ans = 0;
	
	for (int i = 0; i < N; i++) {
		sort(info[i].mile.begin(), info[i].mile.end()); //마일리지 별로 수강신청
	}

	vector<int> point; //신청해야 하는 마일리지 

	for (int i = 0; i < N; i++) {
		if (info[i].p < info[i].L) { //수강신청 여석보다 더 적은 사람이 신청한 경우
			point.push_back(1);
		}
		else {
			point.push_back(info[i].mile[info[i].p - info[i].L]); //제껴야 하는 사람의 포인트
		}
	}
	sort(point.begin(), point.end());

	for (int i = 0; i < point.size(); i++) {
		if (M - point[i] >= 0) {
			M -= point[i];
			ans++;
		}
		else {
			break;
		}
	}
	

	cout << ans << '\n';

	return 0;
}