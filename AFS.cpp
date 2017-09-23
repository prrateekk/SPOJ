#include <bits/stdc++.h>
#define MAX 1000001
#define M 1000000007
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;

ll p[MAX];

int main() {
	for (int i=1;i<MAX;i++) {
		for (int j = 2*i;j<MAX;j+=i) {
			p[j]+=i;
		}
	}
	ll a[MAX];
	a[0] = a[1] = 0;
	for (int i=2;i<MAX;i++) {
		a[i] = a[i-1] + p[i];
	}
	int t;
	cin >> t;
	while(t--) {
		int x;
		cin >> x;
		cout << a[x] << endl; 
	}
	return 0;
}
