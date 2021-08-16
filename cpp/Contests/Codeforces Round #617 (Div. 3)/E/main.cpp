#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll ABC = 26;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    for (auto &i : s) {
        i -= 'a';
    }
    vector <ll> maxdp(ABC);
    vector <ll> dp(n, 1);
    for (ll i = 0; i < n; ++i) {
        for (ll j = s[i] + 1; j < ABC; ++j) {
            dp[i] = max(dp[i], maxdp[j] + 1);
        }
        maxdp[s[i]] = max(maxdp[s[i]], dp[i]);
    }
    cout << *max_element(maxdp.begin(), maxdp.end()) << '\n';
    for (ll i = 0; i < n; ++i) {
        cout << dp[i] << ' ';
    }
    return 0;
}

/**


**/
