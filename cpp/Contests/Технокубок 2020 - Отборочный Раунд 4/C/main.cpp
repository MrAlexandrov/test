#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve () {
    string s;
    cin >> s;
    ll n = s.size();
    vector <pair <char, ll>> a;
    char x = s[0];
    a.push_back({x, 1});
    for (ll i = 1; i < n; ++i) {
        if (s[i] == a.back().first) a.back().second++;
        else a.push_back({s[i], 1});
    }
    vector <ll> ans;
    ll m = a.size();
    ll sum = 0;
    ll i = 0;
    for (; i < m - 2; ++i) {
        if ((a[i].first == 't' && a[i + 1].first == 'w' && a[i + 2].first == 'o' && a[i + 1].second == 1) || (a[i].first == 'o' && a[i + 1].first == 'n' && a[i + 2].first == 'e' && a[i + 1].second == 1)) {
            if (a[i + 2].second <= a[i].second && a[i + 2].second <= a[i + 1].second) {
                sum += a[i].second + a[i + 1].second;
                for (ll x = 0; x < a[i + 2].second; ++x)
                    ans.push_back(sum + x);
                sum += a[i + 2].second;
                i = i + 3 - 1;
            } else if (a[i + 1].second <= a[i].second && a[i + 1].second <= a[i + 2].second) {
                sum += a[i].second;
                for (ll x = 0; x < a[i + 1].second; ++x)
                    ans.push_back(sum + x);
                sum += a[i + 1].second;
                i = i + 2 - 1;
            } else if (a[i].second <= a[i + 1].second && a[i].second <= a[i + 2].second) {
                for (ll x = 0; x < a[i].second; ++x)
                    ans.push_back(sum + x);
                sum += a[i].second;
                i = i + 1 - 1;
            }
        }
        else {
            sum += a[i].second;
        }
    }
    cout << ans.size() << endl;
    for (ll i : ans)
        cout << i + 1 << ' ';
    cout << endl;
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


**/
