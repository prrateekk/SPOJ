#include <bits/stdc++.h>
#define MAX 1000001
#define ll long long
using namespace std;

int primes[100], p[100], cn, md;
map<int, int> mp;
int res;

int init() {
	for (int i=2;i<70;i++) {
		if (!p[i]) {
			for (int j=i*i;j<100;j+=i) p[j] = 1;
		}
	}
	for (int i=2;i<70;i++) if (!p[i]) primes[cn++] = i;
	return 0;
}

int BF(int i, int left, ll ans) {
	if (!mp[ans]) {
		mp[ans] = 1;
		res++;
	}
	if (primes[i]>left || i==cn) return 0;
	BF(i+1, left, ans);
	BF(i, left-primes[i], (ans*primes[i])%md);
	return 0;
}

int main() {
	init();
	int t;
	cin >> t;
	while(t--) {
		int n;
		mp.clear();
		res = 0;
		cin >> n >> md;
		BF(0, n, 1);
		cout << res << endl;
	}
	return 0;
}