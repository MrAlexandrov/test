#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

bool debug = false;

ll q;

void solve () {
    ll n;
    cin >> n;
    vector <ll> p (n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i];
        p[i] /= 100;
    }
    ll x, a;
    cin >> x >> a;
    ll y, b;
    cin >> y >> b;
    ll k;
    ll g = (a * b) / __gcd (a, b);
    ll sum = x + y;
    cin >> k;
    sort (p.rbegin(), p.rend());
    vector <ll> sm (n + 1);
    sm[1] = p[0];
    for (ll i = 1; i <= n; ++i)
        sm[i] = sm[i - 1] + p[i - 1];
    if (debug) cout << "sm ";
    if (debug) for (ll i = 0; i < n + 1; ++i)
        cout << sm[i] << ' ';
    if (debug) cout << endl;
    ll l = 0, r = n;
    while (r - l > 1) {
        ll m = (l + r) >> 1;
        ll cntxy = m / g;
        ll cntx = (m / a) - cntxy;
        ll cnty = (m / b) - cntxy;
        if (debug) cout << "m " << m << endl;
        if (debug) cout << "cnt " << cntxy << ' ' << cntx << ' ' << cnty << endl;
        ll ans = 0;
        ll i = 0;
        ans += sm[cntxy] * sum;
        if (debug) cout << "ans " << ans << endl;
        i = cntxy;
        /*
        if (cntx * a > cnty * b) {
            ans += (sm[i + cntx] - sm[i]) * a / 100;
            i += cntx;
            ans += (sm[i + cnty] - sm[i]) * b / 100;
        }
        else {
            ans += (sm[i + cnty] - sm[i]) * b / 100;
            i += cnty;
            ans += (sm[i + cntx] - sm[i]) * a / 100;
        }
        */
        if (debug) cout << endl << (sm[i + cntx] - sm[i]) * x + (sm[i + cnty + cntx] - sm[i + cntx]) * y << endl << (sm[i + cnty] - sm[i]) * y + (sm[i + cntx + cnty] - sm[i + cnty]) * x << endl;
        ans += max ((sm[i + cntx] - sm[i]) * x + (sm[i + cnty + cntx] - sm[i + cntx]) * y,
                    (sm[i + cnty] - sm[i]) * y + (sm[i + cntx + cnty] - sm[i + cnty]) * x);
        if (debug) cout << "ans " << ans << endl;
        if (ans >= k)
            r = m;
        else
            l = m;
    }

    ll m = r;
    ll cntxy = m / g;
    ll cntx = (m / a) - cntxy;
    ll cnty = (m / b) - cntxy;
    if (debug) cout << "m " << m << endl;
    if (debug) cout << "cnt " << cntxy << ' ' << cntx << ' ' << cnty << endl;
    ll ans = 0;
    ll i = 0;
    ans += sm[cntxy] * sum;
    if (debug) cout << "ans " << ans << endl;
    i = cntxy;
    /*
    if (cntx * a > cnty * b) {
        ans += (sm[i + cntx] - sm[i]) * a / 100;
        i += cntx;
        ans += (sm[i + cnty] - sm[i]) * b / 100;
    }
    else {
        ans += (sm[i + cnty] - sm[i]) * b / 100;
        i += cnty;
        ans += (sm[i + cntx] - sm[i]) * a / 100;
    }
    */
    if (debug) cout << endl << (sm[i + cntx] - sm[i]) * x + (sm[i + cnty + cntx] - sm[i + cntx]) * y << endl << (sm[i + cnty] - sm[i]) * y + (sm[i + cntx + cnty] - sm[i + cnty]) * x << endl;
    ans += max ((sm[i + cntx] - sm[i]) * x + (sm[i + cnty + cntx] - sm[i + cntx]) * y,
                (sm[i + cnty] - sm[i]) * y + (sm[i + cntx + cnty] - sm[i + cnty]) * x);
    if (debug) cout << "ans " << ans << endl;
    if (ans >= k)
        cout << r << endl;
    else
        cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> q;
    while (q--)
        solve ();
    return 0;
}

/**
4
1
100
50 1
49 1
100
8
100 200 100 200 100 200 100 100
10 2
15 3
107
3
1000000000 1000000000 1000000000
50 1
50 1
3000000000
5
200 100 100 100 100
69 5
31 2
90

1
8
100 200 100 200 100 200 100 100
10 2
15 3
107

**/
