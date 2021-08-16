#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 1e5 + 8;

ll n;
vector <vector <ll>> g(N);
vector <pll> edge;
map <pll, ll> ans;

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
        edge.push_back({min(v, u), max(v, u)});
    }
    ll mx = 0;
    for (ll i = 0; i < n; ++i) {
        if (g[i].size() > g[mx].size()) {
            mx = i;
        }
    }
    if (g[mx].size() < 3) {
        for (ll i = 0; i < n - 1; ++i) {
            cout << i << ' ';
        }
        cout << '\n';
        return 0;
    }
    ll ptr = 0;
    for (ll u : g[mx]) {
        ans[{min(mx, u), max(mx, u)}] = ptr++;
    }
    for (pll i : edge) {
        if (ans.find(i) == ans.end()) {
            ans[i] = ptr++;
        }
    }
    for (pll i : edge) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}

/**


**/
