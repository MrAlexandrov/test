#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n, m;
    cin >> n;
    ll even_p = 0, odd_p = 0;
    ll even_q = 0, odd_q = 0;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        if (x & 1) ++odd_p;
        else ++even_p;
    }
    cin >> m;
    for (ll i = 0; i < m; ++i) {
        ll x;
        cin >> x;
        if (x & 1) ++odd_q;
        else ++even_q;
    }
    cout << odd_p * odd_q + even_p * even_q << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/**


**/

