#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

mt19937_64 rnd(time(0));

const ll N = 1e6 + 8;
const ll M = 1e9 + 7;
const ll P = 9901;
const ll ABC = 26;

vector <ll> code;
vector <ll> power = {1LL};

ll sum(ll a, ll b) {
    return (a + b) % M;
}

ll mul(ll a, ll b) {
    return (a * b) % M;
}

ll sub(ll a, ll b) {
    return (a - b + M) % M;
}

ll binpow(ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

ll rev(ll a) {
    return binpow(a, M - 2);
}

ll myrnd(ll l, ll r) {
    return rnd() % (r - l) + l;
}

void start() {
    unordered_set <ll> s;
    while (s.size() < ABC) {
        s.insert(myrnd(1e3, 1e4 + 1));
    }
    for (auto i : s) {
        code.push_back(i);
    }
    for (ll i = 0; i < N; ++i) {
        power.push_back(mul(power.back(), P));
    }
}

void cnthash(string s, vector <ll> &h) {
    ll n = s.size();
    if (n == 0) {
        return;
    }
    h.resize(n);
    for (ll i = 0; i < n; ++i) {
        s[i] -= 'a';
    }
    h[0] = code[s[0]];
    for (ll i = 1; i < n; ++i) {
        h[i] = mul(h[i - 1], P);
        h[i] = sum(h[i], code[s[i]]);
    }
}

ll cnthash(string s) {
    ll res = 0;
    ll n = s.size();
    if (n == 0) {
        return -1;
    }
    for (ll i = 0; i < n; ++i) {
        s[i] -= 'a';
    }
    for (ll i = 0; i < n; ++i) {
        res = sum(res, mul(code[s[i]], power[n - i - 1]));
    }
    return res;
}

ll gethash(ll l, ll r, vector <ll> &h) {
    if (l == 0) {
        return h[r - 1];
    }
    return sub(h[r - 1], mul(h[l - 1], power[r - 1 - (l - 1)]));
}
///R
void cntRhash(string s, vector <ll> &rh) {
    ll n = s.size();
    if (n == 0) {
        return;
    }
    rh.resize(n);
    for (ll i = 0; i < n; ++i) {
        s[i] -= 'a';
    }
    rh[0] = code[s[0]];
    for (ll i = 1; i < n; ++i) {
        rh[i] = sum(rh[i - 1], mul(code[s[i]], power[i]));
    }
}

ll cntRhash(string s) {
    ll res = 0;
    ll n = s.size();
    if (n == 0) {
        return -1;
    }
    for (ll i = 0; i < n; ++i) {
        s[i] -= 'a';
    }
    for (ll i = 0; i < n; ++i) {
        res = sum(res, mul(code[s[i]], power[i]));
    }
    return res;
}

ll getRhash(ll l, ll r, vector <ll> &rh) {
    if (l == 0) {
        return rh[r - 1];
    }
    return mul(sub(rh[r - 1], rh[l - 1]), rev(power[l]));
}

void solve() {
    string s;
    cin >> s;
    ll n = s.size();
    ll l = 0, r = n - 1;
    while (l < r && s[l] == s[r]) {
        ++l, --r;
    }
    string ans = s.substr(0, l);
    string a = s.substr(l, r - l + 1);
    ll m = a.size();
    vector <ll> h, rh;
    cnthash(a, h);
    cntRhash(a, rh);
    ll ans1 = min(1LL, m), ans2 = min(1LL, m);
    for (ll x = 1; x <= (m - 1) / 2; ++x) {
        if (gethash(0, x, h) == getRhash(x + 1, x + 1 + x, rh)) {
            ans1 = max(ans1, 2 * x + 1);
        }
        if (gethash(m - 2 * x - 1, m - x - 1, h) == getRhash(m - x, m, rh)) {
            ans2 = max(ans2, 2 * x + 1);
        }
    }
    for (ll x = 1; x <= m / 2; ++x) {
        if (gethash(0, x, h) == getRhash(x, 2 * x, rh)) {
            ans1 = max(ans1, 2 * x);
        }
        if (gethash(m - 2 * x, m - x, h) == getRhash(m - x, m, rh)) {
            ans2 = max(ans2, 2 * x);
        }
    }
    cout << ans;
    if (ans1 > ans2) {
        cout << a.substr(0, ans1);
    } else {
        cout << a.substr(m - ans2, ans2);
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    start();
    ll q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}

/**


**/
