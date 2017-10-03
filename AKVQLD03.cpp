#include <bits/stdc++.h>
#define MAX 1000001
#define M 1000000007
#define ll long long
#define ld long double
#define ESP 0.0001

#define left (2*i+1)
#define right (2*i+2)
#define mid ((l+r)>>1)
using namespace std;

ll seg[MAX*10];

int update(int i, int l, int r, int x, int v) {
	if (l>r) return 0;
	if (x>=l && x<=r) {
		seg[i]+=v;
		if (l==r) return 0;
		update(left, l, mid, x, v);
		update(right, mid+1, r, x, v);
	}
	return 0;
}

ll query(int i, int l, int r, int x, int y) {
	if (l>r || y<l || x>r) return 0;
	if (l>=x && r<=y) return seg[i];
	else return query(left, l, mid, x, y) + query(right, mid+1, r, x, y);
}

int main() {
	int n, q;
	cin >> n >> q;
	for (int i=0;i<q;i++) {
		string s;
		cin >> s;
		if (s=="find") {
			int x, y;
			cin >> x >> y;
			cout << query(0, 0, n, x, y) << endl;
		}
		else {
			int x, v;
			cin >> x >> v;
			update(0, 0, n, x, v);
		}
	}
	return 0;
}
