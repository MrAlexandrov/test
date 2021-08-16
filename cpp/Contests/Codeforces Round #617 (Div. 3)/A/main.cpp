#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve() {
    ll n;
    cin >> n;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    bool ok = false;
    for (ll i = 0; i < n - 1; ++i) {
        if (a[i] % 2 != a[i + 1] % 2) {
            ok = true;
        }
    }
    if ((sum & 1) || ok) {
        return "YES";
    } else {
        return "NO";
    }
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
