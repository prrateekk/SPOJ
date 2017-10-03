#include <bits/stdc++.h>
#define MAX 1000001
#define M 1000000007
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<int> v;
		int cn;
		int i = 0;
		int f = 0;
		while(i<n) {
			int j = i;
			while(j<n && s[i]==s[j]) j++;
			for (int l=0;l<(j-i)/k;l++) {
				v.push_back(k);
				f = 1;
			}
			if ((j-i)%k) v.push_back((j-i)%k);
			i = j;
		}
		int sz = v.size();
		if (f) cout << sz << endl;
		else cout << -1 << endl;
	}
	return 0;
}

