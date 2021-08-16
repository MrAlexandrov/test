#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

vector <string> ex = {
    "1110111",
    "0010010",
    "1011101",
    "1011011",
    "0111010",
    "1101011",
    "1101111",
    "1010010",
    "1111111",
    "1111011"
};

ll diff(const string &a, const string &b) {
    ll res = 0;
    ll n = a.size();
    for (ll i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            return -1;
        }
        res += (a[i] != b[i]);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n, k;
    cin >> n >> k;
    vector <string> a(n);
    vector <vector <ll>> b(n, vector <ll>(8, -1));
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        for (ll j = 0; j < 8; ++j) {
            ll now = -1;
            for (ll x = 0; x < 10; ++x) {
                if (diff(a[i], ex[x]) == j) {
                    now = max(now, x);
                }
            }
            b[i][j] = now;
        }
    }
    vector <ll> pos(n);
    ll mn = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < 8; ++j) {
            if (b[i][j] != -1) {
                pos[i] = j;
                mn += j;
                break;
            }
        }
    }
    if (k < mn) {
        cout << "-1\n";
        return 0;
    }
    k -= mn;
    for (ll i = 0; i < n; ++i) {
        cout << b[i][pos[i]];
    }
    cout << endl;
    for (ll i = 0; i < n && k > 0; ++i) {
        ll mx = pos[i];
        for (ll j = pos[i]; j < 8; ++j) {
            if (b[i][j] > b[i][mx] && k >= j - pos[i]) {
                mx = j;
            }
        }
        k -= mx - pos[i];
        pos[i] = mx;
    }
    for (ll i = 0; i < n; ++i) {
        cout << b[i][pos[i]];
    }
    cout << endl;
    for (ll i = n - 1; i >= 0 && k > 0; --i) {
        ll now;
        for (ll j = 7; j >= 0; --j) {
            if (b[i][j] != -1) {
                now = j - pos[i];
                break;
            }
        }
        pos[i] += min(k, now);
        k -= min(k, now);
    }
    if (k == 0) {
        for (ll i = 0; i < n; ++i) {
            cout << b[i][pos[i]];
        }
    } else {
        cout << "-1";
    }
    cout << '\n';
    return 0;
}

/**


**/
