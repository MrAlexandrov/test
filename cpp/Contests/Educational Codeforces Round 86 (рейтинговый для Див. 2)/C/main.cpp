#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll a, b, q;
    cin >> a >> b >> q;
    ll g = __gcd(a, b);
    ll x = a * b / g;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        ll all = r - l + 1;
        ll cntr = r / x, cntl = (l - 1) / x;
        ll cnt = cntr - cntl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

/**
1
7 10 2
7 8
100 200

**/
