#include <bits/stdc++.h>
#define MAX 100001
#define M 1000000007
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;

int n, c, a[MAX];

int isPossible(int x) {
	int left = c-1;
	int prev = a[0];
	int i = 1;
	while(i<n) {
		if (a[i]-prev>=x) {
			prev = a[i];
			left--;
		}
		i++;
	}
	if (left>0) return 0; 
	return 1;
}

int bs(int l, int r) {
	if (l>r) return -1;
	int mid = (l+r)>>1;
	if (isPossible(mid)) {
		if (mid==r || !isPossible(mid+1)) return mid;
		else return bs(mid+1, r);
	}
	else return bs(l, mid-1);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> c;
		for (int i=0;i<n;i++) cin >> a[i];
		sort(a, a+n);
		cout << bs(0, a[n-1]) << endl;
	}
	return 0;
}
