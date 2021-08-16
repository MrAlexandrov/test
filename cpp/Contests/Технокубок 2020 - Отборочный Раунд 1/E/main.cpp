#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 5e5 + 8;

ll n, k;
vector <vector <pll>> g(N);
vector <vector <ll>> dp(N, vector <ll>(2));

void calc(ll v, ll p = -1) {
    ll sum = 0;
    vector <ll> take;
    for (pll t : g[v]) {
        ll u = t.first, w = t.second;
        if (u == p) {
            continue;
        }
        calc(u, v);
        sum += dp[u][0];
        take.push_back(dp[u][1] + w - dp[u][0]);
    }
    sort(take.rbegin(), take.rend());
    for (ll i = 0; i < min(k, (ll)take.size()) && take[i] > 0; ++i) {
        sum += take[i];
    }
    dp[v][0] = sum;
    if (take.size() >= k && take[k - 1] > 0) {
        sum -= take[k - 1];
    }
    dp[v][1] = sum;
}

void solve() {
    cin >> n >> k;
    for (ll i = 0; i < n; ++i) {
        g[i].clear();
    }
    for (ll i = 0; i < n - 1; ++i) {
        ll v, u, w;
        cin >> v >> u >> w;
        --v, --u;
        g[v].emplace_back(u, w);
        g[u].emplace_back(v, w);
    }
    calc(0);
    cout << max(dp[0][0], dp[0][1]) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}

/**


**/
