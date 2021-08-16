#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 2e5 + 8;

ll n, m, k;
vector <ll> a;
vector <vector <ll>> g(N);
vector <ll> d[2];

void BFS(ll s, vector <ll> &d) {
    fill(d.begin(), d.end(), N);
    d[s] = 0;
    queue <ll> q;
    q.push(s);
    while (!q.empty()) {
         ll v = q.front();
         q.pop();
         for (ll u : g[v]) {
            if (d[u] == N) {
                d[u] = d[v] + 1;
                q.push(u);
            }
         }
    }
}

bool cmp(pll a, pll b) {
    return a.first - a.second < y.first - y.second;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    a.resize(k);
    for (ll i = 0; i < k; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (ll i = 0; i < m; ++i) {
        ll v, u;
        cin >> v >> u;
        --v, --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    d[0].resize(n);
    d[1].resize(n);
    BFS(0, d[0]);
    BFS(n - 1, d[1]);
    vector <pll> solve;
    for (ll i = 0; i < n; ++i) {
        solve.
    }
    return 0;
}

/**


**/
