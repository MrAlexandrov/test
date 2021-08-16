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
    vector <bool> a(n);
    for (ll i = 0; i < n; ++i) {
        char s;
        cin >> s;
        a[i] = s == 'L';
    }
    vector <vector <ll>> ans;
    ll cnt = 0;
    while (true) {
        ans.push_back({});
        for (ll i = 0; i < n - 1; ++i) {
            if (a[i] == 0 && a[i + 1] == 1) {
                ans.back().push_back(i + 1);
                swap(a[i], a[i + 1]);
                ++i;
            }
        }
        cnt += ans.back().size();
        if (ans.back().empty()) {
            break;
        }
    }
    ans.pop_back();
    if (!(ans.size() <= k && k <= cnt)) {
        cout << "-1\n";
        return 0;
    }
    ll need = k - ans.size();
    for (ll i = 0; i < ans.size(); ++i) {
        if (need) {
            ll sz = ans[i].size();
            ll k = min(need, sz - 1);
            for (ll j = 0; j < k; ++j, --need) {
                cout << 1 << ' ' << ans[i].back() << '\n';
                ans[i].pop_back();
            }
        }
        cout << ans[i].size() << ' ';
        for (ll j : ans[i]) {
            cout << j << ' ';
        }
        cout << '\n';
    }
    return 0;
}

/**


**/
