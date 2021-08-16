#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 2e5 + 8;

ll n;
vector <bool> a;
vector <vector <ll>> g(N);
vector <vector <ll>> cnt(2, vector <ll>(N, 0));
vector <bool> used(N, false);
vector <ll> ans(N, 0);

void DFS(ll v) {
    used[v] = true;
    cnt[a[v]][v]++;
    for (ll to : g[v]) {
        if (used[to]) {
            continue;
        }
        DFS(to);
        if (cnt[0][to] > cnt[1][to]) {
            cnt[0][v] += cnt[0][to];
            cnt[1][v] += cnt[1][to];
        }
    }
}

void change(ll v, ll to) {
    if (cnt[0][to] - cnt[1][to] > 0) {
        cnt[0][v] -= cnt[0][to];
        cnt[1][v] -= cnt[1][to];
    }
    if (cnt[0][v] - cnt[1][v] > 0) {
        cnt[0][to] += cnt[0][v];
        cnt[1][to] += cnt[1][v];
    }
}

void DFS1(ll v) {
    used[v] = true;
    ans[v] = cnt[0][v] - cnt[1][v];
    for (ll to : g[v]) {
        if (used[to]) {
            continue;
        }
        change(v, to);
        DFS1(to);
        change(to, v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    a.resize(n);
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a[i] = (x == 0);
    }
    for (ll i = 0; i < n - 1; ++i) {
        ll v, u;
        cin >> v >> u;
        --v, --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    DFS(0);
    fill(used.begin(), used.end(), false);
    DFS1(0);
    for (ll i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}

/**


**/
