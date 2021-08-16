#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 2e5 + 8;

ll n, k;
vector <vector <ll>> g(N);
vector <ll> depth(N);
vector <ll> sz(N);
vector <ll> dad(N);

void DFS(ll v, ll p, ll d) {
    depth[v] = d;
    sz[v] = 1;
    dad[v] = p;
    for (ll to : g[v]) {
        if (to == p) {
            continue;
        }
        DFS(to, v, d + 1);
        sz[v] += sz[to];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> k;
    k = n - k;
    for (ll i = 0; i < n - 1; ++i) {
        ll v, u;
        cin >> v >> u;
        --v, --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    DFS(0, 0, 0);
    priority_queue <pll> q;
    q.push({sz[0] - 1 - depth[0], 0LL});
    ll ans = 0;
    for (ll i = 0; i < k; ++i) {
        ll now = q.top().first, v = q.top().second;
        q.pop();
        ans += now;
        for (ll to : g[v]) {
            if (to == dad[v]) {
                continue;
            }
            q.push({sz[to] - 1 - depth[to], to});
        }
    }
    cout << ans << '\n';
    return 0;
}

/**


**/
