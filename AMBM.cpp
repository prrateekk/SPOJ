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
		ll n, k;
		cin >> n >> k;
		ll a[k], b[k];
		ll prev = 0;
		for (int i=0;i<k;i++) {
			cin >> a[i];
			b[i] = 2*prev+a[i];
			prev = b[i];
		}
		vector <int> v;
		for (int i=k-1;i>=0;i--) {
			if (b[i]<=n) {
				v.push_back(i+1);
				n-=b[i];
			}
		}
		if (n) cout << -1 << endl;
		else {
			for (int i=v.size()-1;i>=0;i--) cout << v[i] << " ";
			cout << endl;
		}
	}
	return 0;
}
