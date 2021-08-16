#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 2e5 + 8;
ll n, m;
vector <ll> g[N];
vector <ll> ans(N, 0);
vector <bool> was(N, false);

void DFS (ll v) {
    was[v] = true;
    if (g[v].size() == 0) {
        ans[v] = 0;
        return;
    }
    for (ll u : g[v]) {
        if (!was[u])
            DFS(u);
        ans[v] = max(ans[v], ans[u] + 1);
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
        g[v].push_back(u);
    }
    for (ll i = 0; i < n; ++i)
        if (!was[i])
            DFS(i);
    ll mx = 0;
    for (ll i = 0; i < n; ++i)
        if (ans[i] > mx)
            mx = ans[i];
    cout << mx;
    return 0;
}

/**


**/
