#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n;
    cin >> n;
    vector <ll> ans(n + 1, 0);
    ans[1] = 1;
    for (ll i = 2; i <= n; ++i) {
        if (ans[i]) {
            continue;
        }
        for (ll j = i; j <= n; j += i) {
            if (ans[j]) {
                continue;
            }
            ans[j] = j / i;
        }
    }
    sort(ans.begin(), ans.end());
    for (ll i = 2; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}

/**


**/
