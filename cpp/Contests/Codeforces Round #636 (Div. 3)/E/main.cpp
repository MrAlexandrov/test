#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 2e5 + 8;
const ll INF = (ll)1e18;

vector <vector <ll>> g(N);
vector <ll> p(N), pref(N);
ll n, m, a, b, c;

void BFS(ll v, vector <ll> &d) {
    d.resize(n, -1);
    d[v] = 0;
    queue <pll> q;
    q.emplace(d[v], v);
    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        ll x = t.second;
        for (ll to : g[x]) {
            if (d[to] != -1) {
                continue;
            }
            d[to] = d[x] + 1;
            q.emplace(d[to], to);
        }
    }
}

ll sum(ll x) {
    if (x > m) {
        return INF;
    }
    if (x <= 0) {
        return 0;
    } else {
        return pref[x - 1];
    }
}

ll solve() {
    cin >> n >> m >> a >> b >> c;
    --a, --b, --c;
    for (ll i = 0; i < m; ++i) {
        cin >> p[i];
    }
    sort(p.begin(), p.begin() + m);
    pref[0] = p[0];
    for (ll i = 1; i < m; ++i) {
        pref[i] = pref[i - 1] + p[i];
    }
    for (ll i = 0; i < m; ++i) {
        ll v, u;
        cin >> v >> u;
        --v, --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    vector <ll> d1, d2, d3;
    BFS(a, d1);
    BFS(b, d2);
    BFS(c, d3);
    ll ans = 2 * pref[m - 1];
    ll now = 0;
    for (ll d = 0; d < n; ++d) {
        ll x = d1[d], y = d2[d], z = d3[d];
        now = sum(x + y + z) + sum(y);
        ans = min(ans, now);
    }
    for (ll i = 0; i < n; ++i) {
        g[i].clear();
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll T;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}

/**


**/
