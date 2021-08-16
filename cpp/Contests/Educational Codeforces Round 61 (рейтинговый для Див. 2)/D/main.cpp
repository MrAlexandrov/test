#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n, k;
vector <ll> a, b;

ll num(pll x) {
    ll res = x.first / x.second;
    return res;
}

struct cmp {
    bool operator() (const pll &a, const pll &b) {
        return num(a) < num(b);
    }
};

bool check(ll x, set <pll, cmp> y) {
    ///
}

int main()
{
    cin >> n >> k;
    a.resize(n);
    b.resize(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
    }
    multiset <pll, cmp> bad;
    for (ll i = 0; i < n; ++i) {
        bad.emplace(a[i], b[i]);
    }
    ll j = 0;
    for (auto i = bad.begin(); i != bad.end() && j < n; ++i, ++j) {
        if (num(*i) < j) {
            cout << -1 << endl;
            return 0;
        }
    }
    ll l = -1, r = LLONG_MAX;
    while (r - l > 1) {
        ll m = (l + r) >> 1;
        if (check(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << endl;
    return 0;
}

/**


**/
