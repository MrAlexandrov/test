#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve() {
    ll n, x;
    cin >> n >> x;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i : a) {
        if (i == x) {
            return 1;
        }
    }
    ll mx = *max_element(a.begin(), a.end());
    return max(2LL, (ll)ceil(double(x) / mx));
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
