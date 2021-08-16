#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll P = 1e3 + 8;
const ll M = 1e6 + 8;
const ll INF = INT_MAX;

ll n, ans = INF;
vector <ll> prime(P, -1);
vector <ll> cnt(M, 0);
vector <vector <ll>> g(M);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    for (ll i = 2; i < P; ++i) {
        if (prime[i] != -1) {
            continue;
        }
        for (ll j = i; j < P; j += i) {
            if (prime[j] == -1) {
                prime[j] = i;
            }
        }
    }
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        if (x == 1) {
            ans = 1;
            continue;
        }
        if (x > P || prime[x] == x) {
            cnt[x]++;
            continue;
        }
        vector <ll> a;
        while (x) {
            ll t = prime[x];
            ll k = 0;
            while (x % t == 0) {
                x /= t;
                ++k;
            }
            if (k & 1) {
                a.emplace_back(t);
            }
        }
        if (a.empty()) {
            ans = 1;
        } else if (a.size() == 1) {
            cnt[a[0]]++;
        } else {
            g[a[0]].push_back(a[1]);
            g[a[1]].push_back(a[0]);
        }
    }
    if (ans == 1) {
        cout << "1\n";
        return 0;
    }
    for (ll i = 2; i < M; ++i) {
        if (prime[i] == i && cnt[i] > 1) {
            cout << "2\n";
            return 0;
        }
    }

    return 0;
}

/**


**/
