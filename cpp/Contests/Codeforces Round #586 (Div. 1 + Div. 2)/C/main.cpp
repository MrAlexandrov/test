#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

string s;
ll n;
vector <ll> dp (5 * 1e5 + 8);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> s;
    n = s.size();
    dp[0] = 0;
    char mn = s[0];
    for (ll i = 1; i < n; ++i) {
        mn = min (mn, s[i - 1]);
        dp[i] = (s[i] > mn ? 1 : 0);
    }
    for (ll i = 0; i < n; ++i)
        cout << (dp[i] ? "Ann" : "Mike") << '\n';
    return 0;
}
