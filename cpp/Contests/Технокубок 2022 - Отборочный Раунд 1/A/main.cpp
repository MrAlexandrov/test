#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector <ll> a(n);
    ll ind = -1, sum = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        if (a[i] & 1) {
            ind = i;
        }
    }
    for (ll i = 2; i < sqrt(sum) + 1; ++i) {
        if (sum % i == 0) {
            cout << n << '\n';
            for (ll j = 0; j < n; ++j) {
                cout << j + 1 << ' ';
            }
            cout << '\n';
            return;
        }
    }
    cout << n - 1 << '\n';
    for (ll j = 0; j < n; ++j) {
        if (j == ind) {
            continue;
        }
        cout << j + 1 << ' ';
    }
    cout << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

/**


**/
