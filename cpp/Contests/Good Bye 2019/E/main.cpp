#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll dist(pll a, pll b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

const ll N = 1e3 + 8;

vector <ll> color(N, 0);
vector <ll> sz(N, 1);

ll find(ll x) {
     if (x == color[x]) return x;
     return color[x] = find(color[x]);
}

void unite(ll a, ll b) {
     a = find(a);
     b = find(b);
     if (sz[a] < sz[b]) swap(a, b);
     sz[a] += sz[b];
     color[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n;
    cin >> n;
    vector <pll> a(n);
    for (ll i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;
    vector <pair <ll, pll>> b;
    for (ll i = 0; i < n; ++i) {
        for (ll j = i + 1; j < n; ++j) {
            cout << i << ' ' << j << ' ' << dist(a[i], a[j]) << endl;
            b.push_back({dist(a[i], a[j]), {i, j}});
        }
    }
    sort(b.begin(), b.end());
    cout << endl;
    cout << endl;
    for (auto i : b) {
        cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
    }
    cout << endl;
    iota(color.begin(), color.end(), 0);
    fill(sz.begin(), sz.end(), 1);
    ll m = b.size();
    ll l = 0, r = 0;
    while (r < m) {
        l = r;
        while (b[l].first == b[r].first && r < m)
            ++r;
        for (ll i = l; i < r; ++i) {
            for (ll j = i + 1; j < r; ++j) {
                map <ll, ll> x;
                x[b[i].second.first]++;
                x[b[i].second.second]++;
                x[b[j].second.first]++;
                x[b[j].second.second]++;
                if (x.size() == 4) {
                    unite(b[i].second.first, b[i].second.second);
                    unite(b[j].second.first, b[j].second.second);
                } else {
                    bool was = false;
                    for (auto kek : x) {
                        for (auto kek2 : x) {
                            if (kek.second != 2 && kek2.second != 2 && kek != kek2 && !was) {
                                unite(kek.first, kek2.first);
                                was = true;
                            }
                        }
                    }
                }
            }
        }/*
        bool diff = false;
        for (ll i = 0; i < n - 1; ++i) {
            if (find(i) != find(i + 1)) {
                diff = true;
            }
        }
        if (diff) {
            for (ll i = 0; i < n - 1; ++i) {
                if (find(i) != find(i + 1)) {
                    ll ex = find(i);
                    vector <ll> ans;
                    for (ll i = 0; i < n; ++i) {
                        if (find(i) == ex) {
                            ans.push_back(i + 1);
                        }
                    }
                    cout << ans.size() << endl;
                    for (ll j : ans)
                        cout << j << ' ';
                    cout << endl;
                    return 0;
                }
            }
        } else {
            iota(color.begin(), color.end(), 0);
            fill(sz.begin(), sz.end(), 1);
        }*/
    }
    for (ll i = 0; i < n; ++i)
        cout << find(i) << ' ';
    return 0;
}

/**
4
0 1
0 0
1 0
2 0

8
1 0
1 1
0 1
-1 1
-1 0
-1 -1
0 -1
1 -1

**/
