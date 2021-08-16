#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

string s1, s2;
vector <pll> way;

ll cost (const char &a, const char &b) {
    return (a != b);
}

ll Levenshtein (const string &s1, const string &s2) {
    ll n = s1.size(), m = s2.size();
    pair <ll, pll> x[n + 1][m + 1];
    x[0][0] = {0, {0, 0}};
    for (ll i = 1; i < n + 1; ++i)
        x[i][0].first = i,
        x[i][0].second = {i - 1, 0};
    for (ll j = 1; j < m + 1; ++j)
        x[0][j].first = j,
        x[0][j].second = {0, j - 1};
    for (ll i = 1; i < n + 1; ++i)
        for (ll j = 1; j < m + 1; ++j) {
            ll mn = min ({x[i - 1][j].first + 1,
                          x[i][j - 1].first + 1,
                          x[i - 1][j - 1].first + cost (s1[i - 1], s2[j - 1])});
            x[i][j].first = mn;
            if (mn == x[i - 1][j].first + 1) {
                x[i][j].second = {i - 1, j};
            } else
            if (mn == x[i][j - 1].first + 1) {
                x[i][j].second = {i, j - 1};
            } else
            if (mn == x[i - 1][j - 1].first + cost (s1[i - 1], s2[j - 1])) {
                x[i][j].second = {i - 1, j - 1};
            }
        }
    pll t = {n, m};
    for (; t != x[0][0].second; ) {
        way.push_back (t);
        t = x[t.first][t.second].second;
    }
    way.push_back ({0, 0});
    return x[n][m].first;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> s1 >> s2;
    Levenshtein (s1, s2);
    string ans;
    vector <bool> b1 (s1.size());
    vector <bool> b2 (s2.size());
    for (ll i = 0; i < way.size() - 1; ++i) {
        if (s1[way[i].first - 1] == s2[way[i].second - 1] && !b1[way[i].first - 1] && !b2[way[i].second - 1]) {
            ans += (b1[way[i].first - 1] ? ' ' : s1[way[i].first - 1]);
            b1[way[i].first - 1] = true;
            b2[way[i].second - 1] = true;
        }
    }
    reverse (ans.begin(), ans.end());
    cout << ans;
    return 0;
}
