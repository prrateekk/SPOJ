#include <bits/stdc++.h>
#define MAX 1000001
#define M 1000000007
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;

int sumDivisors[MAX], p[10*MAX];

int precomputation(){
	int mx = 0;
	for (int i=1;i<MAX;i++){
		for (int j=i;j<MAX;j+=i){
			sumDivisors[j]+=i;
			mx = max(mx, sumDivisors[j]);
		}
	}
	p[0] = p[1] = 1;
	for (ll i=2;i<mx;i++){
		if (!p[i]){
			for (ll j=i*i;j<mx;j+=i){
				p[j] = 1;
			}
		}
	}
	for (int i=1;i<MAX;i++){
		if (p[sumDivisors[i]]){
			sumDivisors[i] = sumDivisors[i-1];
		}
		else{
			sumDivisors[i] = sumDivisors[i-1] + 1;
		}
	}
	return 0;
}

int main(){
	precomputation();
	int t;
	scanf("%d", &t);
	while(t--){
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", sumDivisors[y] - sumDivisors[x-1]);
	}
	return 0;
}
