#include <bits/stdc++.h>
#define MAX 1000001
#define M 1000000007
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;

int main() {
	ll f[MAX];
	f[1] = 2;
	f[2] = 3;
	for (int i=3;i<MAX;i++) {
		f[i] = f[i-1] + f[i-2];
		if (f[i]>M) break;
	}
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << f[n] << endl;
	}
	return 0;
}

