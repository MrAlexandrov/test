#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        sum += a[i];
    }
    ll m;
    cin >> m;
    for (ll i = 0; i < m; ++i) {
        ll q;
        cin >> q;
        cout << sum - a[q - 1] << endl;
    }
    return 0;
}

/**


**/
