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
        vector <ll> a(n), b(n);
        for (ll i = 0; i < n; ++i)
            cin >> a[i];
        for (ll i = 0; i < n; ++i)
            cin >> b[i];
        for (ll i = 0; i < n; ++i)
            a[i] = b[i] - a[i];
        ll l = 0, r = n - 1;
        ll k = 0;
        bool ans = true;
        for (ll i = 0; i < n; ++i)
            if (a[i] != 0) {
                l = i;
                k = a[i];
                if (k < 0)
                    ans = false;
                break;
            }
        for (ll i = n - 1; i >= 0; --i)
            if (a[i] != 0) {
                r = i;
                break;
            }
        for (ll i = 0; i < l; ++i)
            if (a[i])
                ans = false;
        for (ll i = l; i <= r; ++i)
            if (a[i] != k)
                ans = false;
        for (ll i = r + 1; i < n; ++i)
            if (a[i])
                ans = false;
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}

/**


**/
