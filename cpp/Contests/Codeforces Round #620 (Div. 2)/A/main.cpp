#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve() {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll d = y - x;
    ll sum = a + b;
    if (d % sum == 0) {
        return d / sum;
    } else {
        return -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}

/**


**/
