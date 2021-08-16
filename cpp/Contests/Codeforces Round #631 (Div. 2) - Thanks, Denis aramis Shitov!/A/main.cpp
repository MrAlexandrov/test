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
        ll n, x;
        cin >> n >> x;
        set <ll> a;
        for (ll i = 0; i < n; ++i) {
            ll k;
            cin >> k;
            a.insert(k);
        }
        for (ll i = 1; i < 300; ++i) {
            if (a.find(i) == a.end()) {
                if (x) {
                    --x;
                } else {
                    cout << i - 1 << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}

/**


**/
