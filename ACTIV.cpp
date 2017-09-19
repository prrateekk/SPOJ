#include <bits/stdc++.h>
#define MAX 1000001
#define M 100000000
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;

struct node {
	int s, e;
};

node a[MAX];

bool operator <(node x, node y) {
	if (x.s==y.s) return x.e<y.e;
	else return x.s<y.s;
}

int bs(int l, int r, int x) {
	if (l>r) return -1;
	int mid = (l+r)>>1;
	if (a[mid].s>=x) {
		if (mid==l || a[mid-1].s<x) return mid;
		else return bs(l, mid-1, x);
	}
	else {
		bs(mid+1, r, x);
	}
}

int n, dp[100001];

int DP(int i) {
	if (i>=n) return 1;
	if (dp[i]) return dp[i];
	dp[i] = DP(i+1);
	int next = bs(0, n-1, a[i].e);
	if (next==-1) dp[i] = (dp[i] + 1)%M;
	else dp[i] = (dp[i] + DP(next))%M;
	return dp[i];
}

int digits(int x){
	int d = 0;
	while(x){
		d++;
		x/=10;
	}
	return d;
}

int main() {
	while(1) {
		cin >> n;
		if (n==-1) break;
		for (int i=0;i<n;i++) {
			cin >> a[i].s >> a[i].e;
		}
		sort(a, a+n);
		memset(dp, 0, sizeof(dp));
		int res = DP(0)-1;
		if (res<0) res+=M;
		int d = digits(res);
		for (int i=0;i<8-d;i++) {
			cout << 0;
		}
		cout << res << endl;
	}
	return 0;
}
