#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll solve() {
    ll a, b;
    cin >> a >> b;
    if (a == b) {
        return 0;
    }
    if ((a < b && a % 2 != b % 2) || (a > b && a % 2 == b % 2)) {
        return 1;
    }
    return 2;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}

/**


**/
