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
		int n;
		cin >> n;
		int sq = sqrt(n);
		int mx = 1;

		for (int i=2;i<=sq;i++) {
			if (n%i==0) {
				int c = 0;
				int temp = n;
				while(temp%i==0) {
					temp/=i;
					c++;
				}
				mx = max(mx, c);
			}
		}
		cout << mx << endl;
	}
	return 0;
}
