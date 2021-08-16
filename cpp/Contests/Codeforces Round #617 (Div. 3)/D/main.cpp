#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a, b, k;
vector <ll> h;
ll ans = 0;
vector <ll> solve;

void check(ll x) {
    ll was = x;
    ll t = x % (a + b);
    if (1<= t && t <= a) {
        ++ans;
        return;
    }
    x %= (a + b);
    if (x == 0) {
        x += a + b;
    }
    solve.push_back(ceil((double)x / a) - 1);
}

int main()
{
    cin >> n >> a >> b >> k;
    h.resize(n);
    for (ll i = 0; i < n; ++i) {
        cin >> h[i];
    }
    for (ll i = 0; i < n; ++i) {
        check(h[i]);
    }
    sort(solve.begin(), solve.end());
    for (ll i = 0; i < solve.size(); ++i) {
        if (solve[i] <= k) {
            k -= solve[i];
            ++ans;
        } else {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}

/**


**/
