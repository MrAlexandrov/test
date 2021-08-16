#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n;
    cin >> n;
    vector <vector <pair <string, ll>>> a(4);
    set <string> str;
    for (ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s[0] == '0' && s.back() == '0')
            a[0].push_back({s, i});
        else if (s[0] == '0' && s.back() == '1')
            a[1].push_back({s, i});
        else if (s[0] == '1' && s.back() == '0')
            a[2].push_back({s, i});
        else if (s[0] == '1' && s.back() == '1')
            a[3].push_back({s, i});
        str.insert(s);
    }
    vector <ll> b(4);
    for (ll i = 0; i < 4; ++i)
        b[i] = a[i].size();
    if (b[1] + b[2] == 0 && b[0] && b[3]) {
        cout << -1 << endl;
        return;
    }
    vector <ll> ans;
    ll need = (b[1] + b[2]) / 2;
    need = need - min(b[1], b[2]);
    if (b[1] < b[2]) {
        for (ll i = 0; i < b[2] && need; ++i) {
            string t = a[2][i].first;
            reverse(t.begin(), t.end());
            if (str.find(t) == str.end()) {
                ans.push_back(a[2][i].second);
                --need;
            }
        }
    }
    else {
        for (ll i = 0; i < b[1] && need; ++i) {
            string t = a[1][i].first;
            reverse(t.begin(), t.end());
            if (str.find(t) == str.end()) {
                ans.push_back(a[1][i].second);
                --need;
            }
        }
    }
    if (need) {
        cout << -1 << endl;
    }
    else {
        cout << ans.size() << endl;
        for (ll i : ans)
            cout << i + 1 << ' ';
        cout << endl;
    }
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
