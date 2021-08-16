#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve () {
    ll n, m;
    cin >> n;
    vector <ll> a (n);
    for (ll i = 0; i < n; ++i)
        cin >> a[i];
    a.push_back(INT_MAX);
    cin >> m;
    vector <pll> b (m);
    vector <ll> s (n + 1, 0);
    ll max_s = 0;
    for (ll i = 0; i < m; ++i) {
        cin >> b[i].first >> b[i].second;
        s[b[i].second] = max (s[b[i].second], b[i].first);
        max_s = max (max_s, b[i].second);
    }
    for (ll i = n - 1; i >= 0; --i)
        s[i] = max (s[i], s[i + 1]);/*
    for (ll i = 1; i <= m; ++i)
        cout << s[i] << ' ';
    cout << '\n';//*/
    ll ans = 0;
    ll pos = 0;
    while (pos < n) {
        ll i;
        ll mx = 0;
        for (i = pos; s[i - pos + 1] >= a[i] && s[i - pos + 1] >= mx && i - pos + 1 <= max_s && i < n; ++i)
            mx = max (a[i], mx);
        ++ans;
        //cout << pos << ' ' << i << '\n';
        if (pos == i) {
            cout << "-1\n";
            return;
        }
        pos = i;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
        solve ();
    return 0;
}

/**
2
6
2 3 11 14 1 8
2
3 2
100 1
5
3 5 100 2 3
2
30 5
90 1

1
6
2 3 11 14 1 8
2
3 2
100 1

1
5
3 5 100 2 3
2
30 5
90 1

**/
