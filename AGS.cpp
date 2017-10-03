#include <bits/stdc++.h>
#define MAX 100001
#define M 1000000007
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;

ll mat[2][2], org[2][2];
ll a, d, r, n, m;

int matPow(int x) {
	if (!x) return 0;
	if (x&1) {
		matPow(x-1);
		ll temp[2][2];
		temp[0][0] = ((mat[0][0]*org[0][0])%m + (mat[0][1]*org[1][0])%m)%m;
		temp[0][1] = ((mat[0][0]*org[0][1])%m + (mat[0][1]*org[1][1])%m)%m;
		temp[1][0] = ((mat[1][0]*org[0][0])%m + (mat[1][1]*org[1][0])%m)%m;
		temp[1][1] = ((mat[1][0]*org[0][1])%m + (mat[1][1]*org[1][1])%m)%m;
		for (int i=0;i<2;i++) {
			for (int j=0;j<2;j++) {
				mat[i][j] = temp[i][j];
			}
		}
		return 0;
	}
	else {
		matPow(x/2);
		ll temp[2][2];
		temp[0][0] = ((mat[0][0]*mat[0][0])%m + (mat[0][1]*mat[1][0])%m)%m;
		temp[0][1] = ((mat[0][0]*mat[0][1])%m + (mat[0][1]*mat[1][1])%m)%m;
		temp[1][0] = ((mat[1][0]*mat[0][0])%m + (mat[1][1]*mat[1][0])%m)%m;
		temp[1][1] = ((mat[1][0]*mat[0][1])%m + (mat[1][1]*mat[1][1])%m)%m;
		for (int i=0;i<2;i++) {
			for (int j=0;j<2;j++) {
				mat[i][j] = temp[i][j];
			}
		}
		return 0;
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> a >> d >> r >> n >> m;
		org[0][0] = r;
		org[0][1] = org[1][1] = 1;
		org[1][0] = 0;
		mat[0][0] = mat[1][1] = 1;
		mat[1][0] = mat[0][1] = 0;
		ll res;
		if (n%2==0) {
			matPow(n/2-1);
			res = ((mat[0][0]*(a+d))%m + (mat[0][1]*d)%m)%m;
		}
		else {
			matPow(n/2);
			res = ((mat[0][0]*(a+d))%m + (mat[0][1]*d)%m)%m;
			res = (res-d)%m;
			if (res<0) res+=m;
		}
		cout << res << endl;
	}
	return 0;
}
