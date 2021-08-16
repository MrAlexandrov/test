#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n;
map <ll, map <ll, map <ll, ll>>> m;
vector <pll> ans;
vector <ll> ost;

void solve1 (map <ll, ll> &m) {
    vector <ll> solve;
    for (auto i : m)
        solve.push_back(i.second);
    ll x = solve.size() / 2;
    for (ll i = 0; i < x; ++i)
        ans.push_back({solve[2 * i], solve[2 * i + 1]});
    if (solve.size() & 1)
        ost.push_back(solve.back());
}

void solve2 (map <ll, map <ll, ll>> &m) {
    for (auto i : m) {
        solve1(i.second);
        while (ost.size() > 2) {
            ll a = ost.back(), b;
            ost.pop_back();
            b = ost.back();
            ost.pop_back();
            ans.push_back({a, b});
        }
    }
    ll x = ost.size() / 2;
    for (ll i = 0; i < x; ++i)
        ans.push_back({ost[2 * i], ost[2 * i + 1]});
    if (ost.size() & 1)
        ost = {ost.back()};
    else
        ost = {};
}

void solve3 (map <ll, map <ll, map <ll, ll>>> &m) {
    for (auto i : m) {
        solve2(i.second);
        while (ost.size() > 2) {
            ll a = ost.back(), b;
            ost.pop_back();
            b = ost.back();
            ost.pop_back();
            ans.push_back({a, b});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        ll x, y, z;
        cin >> x >> y >> z;
        m[x][y][z] = i;
    }
    solve3(m);
    for (auto i : ans)
        cout << i.first + 1 << ' ' << i.second + 1 << '\n';
    return 0;
}

/**


**/
