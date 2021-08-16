#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n;

void z (string s, vector <ll> &z) {
	z.resize(n, 0);
	for (ll i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min (r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    string s;
    cin >> s;
    n = s.size();
    vector <ll> a;
    z(s, a);
    a[0] = n;
    vector <ll> ans(n + 2, 0);
    for (ll i = 0; i < n; ++i) {
        if (a[i]) {
            ++ans[1];
            --ans[a[i] + 1];
        }
    }
    ll sum = 0;
    for (ll i = 0; i <= n; ++i) {
        sum += ans[i];
        ans[i] = sum;
    }
    vector <pll> solve;
    for (ll i = 0; i < n; ++i)
        if (a[(n - 1) - i] == i + 1)
            solve.push_back({i + 1, ans[i + 1]});
    cout << solve.size() << endl;
    for (auto i : solve)
        cout << i.first << ' ' << i.second << endl;
    return 0;
}

/**


**/
