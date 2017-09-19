#include <bits/stdc++.h>
#define MAX 1000001
#define M 1000000007
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;

int toNumber(string x){
	int num = 0;
	for (int i=0;i<x.length();i++){
		num = (num*10+x[i]-'0');
	}
	return num;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string a, b, c, waste;
		cin >> a >> waste >> b >> waste >> c;
		int flag = 0;
		for (int i=0;i<a.length();i++){
			if (a[i]=='m'){
				flag = 1;
				break;
			}
		}
		if (flag){
			cout << toNumber(c) - toNumber(b) << " + " << toNumber(b) << " = " << toNumber(c) << endl;
			continue;
		}
		for (int i=0;i<b.length();i++){
			if (b[i]=='m'){
				flag = 1;
				break;
			}
		}
		if (flag){
			cout << toNumber(a) << " + " << toNumber(c) - toNumber(a) << " = " << toNumber(c) << endl;
			continue;
		}
		for (int i=0;i<c.length();i++){
			if (c[i]=='m'){
				flag = 1;
				break;
			}
		}
		if (flag){
			cout << toNumber(a) << " + " << toNumber(b) << " = " << toNumber(a) + toNumber(b) << endl;
			continue;
		}
	}
	return 0;
}
