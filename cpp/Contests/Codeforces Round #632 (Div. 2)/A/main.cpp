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
        ll n, m;
        cin >> n >> m;
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < m; ++j) {
                if (i + j == 0) {
                    cout << 'W';
                } else {
                    cout << 'B';
                }
            }
            cout << '\n';
        }
    }
    return 0;
}

/**


**/
