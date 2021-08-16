#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n, s;
    cin >> n >> s;
    vector <pll> a(n);
    for (ll i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;
    ll mx = 0, ind = 0;
    for (ll i = 0; i < (1LL << n); ++i) {
        vector <ll> ans(n, 0LL);
        ll sum = 0;
        for (ll j = 0; j < n; ++j) {
            if (i & (1LL << j)) {
                ans[j] = a[j].first;
                sum += ans[j];
            }
        }
        if (sum > s) {
            continue;
        } else {
            for (ll j = 0; j < n; ++j) {
                if (i & (1LL << j)) {
                    ll t = min(s - sum, a[j].second - ans[j]);
                    ans[j] += t;
                    sum += t;
                }
            }
            if (sum > mx) {
                mx = sum;
                ind = i;
            }
        }
    }
    for (ll i = ind; i <= ind; ++i) {
        vector <ll> ans(n, 0LL);
        ll sum = 0;
        for (ll j = 0; j < n; ++j) {
            if (i & (1LL << j)) {
                ans[j] = a[j].first;
                sum += ans[j];
            }
        }
        if (sum > s) {
            continue;
        } else {
            for (ll j = 0; j < n; ++j) {
                if (i & (1LL << j)) {
                    ll t = min({s - sum, a[j].second - ans[j]});
                    ans[j] += t;
                    sum += t;
                }
            }
        }
        cout << sum << endl;
        for (ll i : ans)
            cout << i << ' ';
    }
    return 0;
}

/**
3 20
1 2
10 17
11 16

**/
