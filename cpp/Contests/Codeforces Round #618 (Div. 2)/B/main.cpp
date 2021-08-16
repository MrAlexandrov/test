#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve() {
    ll n;
    cin >> n;
    n <<= 1;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    return a[n / 2] - a[(n / 2) - 1];
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
