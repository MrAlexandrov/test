#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    vector <string> a(n), b(m);
    for (ll i = 0; i < n; ++i)
        cin >> a[i];
    for (ll i = 0; i < m; ++i)
        cin >> b[i];
    ll t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        cout << a[(x - 1) % n] << b[(x - 1) % m] << endl;
    }
    return 0;
}

/**


**/
