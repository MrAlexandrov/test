#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector <pair <char, ll>> a;
    char x;
    cin >> x;
    if (x == '>') {
        a.emplace_back(x, 1);
    } else {
        a.emplace_back(x, 1);
    }
    for (ll i = 0; i < n - 2; ++i) {
        cin >> x;
        if (x == a.back().first) {
            ++a.back().second;
        } else {
            a.emplace_back(x, 1);
        }
    }
    ll m = a.size();
    vector <ll> pref(m);
    ll sum = 0;
    for (ll i = 0; i < m; ++i) {
        sum += a[i].second;
        pref[i] = sum;
    }
    vector <ll> mn(n, 0), mx(n, 0);
    ll ptr = n;
    ll i = 0;
    if (a[i].first == '>') {
        ++i;
    }
    for (; i < m; i += 2) {
        for (ll j = 0; j < a[i].second; ++j, --ptr) {
            mn[pref[i] - j] = ptr;
        }
    }
    for (ll i = 0; i < n; ++i) {
        if (mn[i] == 0) {
            mn[i] = ptr--;
        }
    }
    for (ll i : mn) {
        cout << i << ' ';
    }
    cout << endl;
    ptr = n;
    i = m - 1;
    if (a[i].first == '>') {
        --i;
    }
    for (; i >= 0; i -= 2) {
        for (ll j = 0; j < a[i].second; ++j, --ptr) {
            mx[pref[i] - j] = ptr;
        }
    }
    for (ll i = 0; i < n; ++i) {
        if (mx[i] == 0) {
            mx[i] = ptr--;
        }
    }
    for (ll i : mx) {
        cout << i << ' ';
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/**


**/
