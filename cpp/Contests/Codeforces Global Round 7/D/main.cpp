#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

mt19937_64 rnd(time(0));

const ll N = 1e5 + 8;
const ll M = 1e9 + 7;
const ll P = 9901;
const ll ABC = 26;

vector <ll> code;
vector <ll> power = {1};

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
    return rnd() % (r - l + 1) + l;
}

void start() {
    unordered_set <ll> s;
    while (s.size() < ABC) {
        s.insert(myrnd(1e3, 1e4));
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
        return h[r];
    }
    return sub(h[r], mul(h[l - 1], power[r - (l - 1)]));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    start();
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        string s;
        cin >> s;
        n = s.size();
        ll p1 = 0, p2 = n - 1;
        string l, r;
        while (p1 < p2 && s[p1] == s[p2]) {
            l = l + s[p1];
            r = s[p2] + r;
            ++p1, --p2;
        }
        string ra = s.substr(p1, p2 - p1 + 1);
        string a = ra;
        reverse(ra.begin(), ra.end());
        //cout << a << endl;
        vector <ll> ha, hra;
        cnthash(a, ha);
        cnthash(ra, hra);
        ll ans1 = 1, ans2 = 1;
        ll m = a.size();
        for (ll i = 1; i <= m / 2; ++i) {
            ll h = gethash(0, i - 1, ha);
            ll h1 = gethash(m - 2 * i, m - 2 * i + i - 1, hra);
            if (h == h1) {
                ans1 = 2 * i;
            }
            if (m >= 2 * i + 1) {
                ll h2 = gethash(m - 2 * i - 1, m - 2 * i - 1 + i - 1, hra);
                if (h == h2) {
                    ans1 = 2 * i + 1;
                }
            }
        }
        swap(ha, hra);
        for (ll i = 1; i <= m / 2; ++i) {
            ll h = gethash(0, i - 1, ha);
            ll h1 = gethash(m - 2 * i, m - 2 * i + i - 1, hra);
            if (h == h1) {
                ans2 = 2 * i;
            }
            if (m >= 2 * i + 1) {
                ll h2 = gethash(m - 2 * i - 1, m - 2 * i - 1 + i - 1, hra);
                if (h == h2) {
                    ans2 = 2 * i + 1;
                }
            }
        }
        if (ans1 > ans2) {
            cout << l << a.substr(0, ans1) << r << '\n';
        } else {
            cout << l << a.substr(m - ans2, ans2) << r << '\n';
        }
    }
    return 0;
}

/**
1
abbaxyzyx

1
abcdfdcecba

**/
