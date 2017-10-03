#include <bits/stdc++.h>
#define MAX 1000001
#define M 1000000007
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;

int n, dp[1000000][3];

int DP(int i, int prev) {
	if (i==n) return 1;
	if (dp[i][prev]) return dp[i][prev];
	int res = DP(i+1, prev);
	if (prev<2) res+=DP(i+1, prev+1);
	if (prev>0) res+=DP(i+1, prev-1);
	return dp[i][prev] = res;
}

int main() {
	cin >> n;
	cout << DP(1, 0) + DP(1, 1) + DP(1, 2);
	return 0;
}

