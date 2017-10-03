#include <bits/stdc++.h>
#define MAX 1000001
#define M 1000000007
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;

int mx, a[8], n;
vector<int> v[10];

int bf(int i, int val) {
	if (i==8) {
		int sum = 0;
		for (int j=0;j<8;j++) {
			if (val&(1<<j)) sum+=a[j];
		}
		mx = max(mx, sum);
		return 0;
	}
	int sz = v[i].size();
	int flag = 0;
	for (int j = 0;j<sz;j++) {
		if (val&(1<<v[i][j])) {
			flag = 1;
			break;
		}
	}
	bf(i+1, val);
	if (!flag) bf(i+1, val | (1<<i));
	return 0;
}

int main() {
	for (int i=0;i<8;i++) cin >> a[i];
	cin >> n;
	for (int i=0;i<n;i++) {
		int x, y;
		cin >> x >> y;
		x--;y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bf(0, 0);
	cout << mx << endl;
	return 0;
}
