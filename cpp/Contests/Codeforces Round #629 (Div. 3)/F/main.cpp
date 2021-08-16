#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n, k;
    cin >> n >> k;
    map <ll, ll> m;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        m[x]++;
    }
    vector <pll> a(m.begin(), m.end());
    n = a.size();
    for (ll i = 0; i < n; ++i) {
        if (a[i].second >= k) {
            cout << "0\n";
            return 0;
        }
    }
    ll ansl = 0, ans = LLONG_MAX, ansr = 0;
    vector <pll> pref(n), suff(n);
    pref[0] = {0, a[0].second};
    for (ll i = 1; i < n; ++i) {
        pref[i].first = pref[i - 1].first + (a[i].first - a[i - 1].first) * pref[i - 1].second;
        pref[i].second = pref[i - 1].second + a[i].second;
    }

    for (ll i = 0; i < n; ++i) {
        if (pref[i].second >= k) {
            ansl = pref[i].first - (a[i].first - a[i - 1].first) * (pref[i].second - k);
            break;
        }
    }

    suff[n - 1] = {0, a[n - 1].second};
    for (ll i = n - 2; i >= 0; --i) {
        suff[i].first = suff[i + 1].first + (a[i + 1].first - a[i].first) * suff[i + 1].second;
        suff[i].second = suff[i + 1].second + a[i].second;
    }

    for (ll i = n - 1; i >= 0; --i) {
        if (suff[i].second >= k) {
            ansr = suff[i].first - (a[i + 1].first - a[i].first) * (suff[i].second - k);
            break;
        }
    }

    for (ll i = 1; i < n - 1; ++i) {
        if (pref[i].second + suff[i].second - a[i].second >= k) {
            ll now = pref[i].first + suff[i].first;
            ll cnt = (pref[i].second + suff[i].second - a[i].second) - k;
            ll t = min(cnt, pref[i - 1].second);
            now -= t;
            cnt -= t;

            t = min(cnt, suff[i + 1].second);
            now -= t;
            cnt -= t;
            ans = min(ans, now);
        }
    }
    cout << min({ansl, ans, ansr}) << '\n';
    return 0;
}

/**


**/
