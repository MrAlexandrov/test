#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 1e2 + 8;
set <ll> a[N];
vector <ll> g[N];
vector <bool> was(N, false);
ll col = 0;
ll n, m;

void DFS(ll v) {
    was[v] = true;
    for (ll u : g[v]) {
        if (!was[u]) {
            DFS(u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> m;
    for (ll i = 0; i < n; ++i) {
        ll k;
        cin >> k;
        for (ll j = 0; j < k; ++j) {
            ll x;
            cin >> x;
            --x;
            a[i].insert(x);
        }
        for (ll j : a[i]) {
            for (ll q = i - 1; q >= 0; --q) {
                auto t = a[q].lower_bound(j);
                if (t == a[q].end()) continue;
                else {
                    if (*t == j) {
                        g[i].push_back(q);
                        g[q].push_back(i);
                    }
                }
            }
        }
    }
    for (ll i = 0; i < n; ++i) {
        if (!was[i]) {
            ++col;
            DFS(i);
        }
    }
    cout << col - 1 << endl;;
    return 0;
}

/**


**/
