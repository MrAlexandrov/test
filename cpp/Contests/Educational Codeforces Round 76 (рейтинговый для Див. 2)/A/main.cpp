#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve () {
    ll n, x, a, b;
    cin >> n >> x >> a >> b;
    ll ans = abs (a - b);
    if (a > b)
        swap (a, b);
    if (x < a - 1) {
        ans += x;
        x -= x;
    }
    else {
        ans += a - 1;
        x -= a - 1;
    }
    if (x < n - b) {
        ans += x;
        x -= x;
    }
    else {
        ans += n - b;
        x -= n - b;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
        solve ();
    return 0;
}

/**


**/
