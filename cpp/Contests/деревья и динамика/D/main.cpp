#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 2e5 + 8;

ll n;
vector <ll> g[N];
vector <ll> sz(N, 0);
ll mx = 0, x, ans = 0;

void DFS1 (ll v, ll from, ll now) {
    cout << v << ' ' << from << ' ' << now << endl;
    if (mx < now) {
        mx = now;
        x = v;
    }
    for (ll u : g[v]) {
        if (u != from) {
            DFS1(u, v, now + 1);
        }
    }
}

void DFS2 (ll v, ll from) {
    sz[v] = 1;
    if (g[v].size() == 1 && v != from)
        return;
    for (ll u : g[v]) {
        if (u != from) {
            if (sz[u] == 0) {
                DFS2(u, v);
            }
            sz[v] += sz[u];
        }
    }
}

void DFS3 (ll v, ll from) {
    ans += sz[v];
    for (ll u : g[v]) {
        if (u != from) {
            DFS3(u, v);
        }
    }
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
    cout << mx << ' ' << x << endl;
    DFS2(x, x);
    for (ll i = 0; i < n; ++i)
        cout << sz[i] << ' ';
    cout << endl;
    DFS3(x, x);
    cout << ans << endl;
    return 0;
}

/**


**/
