#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

vector <pll> ans;

void change (string &s, string &t, ll i, ll j) {
    if (s[i] == s[j]) {
        swap (s[j], t[i]);
        ans.push_back({j, i});
    }
    else if (s[i] == t[j]) {
        swap (s[j], t[j]);
        swap (s[j], t[i]);
        ans.push_back({j, j});
        ans.push_back({j, i});
    }
    else if (t[i] == t[j]) {
        swap (s[i], t[j]);
        ans.push_back({i, j});
    }
    else if (t[i] == s[j]) {
        swap (s[j], t[j]);
        swap (s[i], t[j]);
        ans.push_back({j, j});
        ans.push_back({i, j});
    }
}

void solve () {
    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector <ll> cnt (26, 0);
    for (ll i = 0; i < n; ++i)
        ++cnt[s[i] - 'a'],
        ++cnt[t[i] - 'a'];
    for (ll i = 0; i < 26; ++i) {
        if (cnt[i] & 1) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    ans.clear();
    for (ll i = 0; i < n; ++i)
        if (s[i] != t[i])
            for (ll j = i + 1; j < n; ++j)
                if (s[j] == s[i] || s[j] == t[i] || t[j] == s[i] || t[j] == t[i]) {
                    change (s, t, i, j);
                    break;
                }

    cout << ans.size() << '\n';
    for (pll i : ans)
        cout << i.first + 1 << ' ' << i.second + 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll k;
    cin >> k;
    while (k--)
        solve ();
    return 0;
}

/**


**/
