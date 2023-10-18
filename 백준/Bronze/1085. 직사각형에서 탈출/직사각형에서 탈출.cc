#include<bits/stdc++.h>

using namespace std;

int x, y, w, h;

int main(void)
{
	cin >> x >> y >> w >> h;
	cout << min(min(x, abs(w-x)), min(y, abs(h-y)));

	return 0;
}