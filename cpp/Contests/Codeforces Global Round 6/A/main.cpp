#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve () {
    string s;
    cin >> s;
    ll zero = 0;
    ll two = 0;
    ll sum = 0;
    for (char i : s) {
        sum += (i - '0');
        zero += (i == '0');
        two += ((i - '0') % 2 == 0);
    }
    cout << (two >= 2 && zero && sum % 3 == 0 ? "red" : "cyan") << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/**


**/
