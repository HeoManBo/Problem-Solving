#include<bits/stdc++.h>
#include<sstream>
using namespace std;


int main(void)
{
	string s;
	cin >> s;
	
	stringstream ss(s);
	vector<string> sp, origin;
	string tmp;
	int part = 0; //해당 문자열의 몇 개의 : 로 구성되어있는지
	while (getline(ss, tmp, ':')) {
		int sp_len = tmp.size();
		if (sp_len) { //문자열이 있다면
			part++;
			while (sp_len++ < 4) {
				tmp = "0" + tmp;
			}
		}
		else {
			tmp = "-1"; //비어있으면 -1 표시
		}
		sp.push_back(tmp);
	}

	//복원
	int flag = 1;
	for (int i = 0; i < sp.size(); i++) {
		tmp = sp[i];
		if (tmp == "-1" && flag) { //비어있다면 
			int whatTime = 8 - part; //몇번 반복해야 하는지
			while (whatTime--) {
				origin.push_back("0000");
			}
			flag = 0;
		}
		else if(tmp != "-1"){
			origin.push_back(tmp);
		}
	}

	for (int i = 0; i < origin.size(); i++) {
		if (i == origin.size() - 1) {
			cout << origin[i];
		}
		else {
			cout << origin[i] << ':';
		}
	}
	cout << '\n';
	return 0;
}
