#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll INF = INT_MAX;
ll n;
vector <ll> a;
vector <vector <ll>> dp;
vector <bool> was;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    a.resize(n);
    for (ll i = 0; i < n; ++i)
        cin >> a[i];
    dp.resize(n, vector <ll>(2, INF));
    was.resize(n, false);
    queue <ll> q;
    for (ll i = 0; i < n; ++i) {
        if (!was[i]) {
            q.push(i);
            while (!q.empty()) {
                ll x = q.front();
                q.pop();
                if (was[x]) continue;
                was[x] = true;
                ll l = x - a[x], r = x + a[x];
                if (0 <= l) {
                    dp[x][a[l] & 1] = 1;
                    if (!was[l])
                        q.push(l);
                    dp[x][(a[l] + 1) & 1] = min(dp[x][(a[l] + 1) & 1], dp[l][(a[l] + 1) & 1] + 1);
                }
                if (r < n) {
                    dp[x][a[r] & 1] = 1;
                    if (!was[r])
                        q.push(r);
                    dp[x][(a[r] + 1) & 1] = min(dp[x][(a[r] + 1) & 1], dp[r][(a[r] + 1) & 1] + 1);
                }
            }
        }
    }
    for (ll i = 0; i < n; ++i)
        cout << (dp[i][(a[i] + 1) & 1] == INF ? -1 : dp[i][(a[i] + 1) & 1]) << ' ';
    return 0;
}

/**


**/
