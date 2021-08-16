#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

string solve() {
    ll a, b, c, n;
    cin >> a >> b >> c >> n;
    ll mx = max({a, b, c});
    ll need = 3 * mx - a - b - c;
    if (n < need || (n - need) % 3) {
        return "NO";
    } else {
        return "YES";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}

/**


**/
