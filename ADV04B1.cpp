//Central Delannoy Number
#include <bits/stdc++.h>
#define MAX 1000001
#define M 1000003
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;

ll exp(ll a, ll b) {
	if (!b) return 1;
	if (b&1) return (a * exp(a, b-1))%M;
	else {
		ll p = exp(a, b/2);
		return (p * p)%M;
	}
}

int main() {
	ll dp[MAX];
	dp[0] = 1;
	dp[1] = 3;
	for (ll i=2;i<MAX;i++) {
		dp[i] = (((6 * i - 3) %M ) * dp[i-1] )%M - ((i-1) * dp[i-2])%M;
		dp[i] = (dp[i] * exp(i, M-2))%M;
		if (dp[i]<0) dp[i]+=M;
	}
	int t;
	cin >> t;
	while(t--) {
		int x;
		cin >> x;
		cout << dp[x-1] << endl;
	}
	return 0;
}
