#include <bits/stdc++.h>
#define MAX 1000001
#define M 1000000007
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;

int p[MAX];

int main() {
	int n;
	cin >> n;
	for (int i=1;i<=n;i++) {
		for (int j = i*i;j<=n;j+=i) {
			p[j]++;
		}
	}
	int cn = 0;
	for (int i=1;i<=n;i++) cn+=p[i];
	cout << cn;
	return 0;
}
