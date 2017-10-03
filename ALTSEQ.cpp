#include <bits/stdc++.h>
#define MAX 1000001
#define M 1000000007
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;

int n, a[5001];

int sign(int x) {
	if (x<0) return -1;
	else return 1;
}

int DP() {
	int dp[n+2][n+2];
	for (int i=0;i<=n;i++) dp[n+1][i] = 0;
	for (int i=n;i>=1;i--) {
		for (int prev = i-1;prev>=0;prev--) {
			dp[i][prev] = dp[i+1][prev];
			if (!prev || (abs(a[i])>abs(a[prev]) && sign(a[i])!=sign(a[prev]))) dp[i][prev] = max(dp[i][prev], dp[i+1][i] + 1);
		}
	}
	return dp[1][0];
}

int main() {
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	cout << DP();
	return 0;
}
