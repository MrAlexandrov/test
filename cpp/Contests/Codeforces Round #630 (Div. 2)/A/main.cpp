#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

string solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2 && (a || b)) {
        return "NO";
    }
    if (y1 == y2 && (c || d)) {
        return "NO";
    }
    ll xx = min(a, b), yy = min(c, d);
    a -= xx, b -= xx;
    c -= yy, d -= yy;
    x += (-a + b), y += (-c + d);
    return (x1 <= x && x <= x2 && y1 <= y && y <= y2 ? "YES" : "NO");
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}

/**


**/
