#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        if (n == 1) {
            cout << -1 << '\n';
        } else {
            cout << 2;
            for (ll i = 0; i < n - 1; ++i) {
                cout << 3;
            }
            cout << '\n';
        }
    }
    return 0;
}

/**


**/
