#include <bits/stdc++.h>
#define MAX 1000001
#define M 1000000007
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;

int main() {
	int dp[MAX];
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i=4;i<MAX;i++) {
		if (i%2==0) dp[i] = 1+dp[i/2];
		else dp[i] = 1+dp[i/2+1];
	}
	int t;
	cin >> t;
	while(t--) {
		int x;
		cin >> x;
		cout << dp[x] << endl;
	}
	return 0;
}
