#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll int rev(ll int x){
	ll int sum = 0;
	while (x){
		sum+=x%10;
		sum*=10;
		x/=10;
	}
	return sum/10;
}

int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		ll int a,b;
		scanf("%lld%lld",&a,&b);
		cout << rev(rev(a)+rev(b)) << endl;
	}
	return 0;
}

