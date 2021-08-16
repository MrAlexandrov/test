#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 1e5 + 8;
const ll lg = 20;

ll n, L, S;
vector <ll> W(N);
vector <vector <ll>> g(N);
vector <vector <ll>> anc(N, vector <ll>(20, 0));
vector <ll> depth(N);
vector <ll> sum(N, 0);
struct item {
    ll l, w;
    item(ll _l, ll _w) {
        l = _l, w = _w;
    }
};
vector <item> dp(N, item(0, 0));

void DFS0(ll v, ll now) {
    now += W[v];
    sum[v] = now;
    for (ll u : g[v]) {
        DFS0(u, now);
    }
}

ll ans = 0;

void check(ll v, ll &mx, ll &ind) {
    ll u = v;
    ll l = dp[v].l, w = dp[v].w;
    for (ll i = lg - 1; i >= 0; --i) {
        ll t = 1LL << i;
        if (l + t <= L && w + ((sum[v] - W[v]) - (sum[anc[v][i]] - W[anc[v][i]])) <= S) {
            v = anc[v][i];
            l += t, w += (sum[v] - W[v]) - (sum[anc[v][i]] - W[anc[v][i]]);
        }
    }
    if (depth[u] - depth[v] > mx) {
        mx = depth[u] - depth[v];
        ind = u;
    }
}

void DFS(ll v) {
    ll mx = 0, ind = -1;
    for (ll u : g[v]) {
        DFS(u);
        check(u, mx, ind);
    }
    if (mx == 0) {
        ++ans;
        dp[v] = item(1, W[v]);
    } else {
        dp[v] = item(1 + dp[ind].l, W[v] + dp[ind].w);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> L >> S;
    bool ok = true;
    for (ll i = 0; i < n; ++i) {
        cin >> W[i];
        if (W[i] > S) {
            ok = false;
        }
    }
    depth[0] = 0;
    for (ll i = 1; i < n; ++i) {
        ll x;
        cin >> x;
        --x;
        anc[i][0] = x;
        g[x].push_back(i);
        depth[i] = depth[x] + 1;
        for (ll j = 1; j < lg; ++j) {
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
    }
    if (!ok) {
        cout << "-1\n";
        return 0;
    }
    DFS0(0, 0);
    DFS(0);
    cout << ans << '\n';
    return 0;
}

/**


**/
