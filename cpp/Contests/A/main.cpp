#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    if (1LL * 4 * n * m - 2 * n - 2 * m < k) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector <pair <ll, char>> ans;
    for (ll i = 0; i < n - 1; ++i) {
        ans.emplace_back(m - 1, 'R');
        ans.emplace_back(m - 1, 'L');
        ans.emplace_back(1, 'D');
    }
    ans.emplace_back(m - 1, 'R');
    for (ll i = 0; i < m - 1; ++i) {
        ans.emplace_back(n - 1, 'U');
        ans.emplace_back(n - 1, 'D');
        ans.emplace_back(1, 'L');
    }
    ans.emplace_back(n - 1, 'U');
    ll sum = 1LL * 4 * n * m - 2 * n - 2 * m;
    while (sum > k) {
        if (sum - ans.back().first >= k) {
            sum -= ans.back().first;
            ans.pop_back();
        } else {
            ans.back().first -= sum - k;
            break;
        }
    }
    ll sz = ans.size();
    for (ll i = 0; i < ans.size(); ++i) {
        if (ans[i].first == 0) {
            --sz;
        }
    }
    cout << sz << endl;
    for (auto i : ans) {
        if (i.first != 0) {
            cout << i.first << ' ' << i.second << endl;
        }
    }
    return 0;
}

/**


**/
