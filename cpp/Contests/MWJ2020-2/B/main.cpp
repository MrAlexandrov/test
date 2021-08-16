#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n;
    cin >> n;
    vector <string> b(n);
    vector <pll> a = {{5, 0}};
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
        ll two = 0;
        for (char j : b[i]) two += (j == '2');
        if (two <= 1) {
            if (i == 0) {
                a.push_back({5, b[i].size() - two});
            } else {
                if (a.back().first == 5)
                    a.back().second += b[i].size() - two;
                else
                    a.push_back({5, b[i].size() - two});
            }
            continue;
        }

        vector <pll> t;
        t.push_back({b[i][0] - '0', 1});
        for (ll j = 1; j < b[i].size(); ++j) {
            if (t.back().first == b[i][j] - '0') t.back().second++;
            else t.push_back({b[i][j] - '0', 1});
        }
        if (t[0].first == 5) {
            if (t.size() >= 3) {
                if (t[1].second == 1) {
                    if (a.back().first == 2)
                        a.push_back({5, 0});
                    a.back().second += t[0].second + t[2].second;
                }
            }
        } else {
            if (t.size() >= 2) {
                if (t[0].second == 1) {
                    if (a.back().first == 2)
                        a.push_back({5, 0});
                    a.back().second += t[1].second;
                }
            }
        }
        for (ll i = 0; i < t.size(); ++i) {
            if (t[i].first == 5) {
                a.push_back(t[i]);
            } else {
                if (t[i].second == 1) {
                    ll cnt = 0;
                    cnt += (0 <= i - 1 ? t[i - 1].second : 0);
                    cnt += (i + 1 < t.size() ? t[i + 1].second : 0);
                    a.push_back({5, cnt});
                }
            }
        }
        if (t.back().first == 5) {
            if (t.size() >= 3) {
                if (t[t.size() - 2].second == 1) {
                    a.push_back({5, t[t.size() - 3].second + t[t.size() - 1].second});
                }
            }
        }
    }
    for (auto i : a) {
        if (i.first == 5)
            ans = max(ans, i.second);
    }
    cout << ans << endl;
    return 0;
}

/**


**/
