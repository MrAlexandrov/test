#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    cin >> s;
    ll ans = 0;
    for (ll i = 0; i < n; i += 2) {
        if (s[i] == s[i + 1]) {
            ++ans;
            if (s[i] == 'a')
                s[i] = 'b';
            else
                s[i] = 'a';
        }
    }
    cout << ans << '\n';
    cout << s << '\n';
    return 0;
}
