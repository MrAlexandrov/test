#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

bool check (vector <ll> &x) {
    ll n = x.size();
    ll one;
    for (ll i = 0; i < n; ++i) {
        if (x[i] == 1) {
            one = i;
            break;
        }
    }
    for (ll i = one; i < one + n - 1; ++i) {
        ll t = i % n;
        if (x[(t + 1) % n] - x[t] != 1)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll q;
    cin >> q;
    while (q--) {
        ll n;
        cin >> n;
        vector <ll> a(n), b(n);
        ll one;
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
            b[(n - 1) - i] = a[i];
        }
        cout << (check(a) || check(b) ? "YES" : "NO") << endl;
    }
    return 0;
}

/**


**/
