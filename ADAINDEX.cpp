#include <bits/stdc++.h>
#define MAX 1000001
#define M 100000000
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;

struct node {
	struct node* child[26];
	int val;
};

node *root;

int addString(string s) {
	int l = s.length();
	node *temp = root;
	for (int i=0;i<l;i++) {
		if (temp->child[s[i]-'a']==NULL) temp->child[s[i]-'a'] = new node();
		temp = temp->child[s[i]-'a'];
		(temp->val)++;
	}
	return 0;
}

int query(string s) {
	int l = s.length();
	node *temp = root;
	int res;
	for (int i=0;i<l;i++) {
		temp = temp->child[s[i]-'a'];
		if (temp==NULL) return 0;
		res = (temp->val);
	}
	return res;
}

int n, q;

int main() {
	root = new node();
	cin >> n >> q;
	for (int i=0;i<n;i++) {
		string x;
		cin >> x;
		addString(x);
	}
	for (int i=0;i<q;i++) {
		string x;
		cin >> x;
		cout << query(x) << endl;
	}
	return 0;
}
