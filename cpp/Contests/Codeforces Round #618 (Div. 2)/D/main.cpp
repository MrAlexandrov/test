#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ll n;
    cin >> n;
    vector <pll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    if (n & 1) {
        cout << "NO" << endl;
        return 0;
    }
    for (ll i = 0; i < n; ++i) {
        if (a[i].first - a[(i + 1) % n].first != a[(i + (n / 2) + 1) % n].first - a[(i + (n / 2)) % n].first ||
            a[i].second - a[(i + 1) % n].second != a[(i + (n / 2) + 1) % n].second - a[(i + (n / 2)) % n].second) {
                cout << "NO" << endl;
                return 0;
            }
    }
    cout << "YES" << endl;
    return 0;
}

/**


**/
