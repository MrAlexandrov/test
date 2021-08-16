#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll solve() {
    ll n, x;
    cin >> n >> x;
    vector <ll> a(n);
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        char s;
        cin >> s;
        if (s == '0') {
            ++sum;
        } else {
            --sum;
        }
        a[i] = sum;
    }
    if (a.back() < 0) {
        x *= -1;
        for (ll i = 0; i < n; ++i) {
            a[i] *= -1;
        }
    }
    ll res = 0;
    if (x == 0) {
        ++res;
    }
    ll ex = a.back();
    if (ex == 0) {
        for (ll i = 0; i < n; ++i) {
            if (a[i] == x) {
                return -1;
            }
        }
        return res;
    }
    for (ll i = 0; i < n; ++i) {
        if ((x - a[i]) % ex == 0 && x >= a[i]) {
            ++res;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}

/**


**/
