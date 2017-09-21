#include <bits/stdc++.h>
#define MAX 1000001
#define M 1000000007
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;

int main() {
	int t;
	int cs = 1;
	scanf("%d",&t);
	while(t--) {
		printf("Case #%d: \n", cs++);
		ll n, m, q;
		scanf("%lld%lld%lld", &n, &m, &q);
		vector< pair<ll,ll > > v[n+1];
		for (int i=0;i<m;i++) {
			ll u, c, l;
			scanf("%lld%lld%lld", &u, &c, &l);
			v[u].push_back(make_pair(c, l));
		}
		ll res[m+1];
		for (int i=0;i<=m;i++) res[i] = 0;
		for (int i=1;i<=n;i++) {
			sort(v[i].begin(), v[i].end(), greater < pair<int,int> >());
			for (int j=0;j<v[i].size();j++) res[j]+=v[i][j].second;
		}
		for (int i=1;i<=m;i++) res[i]+=res[i-1];
		while(q--){
			ll x;
			scanf("%lld", &x);
			if (x>m) x = m;
			printf("%lld\n",res[x-1]);
		}
	}
	return 0;
}
