#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll cnt;

ll gcd (ll a, ll b) {
    if (a == 1 || b == 1) {
        if (a == 1 && b == 1) return 0;
        if (a > b) swap(a, b);
        cnt += b - a;
        return 0;
    }
    if (a > b) swap(a, b);
    cnt += b / a;
    b %= a;
    return gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = n;
    for (ll i = 1; i < n; ++i) {
        if (__gcd(i, n) == 1) {
            cnt = 0;
            gcd(i, n);
            ans = min(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}

/**


**/
