#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 5e3 + 8;

ll n, m;
vector <pll> edges(N);
vector <vector <ll>> g(N);
vector <ll> p(N, 0);
vector <ll> depth(N, 0);
vector <ll> color(N, 1);
vector <vector <ll>> query;

void DFS1(ll v, ll from = 0, ll d = 0) {
    p[v] = from;
    depth[v] = d;
    for (ll u : g[v]) {
        if (u == from) {
            continue;
        }
        DFS1(u, v, d + 1);
    }
}

bool cmp(const vector <ll> &a, const vector <ll> &b) {
    return a.back() > b.back();
}

void paint(ll a, ll b, ll c) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    while (depth[a] > depth[b]) {
        color[a] = max(color[a], c);
        a = p[a];
    }
    while (a != b) {
        color[a] = max(color[a], c);
        color[b] = max(color[b], c);
        a = p[a];
        b = p[b];
    }
}

void check(ll a, ll b, ll c) {
    ll res = INT_MAX;
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    while (depth[a] > depth[b]) {
        res = min(res, color[a]);
        a = p[a];
    }
    while (a != b) {
        res = min(res, color[a]);
        res = min(res, color[b]);
        a = p[a];
        b = p[b];
    }
    if (res != c) {
        cout << -1 << endl;
        exit(0);
    }
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
        edges[i] = {v, u};
    }
    DFS1(0);
    cin >> m;
    for (ll i = 0; i < m; ++i) {
        ll v, u, c;
        cin >> v >> u >> c;
        --v, --u;
        query.push_back({v, u, c});
    }
    sort(query.begin(), query.end(), cmp);
    for (ll i = 0; i < m; ++i) {
        paint(query[i][0], query[i][1], query[i][2]);
    }
    for (ll i = 0; i < m; ++i) {
        check(query[i][0], query[i][1], query[i][2]);
    }
    for (ll i = 0; i < n - 1; ++i) {
        cout << (depth[edges[i].first] > depth[edges[i].second] ? color[edges[i].first] : color[edges[i].second]) << ' ';
    }
    return 0;
}

/**


**/
