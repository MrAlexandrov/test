#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef pair <ll, ll> pll;

const ll N = 2e2 + 8;

ll n, k;
vector <ll> a(N);
vector <vector <ll>> g(N);
vector <vector <ll>> anc(N, vector <ll>(10, 0));
vector <ll> depth(N);
ll d[N][N];

void DFS(ll v, ll p) {
    if (v != p) {
        depth[v] = depth[p] + 1;
    }
    anc[v][0] = p;
    for (ll i = 1; i < 10; ++i) {
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
    for (ll i = 9; i >= 0; --i) {
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
    for (ll i = 9; i >= 0; --i) {
        ll tv = anc[v][i], tu = anc[u][i];
        if (tv != tu) {
            v = tv, u = tu;
        }
    }
    return anc[v][0];
}

vector <bool> ok(N, true);

ll dist(ll v, ll u) {
    return depth[v] + depth[u] - 2 * depth[lca(v, u)];
}

ll ans = 0, now = 0;
vector <bool> was(N, false);

void DFS1(ll v) {
    now += a[v];
    ans = max(ans, now);
    vector <ll> del;
    if (!was[v]) {
        for (ll i = 0; i < n; ++i) {
            if (d[v][i] <= k && ok[i]) {
                ok[i] = false;
                del.push_back(i);
            }
        }
        for (ll u = 0; u < n; ++u) {
            if (ok[u]) {
                DFS1(u);
            }
        }
    }
    now -= a[v];
    for (ll i : del) {
        ok[i] = true;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> k;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; ++i) {
        ll v, u;
        cin >> v >> u;
        --v, --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    DFS(0, 0);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            d[i][j] = d[j][i] = dist(i, j);
        }
    }
    for (ll i = 0; i < n; ++i) {
        DFS1(i);
        was[i] = true;
    }
    cout << ans << '\n';
    return 0;
}

/**


**/
