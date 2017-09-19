#include <bits/stdc++.h>
#define MAX 1000001
#define M 1000000007
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;

int sumOfDigits(int x){
	int sum = 0;
	while(x){
		int digit = x%10;
		sum+=(digit * digit);
		x/=10;
	}
	return sum;
}

int main(){
	while(1){
		int n, m;
		cin >> n >> m;
		if (!n && !m) return 0;
		map <int, int> mark1, mark2;
		vector <int> v1, v2;
		int temp = n;
		while(1){
			if (mark1[temp]==1) break;
			v1.push_back(temp);
			mark1[temp] = 1;
			temp = sumOfDigits(temp);
		}

		temp = m;
		while(1){
			if (mark2[temp]==1) break;
			v2.push_back(temp);
			mark2[temp] = 1;
			temp = sumOfDigits(temp);
		}

		mark1.clear();

		int sz1 = v1.size();
		for (int i=0;i<sz1;i++){
			if (!mark1[v1[i]]) mark1[v1[i]] = i+1;
		}

		int sz2 = v2.size();
		int mn = INT_MAX;

		for (int i=0;i<sz2;i++){
			if (mark1[v2[i]]) mn = min(mn, i+1+mark1[v2[i]]);
		}

		cout << n << " " << m << " ";
		if (mn==INT_MAX) cout << 0 << endl;
		else cout << mn << endl;
	}
	return 0;
}
