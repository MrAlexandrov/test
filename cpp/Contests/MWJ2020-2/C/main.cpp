#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;

const ld EPS = 1e-7;
const ll N = 1e3 + 8;

ll n;
vector <ll> g[N];
vector <bool> was(N, false);
vector <ll> color(N, 0LL);
vector <vector <ll>> a;
bool ok = true;

ld dist (ll x1, ll y1, ll x2, ll y2) {
    return (ld)sqrt(1.0 * (x1 - x2) * (x1 - x2) + 1.0 * (y1 - y2) * (y1 - y2));
}

void DFS (ll v, ll col) {
    was[v] = true;
    color[v] = col;
    for (ll u : g[v]) {
        if (!was[u]) {
            DFS(u, col + 1);
        }
        if (color[v] % 2 == color[u] % 2) {
            ok = false;
        }
    }
}

bool check (ld m) {
    for (ll i = 0; i < n; ++i)
        g[i].clear();

    for (ll i = 0; i < n; ++i) {
        for (ll j = i + 1; j < n; ++j) {
            ld d = dist(a[i][0], a[i][1], a[j][0], a[j][1]);
            if (d - a[i][2] - a[j][2] < m) return false;
            if (d - a[i][2] - a[j][2] < 2 * m) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    ok = true;
    fill(was.begin(), was.end(), false);
    fill(color.begin(), color.end(), 0LL);
    DFS(0, 1);
    return ok;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cout.precision(20);
    cin >> n;
    a.resize(n, vector <ll>(3));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }
    ld l = 0, r = 1e12;
    while (r - l > EPS) {
        ld m = (l + r) / 2;
        if (check(m))
            l = m;
        else
            r = m;
    }
    cout << l << endl;
    return 0;
}

/**


**/
