#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		int n;
		scanf("%d",&n);
		if (n%2==0) cout << n/2 << endl;
		else cout << n/2+1 << endl;
	}
	return 0;
}

