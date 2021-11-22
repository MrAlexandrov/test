#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve() {
    ll n;
    cin >> n;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = a[0];
    ll d = 0;
    for (ll i = 0; i < n - 1; ++i) {
        d += -(a[i] + d);
        ans = max(ans, a[i + 1] + d);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll T;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}

/**
3 2 -4 -2 0
-4 -2 0 2 3

- -4  = 4
- (-2 + 4) = -2
-


2 10 1 7
1 2 7 10
-1  -1
-1  -2
-7  -7

**/
