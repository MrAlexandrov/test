#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll INF = (ll)1e12;

bool inter (ll x1, ll y1, ll x2, ll y2) {
    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }
    return (x2 < y1);
}

void solve () {
    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    ll s1, d1, s2, d2;
    cin >> s1 >> d1 >> s2 >> d2;
    vector <pll> ans;
    if (s1 <= 50 && s2 <= 50 && d1 <= 50 && d2 <= 50 && l1 <= 50 && l2 <= 50 && r1 <= 50 && r2 <= 50) {
        for (ll i = l1; i <= r1 - d1; ++i) {
            for (ll j = l2; j <= r2 - d2; ++j) {
                if (!inter(i, i + d1, j, j + d2)) {
                    ans.push_back({i, j});
                }
            }
        }
    }
    ll cnt1 = INF, cnt2 = INF;
    ll x1, y1, x2, y2;
    vector <ll> k1 = {l1, s1, r1 - d1};
    vector <ll> k2 = {l2, s2, r2 - d2};
    for (ll i : k1)
        for (ll j : k2)
            ans.push_back({i, j});
    for (ll i : k1) {
        for (ll j : k2) {
            if (!inter(i, i + d1, j, j + d2)) {
                if (i < j) {
                    y1 = min(j, r1), x1 = y1 - d1;
                    ans.push_back({x1, x2});
                    x2 = max(y1, l2), y2 = x2 + d2;
                    ans.push_back({x1, x2});
                } else {
                    x1 = max(j + d2, l1), y1 = x1 + d1;
                    ans.push_back({x1, x2});
                    y2 = min(x1, r2), x2 = y2 - d2;
                    ans.push_back({x1, x2});
                }/*
                if (i < j) {
                    x2 = max(i + d1, r2), y2 = x2 + d2;
                    ans.push_back({x1, x2});
                    y1 = min(x2, r1), x1 = y1 - d1;
                    ans.push_back({x1, x2});
                } else {
                    y2 = min(i, r2), x2 = y2 - d2;
                    ans.push_back({x1, x2});
                    x1 = max(y2, l1), y1 = x1 + d1;
                    ans.push_back({x1, x2});
                }*/
            }
        }
    }

    ll cnt = INF;
    pll pr = {-1, -1};
    for (pll i : ans) {
        ll t = abs(i.first - s1) + abs(i.second - s2);
        if (t < cnt && !inter(i.first, i.first + d1, i.second, i.second + d2)) {
            cnt = t;
            pr = i;
        }
    }
    ///cout << cnt << endl;
    cout << pr.first << ' ' << pr.second << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/**
3
14 22 12 18
15 5 16 2
12 22 14 20
14 5 15 4
12 14 16 18
12 2 16 2

**/
