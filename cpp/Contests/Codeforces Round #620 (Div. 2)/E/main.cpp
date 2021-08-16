#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e5 + 8;
const ll lg = 20;

ll n, q;
vector <vector <ll>> g(N);
vector <vector <ll>> anc(N, vector <ll>(lg));
vector <ll> depth(N);

void DFS(ll v, ll p, ll d) {
    depth[v] = d;
    anc[v][0] = p;
    for (ll i = 1; i < lg; ++i) {
        anc[v][i] = anc[ anc[v][i - 1] ][i - 1];
    }
    for (ll u : g[v]) {
        if (u == p) {
            continue;
        }
        DFS(u, v, d + 1);
    }
}

ll up(ll x, ll n) {
    for (ll i = lg - 1; i >= 0; --i) {
        ll t = 1LL << i;
        if (n >= t) {
            n -= t;
            x = anc[x][i];
        }
    }
    return x;
}

ll lca(ll a, ll b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    a = up(a, depth[a] - depth[b]);
    if (a == b) {
        return a;
    }
    for (ll i = lg - 1; i >= 0; --i) {
        ll t = 1LL << i;
        ll aa = up(a, t);
        ll bb = up(b, t);
        if (aa != bb) {
            a = aa;
            b = bb;
        }
    }
    return anc[a][0];
}

ll dist(ll a, ll b) {
    return depth[a] + depth[b] - 2 * depth[lca(a, b)];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (ll i = 0; i < n - 1; ++i) {
        ll v, u;
        cin >> v >> u;
        --v, --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    DFS(0, 0, 0);
    cin >> q;
    for (ll i = 0; i < q; ++i) {
        ll x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        --x, --y, --a, --b;
        ll d1 = dist(a, b);
        if (d1 <= k && d1 % 2 == k % 2) {
            cout << "YES" << endl;
            continue;
        }
        ll d2 = dist(a, x) + 1LL + dist(y, b);
        if (d2 <= k && d2 % 2 == k % 2) {
            cout << "YES" << endl;
            continue;
        }
        ll d3 = dist(a, y) + 1LL + dist(x, b);
        if (d3 <= k && d3 % 2 == k % 2) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}

/**


**/
