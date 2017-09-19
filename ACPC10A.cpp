#include <bits/stdc++.h>
using namespace std;

int main(){
	while (1){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if (a==0&&b==0&&c==0) break;
		if (a+c==2*b) cout << "AP " << c+b-a << endl;
		else cout << "GP " << (c*c)/b << endl;
	}
	return 0;
}

