#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 1e5 + 8;
const ll P = 7;
const ll INF = LLONG_MAX;

ll n, p, k;
ll a[N], b[N][(1LL << P) + 8], dp[N][(1LL << P) + 8], cnt[(1LL << P) + 8];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> p >> k;
    for (ll mask = 0; mask < (1LL << p); ++mask) {
        for (ll i = 0; i < p; ++i) {
            if ((1LL << i) & mask) {
                ++cnt[mask];
            }
        }
    }
    vector <ll> t;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
        t.push_back(i);
    }
    sort(t.begin(), t.end(), [](ll l, ll r) {
        return a[l] > a[r];
    });
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= p; ++j) {
            cin >> b[i][j];
        }
    }
    for (ll i = 0; i <= n; ++i) {
        for (ll mask = 0; mask < (1LL << p); ++mask) {
            dp[i][mask] = -INF;
        }
    }
    dp[0][0] = 0;
    for (ll i = 1; i <= n; ++i) {
        ll x = t[i - 1];
        for (ll mask = 0; mask < (1LL << p); ++mask) {
            dp[i][mask] = dp[i - 1][mask];
            if (cnt[mask] + k >= i) {
                dp[i][mask] += a[x];
            }
        }
        for (ll j = 0; j < p; ++j) {
            for (ll mask = 0; mask < (1LL << p); ++mask) {
                if ((1LL << j) & mask) {
                    continue;
                }
                ll to = mask + (1LL << j);
                dp[i][to] = max(dp[i][to], dp[i - 1][mask] + b[x][j + 1]);
            }
        }
    }
    cout << dp[n][(1LL << p) - 1] << '\n';
    return 0;
}

/**


**/
