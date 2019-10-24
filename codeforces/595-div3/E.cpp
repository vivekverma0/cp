// Problem link : https://codeforces.com/contest/1249/problem/E

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#define M 1000000007
using namespace std;
typedef long long ll;

ll ar[1000010];

ll powr(ll a, ll p, ll m) {
	if (p == 0) {
		return 1;
	}
	if (p%2 == 0) {
		ll x = powr(a, p/2, m);
		return 	(x*x)%m;
	}
	return (a*powr(a, p-1, m) ) % m;
}

ll MIN(ll a, ll b) {
	if (a < b) return a;
	return b;
}

ll a[1000010];
ll b[1000010];
ll mint[1000010][2];

int main () {
	ll t, n, c, i;
	cin >> n >> c;
	for (i = 1; i < n; i++) {
		cin >> a[i];
	}

	for (i = 1; i < n; i++) {
		cin >> b[i];
	}

	mint[1][0] = 0; mint[1][1] = c;

	for (i = 2; i <= n; i++) {
		mint[i][0] = MIN(mint[i-1][0], mint[i-1][1]) + a[i-1];
		mint[i][1] = MIN(mint[i-1][1], mint[i-1][0] + c) + b[i-1];
	}

	for (i = 1; i <= n; i++) {
		cout << MIN(mint[i][0], mint[i][1]) << " ";
	}
	cout << endl;
	return 0;
}