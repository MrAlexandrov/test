#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 15e4 + 8;

ll n;
vector <vector <ll>> g(N);
vector <ll> a(N);
vector <ll> pref(N);

void DFS1(ll v, ll p = 0) {
    for (ll u : g[v]) {
        if (u == p) {
            continue;
        }
        DFS1(u, v);
    }
    pref[v] =
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (ll i = 0; i < n - 1; ++i) {
        ll v, u;
        cin >> v >> u;
        --v, --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    DFS1(0);
    return 0;
}

/**


**/
