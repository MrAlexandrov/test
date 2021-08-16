#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 1e2 + 8;
const ll W = 1e5 + 8;

ll n, w;
struct item {
    ll w, v;
};
vector <item> a;

ll dp[W][N] {};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> w;
    a.resize (n + 1);
    for (ll i = 1; i <= n; ++i)
        cin >> a[i].w >> a[i].v;
    for (ll k = 1; k <= n; ++k) {
        for (ll x = 0; x <= w; ++x) {
            if (x - a[k].w >= 0)
                dp[x][k] = max (dp[x][k], dp[x - a[k].w][k - 1] + a[k].v);
            dp[x][k] = max (dp[x][k], dp[x][k - 1]);
        }
    }
    cout << dp[w][n] << '\n';
    return 0;
}
