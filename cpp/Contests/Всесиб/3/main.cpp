#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n;
ll ans = 0;

void check(const vector <ll> &a, const vector <ll> &b) {
    ll res = 0;
    for (ll i = 0; i < n; ++i) {
        res += __gcd(a[i], b[i]);
    }
    ans = max(ans, res);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    cin >> n;
    vector <ll> a(n), b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    do {
        check(a, b);
    }
    while (next_permutation(b.begin(), b.end()));
    cout << ans;
    return 0;
}

/**


**/
