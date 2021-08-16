#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n;
    cin >> n;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i)
        cin >> a[i];
    for (ll i = 0; i < n - 1; ++i) {
        if (abs(a[i] - a[i + 1]) > 1) {
            cout << "YES" << endl;
            cout << i + 1 << ' ' << i + 2 << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
