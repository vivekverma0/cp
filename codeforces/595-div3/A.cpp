// Problem link : https://codeforces.com/contest/1249/problem/A

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

int main () {
	// freopen ("input.txt", "r", stdin);
	ll t, n, i, j, v, even, odd;
	cin >> t;
	// t = 1;
	while (t--) {
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> ar[i];
		}
		sort(ar, ar + n);
		for (i = 1; i < n; i++) {
			if ((ar[i] - ar[i-1]) == 1) {
				break;
			}
		}
		if (i == n) {
			cout << 1 << endl;
		} else {
			cout << 2 << endl;
		}
	}
	return 0;
}