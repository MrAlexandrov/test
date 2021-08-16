#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 1e5 + 8;
ll n, m;
set <ll> g[N];
set <ll> unused;
ll ans = 0;

void DFS (ll v) {
    unused.erase(v);
    auto it = unused.begin();
    while (it != unused.end()) {
        if (g[v].find(*it) == g[v].end()) {
            ll u = *it;
            DFS(u);
            it = unused.lower_bound(u);
        }
        else {
            ++it;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll v, u;
        cin >> v >> u;
        --v, --u;
        g[v].insert(u);
        g[u].insert(v);
    }
    for (ll i = 0; i < n; ++i)
        unused.insert(i);
    for (ll i = 0; i < n; ++i) {
        if (unused.count(i)) {
            ++ans;
            DFS(i);
        }
    }
    cout << ans - 1;
    return 0;
}

/**


**/
