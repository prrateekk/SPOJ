#include <bits/stdc++.h>
#define MAX 1000001
#define M 100000000
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;

int n, original, dp[10][10][10][10][101];

int compare(int a, int b, int c, int d) {
	int num = ((a*10+b)*10+c)*10+d;
	if (num>original) return 1;
	else return 0;
}

int DP(int a, int b, int c, int d, int x) {
	a%=10;b%=10;c%=10;d%=10;
	if (x==n) return compare(a, b, c, d);
	if (dp[a][b][c][d][x]!=-1) return dp[a][b][c][d][x]; 
	if (x%2==0) {
		dp[a][b][c][d][x] = DP(a+1, b, c, d, x+1) | DP(a, b+1, c, d, x+1) | DP(a, b, c+1, d, x+1) | DP(a, b, c, d+1, x+1);
	}
	else {
		dp[a][b][c][d][x] = DP(a+1, b, c, d, x+1) & DP(a, b+1, c, d, x+1) & DP(a, b, c+1, d, x+1) & DP(a, b, c, d+1, x+1);
	}
	return dp[a][b][c][d][x];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> original >> n;
		for (int i=0;i<10;i++) {
			for (int j=0;j<10;j++) {
				for (int k=0;k<10;k++) {
					for (int l=0;l<10;l++) {
						for (int m=0;m<=100;m++) {
							dp[i][j][k][l][m] = -1;
						}
					}
				}
			}
		}
		int temp = original;
		int d = temp%10;
		temp/=10;
		int c = temp%10;
		temp/=10;
		int b = temp%10;
		temp/=10;
		int a = temp;
		if (DP(a, b, c, d, 0)) cout << "Ada\n";
		else cout << "Vinit\n";
	}
	return 0;
}
