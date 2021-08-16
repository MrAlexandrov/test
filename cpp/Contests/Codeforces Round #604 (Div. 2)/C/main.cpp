#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve () {
    ll n;
    cin >> n;
    vector <pll> a;
    ll x;
    cin >> x;
    a.push_back({x, 1});
    for (ll i = 1; i < n; ++i) {
        cin >> x;
        if (x == a.back().first) ++a.back().second;
        else a.push_back({x, 1});
    }
    if (a.size() < 4) {
        cout << "0 0 0" << endl;
        return;
    }
    ll half = n / 2;
    ll sum = 0;
    ll last_ind = -1;
    ll m = a.size();
    for (ll i = 0; i < m; ++i) {
        if (sum + a[i].second > half) {
            last_ind = i - 1;
            break;
        }
        sum += a[i].second;
    }
    if (last_ind < 2) {
        cout << "0 0 0" << endl;
        return;
    }
    ll g = a[0].second, s = 0, b = 0;
    sum -= a[0].second;
    s = sum;
    for (ll i = last_ind; i > 1; --i) {
        b += a[i].second;
        s -= a[i].second;
        if (s > 0 && b > 0 && g < s && g < b) {
            cout << g << ' ' << s << ' ' << b << endl;
            return;
        }
    }
    cout << "0 0 0" << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/**


**/
