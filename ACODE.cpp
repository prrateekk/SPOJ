#include <bits/stdc++.h>
using namespace std;

char s[5001];
int dp[5002],n;

int func(){
	int start;
	dp[n]=1;
	if (s[n-1]=='0'){
		start=n-3;
		dp[n-2]=1;
	}
	else{
		start=n-2;
		dp[n-1]=1;
	}
	for (int i=start;i>=0;i--){
		if (s[i]!='0'){
			if (s[i]=='1'||s[i]=='2'&&s[i+1]<='6'){
				dp[i]=dp[i+1]+dp[i+2];
			}
			else{
				dp[i]=dp[i+1];
			}
		}
	}
	return dp[0];
}

int main(){
	while (1){
		scanf("%s",s);
		if (s[0]=='0') break;
		n=strlen(s);
		printf("%d\n",func());
		memset(dp,0,sizeof(dp));
	}
	return 0;
}

