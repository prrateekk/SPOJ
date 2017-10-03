#include <bits/stdc++.h>
using namespace std;

int main(){
	while (1){
		map <int,int> m;
		int x,y;
		cin >> x;
		if (x==0) break;
		int a[x];
		for (int i=0;i<x;i++)
			cin >> a[i];
		cin >> y;
		int b[y];
		for (int i=0;i<y;i++)
			cin >> b[i];
		int st[x];
		for (int i=0;i<x;i++){
			m[a[i]]=1;
		}
		int c=0;
		for (int i=0;i<y;i++){
			if (m[b[i]]==1) st[c++]=b[i];
		}
		c--;
		int sx=x-1,sy=y-1,sum=0;
		while (c>=0){
			int sumx=0;
			while (sx>=0){
				if (a[sx]==st[c]) break;
				sumx+=(a[sx]);
				sx--;
			}
			sx--;
			int sumy=0;
			while (sy>=0){
				if (b[sy]==st[c]) break;
				sumy+=(b[sy]);
				sy--;
			}
			sy--;
			sum+=(max(sumx,sumy)+st[c]);
			c--;
		}
		int sumx=0;
		while (sx>=0){
			sumx+=a[sx];
			sx--;
		}
		int sumy=0;
		while (sy>=0){
			sumy+=b[sy];
			sy--;
		}
		sum+=(max(sumx,sumy));
		cout << sum << endl;
	}
	return 0;
}

