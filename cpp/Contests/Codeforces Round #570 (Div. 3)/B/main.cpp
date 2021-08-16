#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll q;

ll solve () {
    ll n, k;
    cin >> n >> k;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i)
        cin >> a[i];
    ll mn = *min_element(a.begin(), a.end());
    ll mx = *max_element(a.begin(), a.end());
    if (mx - mn > 2 * k)
        return -1;
    else
        return mn + k;
}

int main()
{
    cin >> q;
    while (q--)
        cout << solve() << '\n';
    return 0;
}
