// https://codeforces.com/contest/1249/problem/C2

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
typedef unsigned long long ull;

// struct queries {
// 	ll index;
// 	ll n;
// 	ull val;
// } ar[100010];

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

// ull pwrs3[40];

// void prepare() {
// 	int i;
// 	ull v = 1;
// 	for (i = 0; i < 40; i++) {
// 		pwrs3[i] = v;
// 		v = v * 3;
// 	}
// }

string base3rep(ll n) {
	string ans = "";
	ll i, r;
	for (i = 39; i >= 0; i--) {
		r = n % 3;
		ans = (char)(r + 48) + ans;
		n = n / 3;
	}
	return ans;
}

ll contains2(string str) {
	for (int i = 0; i < str.size(); i++) {
		if(str[i] == '2') {
			return 1;
		}
	}
	return 0;
}

string nextb3(string str) {
	int len = str.size(), i, j;
	int first_2, first_0;
	string conv = str;
	for (i = 0; i < len; i++) {
		if (conv[i] == '2') {
			first_2 = i;
			break;
		}
	}
	// cout << "first 2 at " << first_2 << endl;

	for (j = first_2; j >= 0; j--) {
		if (conv[j] == '0') {
			first_0 = j;
			break;
		}
	}

	// cout << "first 0 at " << first_0 << endl;

	conv[first_0] = '1';
	for (i = first_0 + 1; i < len; i++) {
		conv[i] = '0';
	}
	return conv;
}

ull convertb3(string str) {
	ull num = 0;
	ll v = 1;
	int len = str.size(), i;
	for (i = len - 1; i >= 0; i--) {
		num = num + (str[i] - '0')*v;
		v = v * 3;
	}
	return num;
}

int main () {
	// freopen ("input.txt", "r", stdin);
	// prepare();
	ll t, n, i, flag;
	string b3, nextb;

	cin >> t;
	// t = 1;
	while (t--) {
		cin >> n;
		b3 = base3rep(n);
		flag = contains2(b3);
		// cout << "------------------" << endl;
		if (flag == 0) {
			cout << n << endl;
		} else {
			nextb = nextb3(b3);
			// cout << "next num  : " << nextb << endl;
			ull num = convertb3(nextb);
			cout << num << endl;
		}
		// cout << "------------------" << endl;
	}
	return 0;
}

