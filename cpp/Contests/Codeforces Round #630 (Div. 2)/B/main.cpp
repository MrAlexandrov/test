#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

vector <ll> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

void solve() {
    ll n;
    cin >> n;
    vector <ll> a(n);
    ll ans = 0;
    vector <ll> b(11, 0);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        for (ll j = 0; j < 11; ++j) {
            if (a[i] % p[j] == 0) {
                if (b[j] == 0) {
                    ++ans;
                    b[j] = ans;
                    a[i] = b[j];
                } else {
                    a[i] = b[j];
                }
                break;
            }
        }
    }
    cout << ans << '\n';
    for (ll i : a) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/**


**/
