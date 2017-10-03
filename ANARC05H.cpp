#include <bits/stdc++.h>
using namespace std;

char s[26];
int l;
int dp[250][26];

int func(int prev,int i){
	if (i==l) return 1;
	if (dp[prev][i]>0) return dp[prev][i];
	int sum = 0,tot = 0;
	for (int j=i;j<l;j++){
		sum+=(int(s[j]-48));
		if (sum>=prev) tot+=func(sum,j+1);
	}
	dp[prev][i] = tot;
	return tot;
}

int main(){
	int cs = 1;
	while (1){
		memset(dp,0,sizeof(dp));
		scanf("%s",s);
		if (s[0]=='b') break;
		l = strlen(s);
		cout << cs++ << ". " << func(0,0) << endl;
	}
	return 0;
}

