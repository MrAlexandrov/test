#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve () {
	string s;
	cin >> s;
	ll n = s.size();
    for (ll i = 0; i < n - 1; ++i) {
        if (s[i] != '?' && s[i] == s[i + 1]) {
			cout << -1 << endl;
			return;
        }
    }
    if (s[0] == '?') {
        if (n == 1) {
			cout << "a" << endl;
			return;
        }
        if (s[1] == 'a') s[0] = 'b';
        else s[0] = 'a';
    }
    for (ll i = 1; i < n - 1; ++i) {
        if (s[i] != '?') continue;
        set <char> x = {'a', 'b', 'c'};
        x.erase(s[i - 1]);
        x.erase(s[i + 1]);
        s[i] = *x.begin();
    }
    if (s[n - 1] == '?') {
		set <char> x = {'a', 'b', 'c'};
        x.erase(s[n - 2]);
        s[n - 1] = *x.begin();
    }
    cout << s << endl;
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
