#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll ABC = 26;
const ll INF = INT_MAX;

string s, t;

bool check(const string &a, const string &b, vector <vector <ll>> &nxt) {
    ll n = a.size(), m = b.size();
    vector <vector <ll>> dp(n + 1, vector <ll>(m + 1, INF));
    dp[0][0] = 0;
    for (ll i = 0; i < n + 1; ++i) {
        for (ll j = 0; j < m + 1; ++j) {
            ll len = dp[i][j];
            if (len > s.size()) {
                continue;
            }
            if (i < n) {
                dp[i + 1][j] = min(dp[i + 1][j], nxt[len][a[i]] + 1);
            }
            if (j < m) {
                dp[i][j + 1] = min(dp[i][j + 1], nxt[len][b[j]] + 1);
            }
        }
    }
    return dp[n][m] < INF;
}

string solve() {
    cin >> s >> t;
    ll n = s.size(), m = t.size();
    for (ll i = 0; i < n; ++i) {
        s[i] -= 'a';
    }
    for (ll j = 0; j < m; ++j) {
        t[j] -= 'a';
    }
    vector <vector <ll>> nxt(n + 1, vector <ll>(ABC, INF));
    for (ll i = n - 1; i >= 0; --i) {
        nxt[i] = nxt[i + 1];
        nxt[i][s[i]] = i;
    }
    for (ll i = 0; i < m; ++i) {
        if (check(t.substr(0, i), t.substr(i, m), nxt)) {
            return "YES";
        }
    }
    return "NO";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll T;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}

/**


**/
