#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ll n;
    cin >> n;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <ll> b(40, 0);
    for (ll i = 0; i < n; ++i) {
        ll x = a[i];
        ll ptr = 0;
        while (x) {
            if (x & 1) {
                ++b[ptr];
            }
            x >>= 1;
            ++ptr;
        }
    }
    ll ans = -1;
    for (ll i = 39; i >= 0; --i) {
        if (b[i] == 1) {
            ans = i;
            break;
        }
    }
    if (ans == -1) {
        for (ll i : a) {
            cout << i << ' ';
        }
        cout << endl;
        return 0;
    }
    for (ll i = 0; i < n; ++i) {
        if (a[i] & (1LL << ans)) {
            for (ll j = i - 1; j >= 0; --j) {
                swap(a[j], a[j + 1]);
            }
            break;
        }
    }
    for (ll i : a) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}

/**


**/
