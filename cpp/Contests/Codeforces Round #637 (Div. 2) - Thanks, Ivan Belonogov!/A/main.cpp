#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

string solve() {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    ll l = n * (a - b), r = n * (a + b);
    if (r < c - d || c + d < l) {
        return "No";
    } else {
        return "Yes";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll T;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}

/**


**/
