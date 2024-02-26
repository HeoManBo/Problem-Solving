//돈이 많은 도현이의 공유기를 설치해주자,
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, C;
vector<int> house;

//거리가 X일 때 거리가 X보다 긴 곳에 몇 개의 공유기를 설치 할 수 있을까?
bool D(int x) {
	int cnt = 1;
	int front_house = house[0];
	for (int i = 1; i < house.size(); i++) {
		if (house[i] - front_house >= x) { //거리가 X보다 크면
			cnt++;
			front_house = house[i]; //다음 공유기를 설치할 집을 셋팅
		}
	}
	return C > cnt; 
}
int main(void) {
	cin >> N >> C;
	int dist;
	int max_dist = 0;
	for (int i = 0; i < N; i++) {
		cin >> dist;
		house.push_back(dist);
		max_dist = max(max_dist, dist); //가장 거리가 먼 집의 거리를 구함.
	}
	sort(house.begin(), house.end());//입력받은 집의 주소를 오름차순으로 정렬.
	int left = 1; //최소 최댓값은 1
	int right = house.back() - house.front();
	int x;
	while (left <= right) {
		x = (left + right) / 2;
		if (D(x)) { //공유기를 C개보다 더 설치를 하지 못하면 거리를 줄인다.
			right = x - 1;
		}
		else { //더 많이 설치할 수 있다면 거리를 늘려본다.
			left = x + 1;
			dist = x;
		}
	}
	cout << dist;

}