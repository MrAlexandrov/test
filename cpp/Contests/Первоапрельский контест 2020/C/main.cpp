#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

mt19937_64 rnd(time(0));

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n;
    cin >> n;
    vector <ll> a(64);
    ll two = pow(2, 63);
    for (ll i = 0; i < 64; ++i, two >>= 1) {
        if (n >= two) {
            n -= two;
            a[i] = 1;
        }
    }
    for (ll i = 0; i < 64; ++i) {
        swap(a[i], a[rnd() % 64]);
    }
    ll ans = 0;
    for (ll i = 0; i < 64; ++i) {
        ans += pow(2, i);
    }
    cout << ans;
    return 0;
}

/**


**/
