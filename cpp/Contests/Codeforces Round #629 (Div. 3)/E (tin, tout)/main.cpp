#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 2e5 + 8;

ll n, m;
vector <vector <ll>> g(N);
vector <ll> anc(N), depth(N);
vector <ll> tin(N), tout(N);

ll T = 0;

void DFS(ll v, ll p, ll d) {
    tin[v] = T++;
    anc[v] = p, depth[v] = d;
    for (ll u : g[v]) {
        if (u == p) {
            continue;
        }
        DFS(u, v, d + 1);
    }
    tout[v] = T++;
}

bool pred(ll v, ll u) {
    return (tin[u] <= tin[v] && tout[v] <= tout[u]);
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
    DFS(0, 0, 0);
    for (ll i = 0; i < m; ++i) {
        ll k;
        cin >> k;
        vector <ll> a(k);
        ll root = 0;
        for (ll i = 0; i < k; ++i) {
            cin >> a[i];
            --a[i];
            a[i] = anc[a[i]];
            if (depth[a[i]] > depth[root]) {
                root = a[i];
            }
        }
        bool ok = true;
        for (ll i = 0; i < k; ++i) {
            if (!pred(root, a[i])) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}

/**


**/
