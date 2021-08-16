#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll INF = INT_MAX;

ll n, k;
vector <pll> a;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> k;
    set <vector <ll>> s;
    vector <pll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        s.insert({a[i].first, 0, a[i].first - a[i].second, i});
        s.insert({a[i].second, 1, a[i].first - a[i].second, i});
    }
    vector <bool> ok(n, true);
    ll cnt = 0;
    set <pll, greater <pll>> r;
    vector <ll> ans;
    for (auto i : s) {
        ll val = i[0], open = i[1], length = i[2], ind = i[3];
        if (!ok[ind]) {
            continue;
        }
        if (open == 0) {
            ++cnt;
            r.insert({a[ind].second, ind});
            if (cnt > k) {
                pll t = *r.begin();
                r.erase(r.begin());
                --cnt;
                ok[t.second] = false;
                ans.push_back(t.second);
            }
        } else {
            --cnt;
            r.erase({a[ind].second, ind});
        }
    }
    cout << ans.size() << '\n';
    for (ll i : ans) {
        cout << i + 1 << ' ';
    }
    return 0;
}

/**


**/
