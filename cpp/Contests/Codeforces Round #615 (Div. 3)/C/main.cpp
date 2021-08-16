#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n;
    cin >> n;
    vector <ll> ans(3, 1);
    vector <ll> a;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            n /= i;
            a.push_back(i);
        }
    }
    if (n > 1) {
        a.push_back(n);
    }
    ll m = a.size();
    ans[0] = a[0];
    ll ptr;
    for (ptr = 1; ptr < m; ++ptr) {
        ans[1] *= a[ptr];
        if (ans[0] != ans[1]) {
            break;
        }
    }
    ++ptr;
    for (; ptr < m; ++ptr) {
        ans[2] *= a[ptr];
    }
    bool ok = true;
    for (ll i = 0; i < 3; ++i) {
        if (ans[i] == 1) {
            ok = false;
        }
    }
    for (ll i = 0; i < 3; ++i) {
        for (ll j = i + 1; j < 3; ++j) {
            if (ans[i] == ans[j]) {
                ok = false;
            }
        }
    }
    if (!ok) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (ll i = 0; i < 3; ++i) {
        cout << ans[i] << ' ';
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
