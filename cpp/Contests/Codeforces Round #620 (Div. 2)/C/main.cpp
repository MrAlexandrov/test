#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve() {
    ll n, m;
    cin >> n >> m;
    vector <vector <ll>> a(n, vector <ll>(3));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }
    ll t = 0;
    ll l = m, r = m;
    for (ll i = 0; i < n; ++i) {
        ll d = a[i][0] - t;
        t = a[i][0];
        l -= d, r += d;
        if (a[i][2] < l || r < a[i][1]) {
            return "NO";
        }
        l = max(l, a[i][1]);
        r = min(r, a[i][2]);
    }
    return "YES";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll q;
    cin >> q;
    while (q--) {
        cout << solve() << endl;
    }
    return 0;
}

/**


**/
