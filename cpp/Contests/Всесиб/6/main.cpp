#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n, q;
string s;

bool ask(ll l, ll r) {
    ll a = l, b = r;
    while (a < b) {
        if (s[a] != s[b]) {
            return false;
        }
        ++a, --b;
    }
    return true;
}

void update(ll l, ll r, char x) {
    for (ll i = l; i <= r; ++i) {
        s[i] = x;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    cin >> n >> q;
    cin >> s;
    while (q--) {
        string t;
        ll l, r;
        cin >> t >> l >> r;
        --l, --r;
        if (t == "ask") {
            cout << (ask(l, r) ? "YES" : "NO") << endl;
        } else {
            char x;
            cin >> x;
            update(l, r, x);
        }
    }
    return 0;
}

/**


**/
