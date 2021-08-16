#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 1e5 + 8;

ll n;
vector <vector <ll>> g(N);
ll mn, mx;
ll a, b;
pll best = {0, 0};
ll root, far;
vector <ll> dist(N, 0);
vector <ll> is(N, 0);

vector <set <ll>> g1;

void DFS1(ll v, ll p, ll d) {
    if (d > best.second) {
        best = {v, d};
    }
    for (ll u : g[v]) {
        if (u == p) {
            continue;
        }
        DFS1(u, v, d + 1);
    }
}

void DFS2(ll v, ll p, ll d) {
    dist[v] = d;
    if (d > best.second) {
        best = {v, d};
    }
    if (g[v].size() == 1) {
        ++is[d];
    }
    for (ll u : g[v]) {
        if (u == p) {
            continue;
        }
        DFS2(u, v, d + 1);
    }
}

ll del(vector <set <ll>> &g1) {
    ll res = 0;
    set <pll> now;
    for (ll i = 0; i < n; ++i) {
        if (g1[i].size() == 1) {
            ll v = i, u = *g1[i].begin();
            now.insert({min(v, u), max(v, u)});
        }
    }
    res = now.size();
    for (pll t : now) {
        ll v = t.first, u = t.second;
        g1[v].erase(u);
        g1[u].erase(v);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    for (ll i = 0; i < n - 1; ++i) {
        ll v, u;
        cin >> v >> u;
        --v, --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    DFS1(0, 0, 0);
    root = best.first;
    far = root;
    best = {root, 0};
    DFS2(root, root, 0);
    set <ll> s;
    for (ll i = 0; i < n; ++i) {
        if (is[i]) {
            s.insert(i % 2);
        }
    }
    if (s.size() == 1) {
        mn = 1;
    } else {
        mn = 3;
    }
    ll leafs = 0;
    set <ll> v;
    for (ll i = 0; i < n; ++i) {
        if (g[i].size() == 1) {
            ++leafs;
            v.insert(g[i][0]);
        }
    }
    mx = (n - 1) - leafs + v.size();
    cout << mn << ' ' << mx << '\n';
    return 0;
}

/**


**/
