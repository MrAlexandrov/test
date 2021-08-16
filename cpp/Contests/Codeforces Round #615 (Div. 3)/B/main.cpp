#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n;
    cin >> n;
    vector <pll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    a.emplace_back(0, 0);
    sort(a.begin(), a.end());
    for (ll i = 0; i < n; ++i) {
        if (a[i].second > a[i + 1].second) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < a[i + 1].first - a[i].first; ++j) {
            cout << 'R';
        }
        for (ll j = 0; j < a[i + 1].second - a[i].second; ++j) {
            cout << 'U';
        }
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/**


**/
