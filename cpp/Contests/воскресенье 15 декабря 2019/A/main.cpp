#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n, m;
vector <pll> zero, one;

bool bad (pll a, pll b) {
    return (b.first <= a.first && a.second <= b.second);
}

bool bad2 (pll x, const vector <ll> &a) {
    return (a[x.first - 1] == a[x.second - 1]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll t, l, r;
        cin >> t >> l >> r;
        if (t) one.push_back({l, r});
        else zero.push_back({l, r});
    }
    for (pll i : zero) {
        for (pll j : one) {
            if (bad(i, j)) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    ll start = 1e6;
    vector <ll> ans(n);
    iota(ans.rbegin(), ans.rend(), start);
    sort(one.begin(), one.end());
    for (pll x : one) {
        ll l = x.first - 1, r = x.second - 1;
        for (ll i = l; i <= r; ++i) {
            ans[i] = ans[l];
        }
    }
    for (pll x : zero) {
        if (bad2(x, ans)) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for (ll i : ans)
        cout << i << ' ';
    return 0;
}

/**
5 4
1 2 3
0 4 5
1 1 2
1 3 4

5 3
0 1 5
1 1 3
1 4 5

3 3
1 1 2
1 2 3
0 1 3

**/
