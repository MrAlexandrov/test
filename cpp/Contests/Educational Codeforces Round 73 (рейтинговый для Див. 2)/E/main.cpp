#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll q;

void answer (bool x) {
    cout << (x ? "YES\n" : "NO\n");
}

bool is_win (ll x) {
    return !(x & 1);
}

void solve () {
    ll a, b;
    string s;
    cin >> a >> b;
    cin >> s;
    vector <ll> block;
    ll i = 0, cnt = 0;
    s += 'X';
    ///cout << s << endl;
    ll n = s.size();
    while (i < n) {
        if (s[i] == 'X') {
            if (cnt > 0) {
                block.push_back(cnt);
                cnt = 0;
            }
        }
        else {
            ++cnt;
        }
        ++i;
    }
    /*
    cout << "block: ";
    for (ll i : block)
        cout << i << ' ';
    cout << endl;
    //*/

    ll type2 = 0, type3 = 0;
    vector <ll> type4;

    for (ll x : block) {
        if (x < b)
            continue;
        else if (b <= x && x < a)
            ++type2;
        else if (a <= x && x < 2 * b)
            ++type3;
        else if (2 * b <= x)
            type4.push_back (x);
    }

    ///cout << "types: " << type2 << ' ' << type3 << ' ' << type4.size() << ' ' << type4[0] << endl;

    if (type2 || type4.size() > 1) {
        answer (0);
        return;
    }

    if (type4.size()) {
        ll x = type4[0];
        for (ll i = 0; i <= x - a; ++i) {
            ll n = i, m = (x - a) - i;
            ll locale_type3 = type3;
            ///cout << n << ' ' << m << endl;
            if (!(b <= n && n < a) && !(b <= m && m < a) && !(2 * b <= n) && !(2 * b <= m)) {
                if (a <= n && n <= 2 * b)
                    ++locale_type3;
                if (a <= m && m <= 2 * b)
                    ++locale_type3;
                if (is_win (locale_type3)) {
                    answer (1);
                    return;
                }
            }
        }
        answer (0);
        return;
    }
    else {
        answer (is_win (type3 + 1));
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> q;
    while (q--)
        solve ();
    return 0;
}
