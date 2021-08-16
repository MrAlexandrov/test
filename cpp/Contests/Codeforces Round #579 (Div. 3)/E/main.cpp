#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n;
    cin >> n;
    multiset <ll> a;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a.insert(x);
    }
    for (ll i = 1; i <= 150001; ++i) {
        for (ll j = max(1LL, i - 1); j <= i + 1; ++j) {
            auto t = a.find(j);
            if (t != a.end()) {
                a.erase(t);
                break;
            }
        }
    }
    cout << n - a.size() << endl;
    return 0;
}

/**


**/
