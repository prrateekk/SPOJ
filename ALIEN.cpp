#include <bits/stdc++.h>

#define ll long long

#define scan(n) scanf("%d",&n)
#define set(x,y) memset(x,y,sizeof(x))
#define fori(l,r,x) for (int i=l;i<=r;i+=x)
#define forj(l,r,x) for (int j=l;j<=r;j+=x)

#define INF 1000000000
#define M 1000000
#define MAX 1000000
#define X 6
#define LIM 10

using namespace std;

int a[100001],pre[100001],n;

int init(){
	int t;
	scan(t);
	while(t--){
		int x;
		scan(n);
		scan(x);
		fori(1,n,1) scan(a[i]);
		fori(1,n,1) pre[i] = pre[i-1]+a[i];
		int stations=0,humans=0;
		fori(1,n,1){
			if (pre[i]-pre[i-1]>x) continue;
			else if (pre[n]-pre[i-1]<=x){
				int tm = pre[n]-pre[i-1];
				int temp = n-i+1;
				if (temp>stations){
					stations = temp;
					humans = tm;
				}
				else if (temp==stations){
					if (tm<humans)humans=tm;
				}
			}
			else{
				//int in = bs(i,n,pre[i-1]+x);
				int l,r,mid=-1,in;
				l=i;
				r=n;
				int x1 = pre[i-1]+x;
				while(l<=r){
					mid = (l+r)>>1;
					if (pre[mid]<=x1){
						if (mid==n) {
							in = mid;
							break;
						}
						else if (pre[mid+1]>x1){
							in=mid;
							break;
						}
						else l=mid+1;
					}
					else r=mid-1;
				}
				int temp = in-i+1;
				if (temp>stations){
					stations = temp;
					humans = pre[in]-pre[i-1];
				}
				else if (temp==stations){
					int tm = pre[in]-pre[i-1];
					if (tm<humans) humans = tm;
				}
			}
		}
		cout << humans << " " << stations << endl;
	}
	return 0;
}

int main(){
	//clock_t tStart = clock();
	init();
	//printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}

