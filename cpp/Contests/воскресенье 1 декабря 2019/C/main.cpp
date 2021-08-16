#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n;
    cin >> n;
    map <ll, ll> m;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        ++m[x];
    }
    vector <vector <ll>> ans;
    set <pll, greater <pll>> a;
    for (auto i : m) a.insert({i.second, i.first});
    while (a.size() >= 3) {
        pll x = *a.begin();
        a.erase(a.begin());
        pll y = *a.begin();
        a.erase(a.begin());
        pll z = *a.begin();
        a.erase(a.begin());
        ans.push_back({x.second, y.second, z.second});
        sort(ans.back().rbegin(), ans.back().rend());
        --x.first, --y.first, --z.first;
        if (x.first) a.insert(x);
        if (y.first) a.insert(y);
        if (z.first) a.insert(z);
    }
    cout << ans.size() << endl;
    for (auto i : ans) {
        for (ll j : i)
            cout << j << ' ';
        cout << endl;
    }
    return 0;
}

/**


**/
