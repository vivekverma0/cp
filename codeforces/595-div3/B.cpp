// Problem link : https://codeforces.com/contest/1249/problem/B2

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
ll visited[1000010];
ll parent[1000010];
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
	ll t, n, i, j, v, f, curr_parent, index, currComp, currCompSize;
	cin >> t;
	// t = 1;
	while (t--) {
		cin >> n;
		map<ll, vector<ll> > graph;
		map<ll, ll> compsize;
		queue<ll> q;
		for (i = 1; i <= n; i++) {
			cin >> ar[i];
			parent[i] = i;
			graph[i].push_back(ar[i]);
			graph[ar[i]].push_back(i);
			visited[i] = 0;
			// compnum[i] = -1;
		}
		currComp = 0;
		for (i = 1; i <= n; i++) {
			if (visited[i] == 0) {
				currComp++; currCompSize = 1;
				q.push(i);
				visited[i] = 1;
				while (!q.empty()) {
					f = q.front(); q.pop();
					parent[f] = currComp;
					for (j = 0; j < graph[f].size(); j++) {
						if (visited[graph[f][j]] == 0) {
							q.push(graph[f][j]);
							visited[graph[f][j]] = 1;
							currCompSize++;
							parent[graph[f][j]] = currComp;
						}
					}
				}
				compsize[currComp] = currCompSize;
			}
		}

		for (i = 1; i <= n; i++) {
			// cout << i  << " : " << parent[i] << endl;
			cout << compsize[parent[i]] << " ";
		}
		cout << endl;
	}
	return 0;
}