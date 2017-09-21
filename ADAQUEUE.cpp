#include <bits/stdc++.h>
#define MAX 1000001
#define M 100000000
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;

int a[3000000];

int main() {
	int n;
	cin >> n;
	int bin = 0, l = 1500000, r = 1499999;
	while(n--) {
		string s;
		cin >> s;
		if (s=="reverse") bin^=1;
		else if (s=="front") {
			if (l>r) {
				cout << "No job for Ada?\n";
				continue;
			}
			if (!bin) {
				cout << a[l] << endl;
				l++;
			}
			else {
				cout << a[r] << endl;
				r--;
			}
		}
		else if (s=="back") {
			if (l>r) {
				cout << "No job for Ada?\n";
				continue;
			}
			if (bin) {
				cout << a[l] << endl;
				l++;
			}
			else {
				cout << a[r] << endl;
				r--;
			}
		}
		else if (s=="push_back") {
			int x;
			cin >> x;
			if (!bin) a[++r] = x;
			else a[--l] = x;
		}
		else if (s=="toFront") {
			int x;
			cin >> x;
			if (bin) a[++r] = x;
			else a[--l] = x;
		}
	}
	return 0;
}
