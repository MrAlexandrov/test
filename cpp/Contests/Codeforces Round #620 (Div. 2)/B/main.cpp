#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vector <string> a(n), b(n);
    vector <bool> c(n, false);
    for (ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        a[i] = s;
        reverse(s.begin(), s.end());
        b[i] = s;
    }
    for (ll i = 0; i < n; ++i) {
        ll l = 0, r = m - 1;
        bool ok = true;
        while (r > l) {
            if (a[i][l] != a[i][r]) {
                ok = false;
                break;
            }
            ++l, --r;
        }
        c[i] = ok;
    }
    vector <bool> used(n, false);
    string ans = "";
    for (ll i = 0; i < n; ++i) {
        if (used[i]) {
            continue;
        }
        for (ll j = i + 1; j < n; ++j) {
            if (used[j]) {
                continue;
            }
            if (a[i] == b[j]) {
                ans = a[i] + ans;
                used[i] = used[j] = true;
            }
        }
    }
    string mid = "";
    for (ll i = 0; i < n; ++i) {
        if (!used[i] && c[i]) {
            mid = a[i];
            break;
        }
    }
    cout << 2 * ans.size() + (mid != "" ? m : 0) << endl;
    cout << ans;
    if (mid != "") {
        cout << mid;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}

/**


**/
