#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve () {
    ll n;
    cin >> n;
    vector <ll> a(4 * n);
    for (ll i = 0; i < 4 * n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (ll i = 0; i < 4 * n; i += 2) {
        if (a[i] != a[i + 1]) {
            cout << "NO" << endl;
            return;
        }
    }
    ll l = 0, r = 4 * n - 1;
    ll sq = a[l] * a[r];
    while (r > l) {
        l += 2;
        r -= 2;
        if (a[l] * a[r] != sq) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll q;
    cin >> q;
    while (q--)
        solve();
    return 0;
}

/**


**/
