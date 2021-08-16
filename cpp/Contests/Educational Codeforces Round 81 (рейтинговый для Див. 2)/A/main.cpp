#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n;
    cin >> n;
    if (n % 2 == 0) {
        for (ll i = 0; i < n; i += 2) {
            cout << 1;
        }
        cout << endl;
    } else {
        cout << 7;
        for (ll i = 3; i < n; i += 2) {
            cout << 1;
        }
        cout << endl;
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
        solve();
    }
    return 0;
}

/**


**/
