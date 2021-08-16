#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll k;
    cin >> k;
    vector <ll> a;
    ll x = k;
    while (x) {
        a.push_back(x % 2);
        x >>= 1;
    }
    ll ans[3][4]{};
    for (ll i = 0; i < a.size(); ++i) {
        if (a[i]) {
            ans[0][0] = ans[0][1] = ans[0][2] = ans[1][2] = ans[2][2] = ans[2][3] = k;
        }
    }
    ll two = pow(2, a.size());
    ans[0][0] += two;
    ans[1][0] += two;
    ans[2][0] += two;
    ans[2][1] += two;
    ans[2][2] += two;
    ll n = 3, m = 4;
    cout << n << ' ' << m << '\n';
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

/**


**/
