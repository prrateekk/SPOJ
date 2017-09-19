#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		int n;
		scanf("%d",&n);
		int a[n];
		for (int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		long long int sum = 0;
		int c =1;
		for (int i=0;i<n;i++){
			sum+=((c-n)*a[i]);
			c+=2;
		}
		cout << sum << endl;
	}
	return 0;
}
