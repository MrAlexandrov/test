#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

string to_16 (ll x) {
    string res;
    while (x) {
        ll t = x % 16;
        x >>= 4;
        res += (t < 10 ? char('0' + t) : char('a' + t - 10));
    }
    reverse(res.begin(), res.end());
    return res;
}

void solve (ll n, ll k) {
    ll sq = sqrt(n);
    if (k == 2) {
        for (ll i = sq; i >= 2; --i) {
            if (n % i == 0) {
                cout << to_16(i) << endl;
                cout << to_16(n / i) << endl;
                return;
            }
        }
    } else {
        for (ll i = sq; i >= 2; --i) {
            if (n % i == 0) {
                solve(i, 2);
                solve(n / i, 2);
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n, k;
    string s;
    ll num = 0;
    cin >> n >> k;
    cin >> s;
    for (char i : s) {
        num <<= 4;
        num += ('0' <= i && i <= '9' ? i - '0' : i - 'a' + 10);
    }
    solve(num, k);
    return 0;
}

/**


**/

