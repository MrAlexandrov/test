#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

vector <ll> mas = {0, 45, 4905LL, 494550LL, 49495500LL, 4949955000LL, 494999550000LL, 49499995500000LL, 4949999955000000LL, 494999999550000000LL};
vector <ll> sum;
vector <ll> add = {};

ll q;

ll get (ll a, ll x) {
    --x;
    ll cnt = log10 (a);
    a /= pow (10, cnt - x);
    return a % 10;
}

ll solve1 (ll x) {
    /*
    if (x < 10)
        return x;
    */
    ll res = 0;
    ll i = 0;
    for (; res < x;) {
        ++i;
        res += (ll) log10(i) + 1;
        //cout << res << ' ';
    }
    //cout << '\n';
    res -= (ll) log10(i) + 1;
    //cout << res << ' ' << i << ' ' << x << ' ' << res - x << '\n';
    //cout << i << ' ' << res - x << '\n';
    return get (i, x - res);
}

ll solve (ll x) {
    ll ptr = 0;
    for (ll i = 9; i >= 0; --i) {
        if (sum[i] <= x) {
            x -= sum[i];
            ptr = i;
            break;
        }
    }
    //cout << x << ' ' << ptr << '\n';
    ll sub = mas[ptr] + (ptr + 1);          ///bin search
    while (sub < x) {
        x -= sub;
        sub += ptr + 1;
    }
    //cout << x << ' ' << sub << '\n';
    return solve1 (x);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll s = 0;
    for (ll i = 0; i < 10; ++i) {
        s += mas[i];
        sum.push_back (s);
    }
    cin >> q;
    while (q--) {
        ll x;
        cin >> x;
        cout << solve (x) << endl;
    }
    return 0;
}
