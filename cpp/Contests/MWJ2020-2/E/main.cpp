#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll M = 1000000007LL;

ll mul (ll a, ll b) {
    return (1LL * a * b) % M;
}

ll sm (ll a, ll b) {
    return (0LL + a + b + M) % M;
}

ll bin_pow (ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1)
            res = mul(res, a);
        n >>= 1;
        a = mul(a, a);
    }
    return res;
}

ll inv (ll a) {
    return bin_pow(a, M - 2);
}

void pref (string s, vector <ll> &pi) {
	ll n = s.size();
	pi.resize(n, 0);
	for (ll i = 1; i < n; ++i) {
		ll j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j]) ++j;
		pi[i] = j;
	}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll k;
    cin >> k;
    string s;
    cin >> s;
    vector <ll> p;
    ll sum = 0;
    if (k == 1) {
        pref(s, p);
        for (ll i : p)
            sum = sm(sum, i);
        cout << sum << endl;
        return 0;
    }
    string res = s + s + s[0];
    pref(res, p);
    for (ll i : p)
        sum = sm(sum, i);
    sum = sm(sum, -p.back());
    ll sz = s.size();

    ll t = p.back();
    ll x = mul(k - 2, sz);
    ll a = sm(mul(2, t), sm(x, -1));
    ll b = inv(2);
    ll ex = mul(a, x);
    ex = mul(ex, b);

    sum = sm(sum, ex);

    cout << sum << endl;
    return 0;
}

/**
3
abab

3
aabaa

**/
