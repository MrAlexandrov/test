#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll INF = (ll)1e18 + 8;
ll n, m;
map <pll, ll> x;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll v, u, w;
        cin >> v >> u >> w;
        if (v > u) x[{u, v}] += w;
        else x[{v, u}] += w;
    }
    while (n--) {
        ///for (auto i = x.begin(); i != x.end(); ++i)
        for (auto i : x) {
            cout << "i: " << i.first.first << ' ' << i.first.second << ' ' << i.second << endl;
            auto t = x.lower_bound({i.second, 0});
            cout << "t: " << t -> first.first << ' ' << t -> first.second << ' ' << t -> second << endl;
            if (t == x.end()) continue;

            ll mn = (i.second, t -> second);
            x[i.first] -= mn;
            if (x[i.first] == 0) x.erase(i.first);
            x[t -> first] -= mn;
            if (x[t -> first] == 0) x.erase(t -> first);
            x[{i.first.first, t -> first.first}] += mn;
            break;
        }
    }
    ll cnt = 0;
    for (auto i : x)
        cnt += (i.second != 0);
    cout << cnt << endl;
    for (auto i : x) {
        if (i.second != 0) {
            cout << i.first.first << ' ' << i.first.second << ' ' << i.second << endl;
        }
    }
    return 0;
}

/**


**/
