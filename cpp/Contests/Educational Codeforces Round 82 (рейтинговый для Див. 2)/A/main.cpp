#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve() {
    string s;
    cin >> s;
    ll n = s.size();
    ll cnt = 0;
    for (ll i = 0; i < n; ++i) {
        cnt += (s[i] == '1');
    }
    if (cnt == 0) {
        return 0;
    }
    ll l, r;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '1') {
            l = i;
            break;
        }
    }
    for (ll i = n - 1; i >= 0; --i) {
        if (s[i] == '1') {
            r = i;
            break;
        }
    }
    cnt = r - l + 1;
    for (ll i = l; i <= r; ++i) {
        if (s[i] == '1') {
            --cnt;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}

/**


**/
