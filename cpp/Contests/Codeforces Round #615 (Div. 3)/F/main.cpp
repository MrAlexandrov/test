#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 2e5 + 8;

ll n;
vector <vector <ll>> g(N);

ll ans = 0;
ll a, b, c = -1;
ll dist = 0;

void DFS1(ll v, ll p = -1, ll d = 0) {
    if (d > dist) {
        a = v, dist = d;
    }
    for (ll u : g[v]) {
        if (u == p) {
            continue;
        }
        DFS1(u, v, d + 1);
    }
}

vector <ll> from(N);

void DFS2(ll v, ll p = -1, ll d = 0) {
    from[v] = p;
    if (d > dist) {
        b = v, dist = d;
        ans = dist;
    }
    for (ll u : g[v]) {
        if (u == p) {
            continue;
        }
        DFS2(u, v, d + 1);
    }
}



void DFS4(ll v, ll p, ll d = 1) {
    if (d > dist) {
        c = v, dist = d;
    }
    for (ll u : g[v]) {
        if (u == p) {
            continue;
        }
        DFS4(u, v, d + 1);
    }
}

void DFS3(ll v, ll p = -1) {
    for (ll u : g[v]) {
        if (u == p) {
            continue;
        }
        if (u != from[v]) {
            DFS4(u, v);
        }
        DFS3(u, v);
    }
}

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
    }
    DFS1(0);
    dist = 0;
    DFS2(a);
    dist = 0;
    DFS3(b);
    if (c == -1) {
        for (ll i = 0; i < n; ++i) {
            if (i != a && i != b) {
                c = i;
                break;
            }
        }
        ans -= dist;
    }
    ans += dist;
    cout << ans << endl;
    cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
    return 0;
}

/**


**/
