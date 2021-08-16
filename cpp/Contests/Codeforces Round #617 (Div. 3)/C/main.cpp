#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n;
    cin >> n;
    map <ll, vector <ll>> m;
    m[0].push_back(0);
    ll now = 0;
    for (ll i = 0; i < n; ++i) {
        char x;
        cin >> x;
        if (x == 'L') {
            now -= 1;
        } else if (x == 'R') {
            now += 1;
        } else if (x == 'U') {
            now += (ll)1e9;
        } else if (x == 'D') {
            now -= (ll)1e9;
        }
        m[now].push_back(i + 1);
    }
    pll ans = {0, INT_MAX};
    for (auto i : m) {
        for (ll j = 0; j < i.second.size() - 1; ++j) {
            if (i.second[j + 1] - i.second[j] < ans.second - ans.first) {
                ans = {i.second[j] + 1, i.second[j + 1]};
            }
        }
    }
    if (ans.second == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans.first << ' ' << ans.second << endl;
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/**


**/
