#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n;
    cin >> n;
    ll l = 0, r = (ll)1e9;
    string left;
    ll k = 10;
    cout << 0 << ' ' << k << endl;
    cin >> left;
    --n;
    string t;
    while (n--) {
        ll m = l + r >> 1;
        cout << m << ' ' << k << endl;
        cin >> t;
        if (t == left) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << ' ' << k + 1 << ' ' << r << ' ' << k - 1 << endl;
    return 0;
}

/**


**/
