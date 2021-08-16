#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n;
    cin >> n;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    bool one = true;
    for (ll i = 0; i < n; ++i) {
        if (a[0] != a[i]) {
            one = false;
        }
    }
    if (one) {
        cout << "1\n";
        for (ll i = 0; i < n; ++i) {
            cout << "1 ";
        }
        cout << '\n';
        return;
    }
    if (n % 2 == 0) {
        cout << "2\n";
        for (ll i = 0; i < n; ++i) {
            cout << 1 + (i % 2) << ' ';
        }
        cout << '\n';
        return;
    }
    for (ll i = 0; i < n; ++i) {
        ll j = (i + 1) % n;
        if (a[i] == a[j]) {
            a[i] = a[j] = 1;
            for (ll k = 0; k < n - 1; ++k) {
                a[(j + k) % n] = 1 + (k % 2);
            }
            cout << "2\n";
            for (ll k : a) {
                cout << k << ' ';
            }
            cout << '\n';
            return;
        }
    }
    cout << "3\n3 ";
    for (ll i = 1; i < n; ++i) {
        cout << 1 + (i % 2) << ' ';
    }
    cout << '\n';
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
