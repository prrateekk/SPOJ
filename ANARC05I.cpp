#include <bits/stdc++.h>
#define MAX 1000001
#define M 1000000007
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;

int main() {
	while(1) {
		map<int, int> mp;
		string s;
		cin >> s;
		if (s=="Q") return 0;
		int l = s.length();
		int x, y;
		x = y = 0;
		int cn = 0;
		for (int i=0;i<l;i++) {
			int v = x*2000+y;
			if (mp[v]) cn++;
			else mp[v] = 1;
			if (s[i]=='U') x--;
			else if (s[i]=='D') x++;
			else if (s[i]=='L') y--;
			else y++;
		}
		cout << cn << endl;
	}
	return 0;
}
