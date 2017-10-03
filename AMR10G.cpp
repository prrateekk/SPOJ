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
		int a[n];
		for (int i=0;i<n;i++) cin >> a[i];
		sort(a, a+n);
		int mn = INT_MAX;
		for (int i=0;i<=n-k;i++) {
			mn = min(mn, a[i+k-1]-a[i]);
		}
		cout << mn << endl;
	}
	return 0;
}
