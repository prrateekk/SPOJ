#include <bits/stdc++.h>
#define MAX 1000001
#define M 1000000007
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;

vector<int> v;

int check(int x) {
	int i = 2;
	int c = 0;
	while(x!=1) {
		if (x%i==0) {
			c++;
			while(x%i==0) x/=i;
		}
		if (c>=3) return 1;
		i++;
	}
	return 0;
}

int main() {
	for (int i=2;i<2665;i++) {
		if (check(i)) v.push_back(i);
	} 
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << v[n-1] << endl;
	}
	return 0;
}