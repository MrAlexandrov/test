#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum (ll x) {
    ll ans = 0;
    while (x > 0) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int main()
{
    ll n;
    cin >> n;
    for (ll i = n; i < LLONG_MAX; ++i)
        if (sum(i) % 4 == 0) {
            cout << i;
            return 0;
        }

    return 0;
}
