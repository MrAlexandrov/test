#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = (ll)1e5 + 8;

ll n, m;
vector <bool> root(N, true);
vector <ll> g[N];
vector <ll> a(N);
ll C = 0;
vector <ll> c(N, 0);            ///color
vector <ll> h(N);               ///depth
vector <bool> can(N, false);

void DFS1 (ll v, ll col, ll dist) {
    c[v] = col;
    h[v] = dist;
    for (ll u : g[v]) {
        if (c[u] == 0) {
            DFS1(u, col, dist + 1);
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
        root[u] = false;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    cout << "root: ";
    for (ll i = 0; i < n; ++i)
        cout << root[i] << ' ';
    cout << endl;
    for (ll i = 0; i < n; ++i) {
        if (root[i]) {
            DFS1(i, ++C, 0);
        }
    }
    cout << "color: ";
    for (ll i = 0; i < n; ++i)
        cout << c[i] << ' ';
    cout << endl;
    cout << "depth: ";
    for (ll i = 0; i < n; ++i)
        cout << h[i] << ' ';
    cout << endl;
    for (ll i = 0; i < n; ++i) {
        ll t;
        cin >> t;
        --t;
        a[i] = t;
        can[i] = ((c[i] == c[t] && h[i] < h[t]) || i == t);
    }
    for (ll i = 0; i < n; ++i)
        cout << can[i] << ' ';
    return 0;
}

/**


**/
