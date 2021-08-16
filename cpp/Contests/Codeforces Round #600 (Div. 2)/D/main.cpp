#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll INF = INT_MAX;
const ll N = 2e5 + 8;
ll n, m;
vector <ll> g[N];
ll col = 0;
vector <ll> color(N);
ll mn, mx;

void DFS (ll u) {
    color[u] = col;
    mn = min(mn, u);
    mx = max(mx, u);
    for (ll v : g[u])
        if (color[v] == 0)
            DFS (v);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector <pll> solve;
    for (ll i = 0; i < n; ++i) {
        if (!color[i]) {
            ++col;
            mn = INF, mx = -INF;
            DFS (i);
            solve.push_back({mn, mx});
        }
    }
    sort(solve.begin(), solve.end());
    ll ans = 0;
    n = solve.size();
    mx = -INF;
    for (ll i = 0; i < n; ++i) {
        if (solve[i].first <= mx)
            ++ans;
        mx = max(mx, solve[i].second);
    }
    cout << ans;
    return 0;
}

/**


**/
