#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve() {
    ll n;
    cin >> n;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll res = 0;
    for (ll i = 0; i < n; ++i) {
        if (a[i] == 0) {
            ++a[i];
            ++res;
        }
    }
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    if (sum == 0) {
        for (ll i = 0; i < n; ++i) {
            if (a[i] > 0) {
                ++a[i];
                ++res;
                break;
            }
        }
    }
    return res;
}

int main()
{
    ll t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}

/**


**/
