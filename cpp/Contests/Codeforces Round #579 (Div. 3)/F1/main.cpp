#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

bool cmp (const pll &a, const pll &b) {
    return a.first + a.second > b.first + b.second;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n, r;
    cin >> n >> r;
    vector <pll> a, b;
    for (ll i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        if (y >= 0)
            a.push_back({x, y});
        else
            b.push_back({max(x, abs(y)), y});
    }
    sort(a.begin(), a.end());
    for (ll i = 0; i < a.size(); ++i) {
        if (r >= a[i].first)
            r += a[i].second;
        else {
            cout << "NO" << endl;
            return 0;
        }
    }

    sort(b.begin(), b.end(), cmp);
    for (ll i = 0; i < b.size(); ++i) {
        if (r >= b[i].first)
            r += b[i].second;
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}

/**


**/
