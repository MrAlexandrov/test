#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    vector <ll> d(n, 0);
    for (ll i = 0; i < m; ++i) {
        ll v, u, w;
        cin >> v >> u >> w;
        --v, --u;
        d[v] -= w;
        d[u] += w;
    }
    vector <ll> less;
    vector <ll> more;
    for (ll i = 0; i < n; ++i) {
        if (d[i] < 0) less.push_back(i);
        if (d[i] > 0) more.push_back(i);
    }
    ll ptr1 = 0, ptr2 = 0;
    vector <pair <pll, ll>> ans;
    while (ptr1 < less.size() && ptr2 < more.size()) {
        ll t = min(abs(d[less[ptr1]]), abs(d[more[ptr2]]));
        d[less[ptr1]] += t;
        d[more[ptr2]] -= t;
        ans.push_back({{less[ptr1], more[ptr2]}, t});
        if (d[less[ptr1]] == 0) ++ptr1;
        if (d[more[ptr2]] == 0) ++ptr2;
    }
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i.first.first + 1 << ' ' << i.first.second + 1 << ' ' << i.second << endl;
    return 0;
}

/**


**/
