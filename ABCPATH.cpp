#include <bits/stdc++.h>
#define MAX 1000001
#define M 1000000007
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;

int n, m, dp[51][51];
string s[50];

int isValid(int x, int y){
	if (x>=0 && y>=0 && x<n && y<m){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	int cn = 1;
	while(1){
		scanf("%d%d", &n, &m);
		if (!n) return 0;
		for (int i=0;i<=50;i++){
			for (int j=0;j<=50;j++) dp[i][j] = 0;
		}
		for (int i=0;i<n;i++){
			cin >> s[i];
		}
		for (int i=96;i>=65;i--){
			for (int j=0;j<n;j++){
				for (int k=0;k<m;k++){
					if (s[j][k]==char(i)){
						if (isValid(j-1, k-1) && s[j-1][k-1]==char(i+1)) dp[j][k] = max(dp[j][k], dp[j-1][k-1]+1);
						if (isValid(j-1, k) && s[j-1][k]==char(i+1)) dp[j][k] = max(dp[j][k], dp[j-1][k]+1);
						if (isValid(j-1, k+1) && s[j-1][k+1]==char(i+1)) dp[j][k] = max(dp[j][k], dp[j-1][k+1]+1);
						if (isValid(j, k-1) && s[j][k-1]==char(i+1)) dp[j][k] = max(dp[j][k], dp[j][k-1]+1);
						if (isValid(j, k+1) && s[j][k+1]==char(i+1)) dp[j][k] = max(dp[j][k], dp[j][k+1]+1);
						if (isValid(j+1, k-1) && s[j+1][k-1]==char(i+1)) dp[j][k] = max(dp[j][k], dp[j+1][k-1]+1);
						if (isValid(j+1, k) && s[j+1][k]==char(i+1)) dp[j][k] = max(dp[j][k], dp[j+1][k]+1);
						if (isValid(j+1, k+1) && s[j+1][k+1]==char(i+1)) dp[j][k] = max(dp[j][k], dp[j+1][k+1]+1);
					}
				}
			}
		}
		int mx = 0;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				if (s[i][j]=='A') mx = max(mx, dp[i][j]+1);
			}
		}
		printf("Case %d: ", cn++);
		cout << mx << endl;
	}
	return 0;
}
