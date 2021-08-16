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
    string s;
    cin >> n >> s;
    s += '#';
    vector <ll> a;
    ll cnt = 1;
    for (ll i = 1; i < n + 1; ++i) {
        if (s[i - 1] == s[i])
            ++cnt;
        else {
            a.push_back(cnt);
            cnt = 1;
        }
    }
    ll ans = 0;
    for (ll i = 0; i < a.size() - 1; ++i)
        ans += a[i] + a[i + 1] - 1;
    cout << n * (n - 1) / 2 - ans;
    return 0;
}

/**


**/
