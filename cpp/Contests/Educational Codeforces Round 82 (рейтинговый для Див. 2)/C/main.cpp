#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    ll n = s.size();
    if (n == 1) {
        cout << "YES" << endl;
        for (ll i = 0; i < 26; ++i) {
            cout << char(i + 'a');
        }
        cout << endl;
        return;
    }
    vector <set <ll>> a(26);
    for (ll i = 0; i < n - 1; ++i) {
        a[s[i] - 'a'].insert(s[i + 1] - 'a');
        a[s[i + 1] - 'a'].insert(s[i] - 'a');
    }
    ll start = -1, finish = -1;
    for (ll i = 0; i < 26; ++i) {
        if (a[i].size() > 2) {
            cout << "NO" << endl;
            return;
        }
        if (a[i].size() == 1) {
            if (start != -1) {
                finish = i;
            } else {
                start = i;
            }
        }
    }
    if (start == -1) {
        cout << "NO" << endl;
        return;
    }
    string res;
    ll p = start;
    while (start != finish) {
        res += char(start + 'a');
        for (auto u : a[start]) {
            if (u != p) {
                p = start;
                start = u;
                break;
            }
        }
    }
    res += char(finish + 'a');
    cout << "YES" << endl;
    for (ll i = 0; i < 26; ++i) {
        if (a[i].size() == 0) {
            res += char(i + 'a');
        }
    }
    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/**


**/
