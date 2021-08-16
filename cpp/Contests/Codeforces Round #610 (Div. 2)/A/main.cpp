#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve () {
    ll a, b, c, r;
    cin >> a >> b >> c >> r;
    if (a > b) swap(a, b);
    ll x, y;
    if (c < a) {
        x = max(a, c + r);
        cout << max(0LL, b - x) << endl;
    } else if (a <= c && c <= b) {
        x = max(a, c - r);
        y = min(b, c + r);
        cout << max(0LL, (b - a) - (y - x)) << endl;
    } else if (b < c) {
        y = min(b, c - r);
        cout << max(0LL, y - a) << endl;
    }
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
