#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll solve() {
    string s, t;
    cin >> s >> t;
    ll n = s.size();
    vector <ll> cnt(26, 0);
    for (ll i = 0; i < n; ++i) {
        ++cnt[s[i] - 'a'];
    }
    for (ll i = 0; i < t.size(); ++i) {
        if (cnt[t[i] - 'a'] == 0) {
            return -1;
        }
    }
    vector <vector <ll>> a(n, vector <ll>(26, -1));
    a[n - 1][s.back() - 'a'] = n - 1;
    for (ll i = n - 2; i >= 0; --i) {
        a[i][s[i] - 'a'] = i;
        for (ll j = 0; j < 26; ++j) {
            if (a[i][j] == -1) {
                a[i][j] = a[i + 1][j];
            }
        }
    }
    ll res = 0;
    ll i = 0;
    while (i < t.size()) {
        ll ptr = 0;
        while (ptr < n && a[ptr][t[i] - 'a'] != -1 && i < t.size()) {
            ptr = a[ptr][t[i] - 'a'] + 1;
            ++i;
        }
        ++res;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}

/**


**/
