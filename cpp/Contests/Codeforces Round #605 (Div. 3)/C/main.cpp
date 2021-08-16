#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <bool> a(26, false);
    for (ll i = 0; i < k; ++i) {
        char x;
        cin >> x;
        a[x - 'a'] = true;
    }
    ll l = 0, r = -1;
    ll cnt_bad = 0;
    vector <ll> b(26, 0);
    ll ans = 0;
    while (r < n) {
        while (cnt_bad) {
            --b[s[l] - 'a'];
            if (b[s[l] - 'a'] == 0 && !a[s[l] - 'a']) --cnt_bad;
            ++l;
        }
        ans += (ll)(cnt_bad == 0 && l <= r) * (r - l + 1);
        if (r == n - 1)
            break;
        ++r;
        ++b[s[r] - 'a'];
        if (!a[s[r] - 'a']) ++cnt_bad;
    }
    cout << ans << endl;
    return 0;
}

/**


**/
