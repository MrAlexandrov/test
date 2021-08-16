#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 2e5 + 8;

ll n, m;
vector <vector <ll>> g(N);
vector <vector <ll>> anc(N, vector <ll>(20, 0));
vector <ll> depth(N, 0);

void DFS(ll v, ll p) {
    if (v != p) {
        depth[v] = depth[p] + 1;
    }
    anc[v][0] = p;
    for (ll i = 1; i < 20; ++i) {
        anc[v][i] = anc[anc[v][i - 1]][i - 1];
    }
    for (ll u : g[v]) {
        if (u == p) {
            continue;
        }
        DFS(u, v);
    }
}

ll up(ll v, ll n) {
    for (ll i = 19; i >= 0; --i) {
        ll t = 1LL << i;
        if (n >= t) {
            n -= t;
            v = anc[v][i];
        }
    }
    return v;
}

ll lca(ll v, ll u) {
    if (depth[v] < depth[u]) {
        swap(v, u);
    }
    v = up(v, depth[v] - depth[u]);
    if (v == u) {
        return v;
    }
    for (ll i = 19; i >= 0; --i) {
        ll tv = anc[v][i], tu = anc[u][i];
        if (tv != tu) {
            v = tv, u = tu;
        }
    }
    return anc[v][0];
}

ll dist(ll v, ll u) {
    return depth[v] + depth[u] - 2 * depth[lca(v, u)];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> m;
    for (ll i = 0; i < n - 1; ++i) {
        ll v, u;
        cin >> v >> u;
        --v, --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    DFS(0, 0);
    for (ll i = 0; i < m; ++i) {
        ll k;
        cin >> k;
        vector <ll> a(k);
        ll root = 0;
        for (ll j = 0; j < k; ++j) {
            cin >> a[j];
            --a[j];
            if (depth[a[j]] > depth[root]) {
                root = a[j];
            }
        }
        bool ok = true;
        for (ll j = 0; j < k; ++j) {
            ll x = lca(root, a[j]);
            if (!(x == a[j] || dist(x, a[j]) == 1)) {
                ok = false;
            }
        }
        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}

/**


**/
