#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll ans = 0;
        ll cnt = 0;
        ll i = 0;
        while (s[i] == 'P' && i < n) {
            ++i;
        }
        for (; i < n; ++i) {
            if (s[i] == 'P') {
                ++cnt;
                ans = max(ans, cnt);
            } else {
                cnt = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/**


**/
