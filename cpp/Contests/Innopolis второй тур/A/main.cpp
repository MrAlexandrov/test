#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    string s;
    cin >> s;
    ll n = s.size();
    string ans;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            ans += ' ';
            ans += s[i];
            ans += ' ';
        }
        else
            ans += s[i];
    }
    cout << ans;
    return 0;
}

/**


**/
