#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n, k;
ll start = 0;
ll mx = 0;
vector <ll> a;

void no () {
    cout << "No\n";
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> k;
    n *= 2;
    a.resize(n);
    vector <ll> rasn(n);
    for (ll i = 0; i < n; ++i)
        cin >> a[i];
    mx = a.back() - a[0];
    for (ll i = 0; i < (n / 2) + 1; ++i)
        rasn[i + 1] = a[2 * i + 2] - a[2 * i + 1];
    for (ll i = 0; i < n; i += 2)
        now += a[i + 1] - a[i];
    ll need = k - now;
    mx = mx - now;
    vector <ll> ans(n);
    iota(ans.begin(), ans.end(), 1LL);
    if (need < 0) no();
    if (need == 0) {
        cout << "Yes" << endl;
        for (ll i = 0; i < n; i += 2)
            cout << ans[i] << ' ' << ans[i + 1] << endl;
        exit(0);
    }

    ll solve = min(need, mx - need);

    ll dp[n][solve + 1]{};
    for (ll i = 1; i < n; ++i) {
        for (ll j = 0; j <= solve; ++j) {
            if (j - rasn[i] >= 0)
                dp[i][j] = (dp[i - 1][j - rasn[i]] ? i : 0);
            dp[i][j] = dp[i - 1][j];
        }
    }
    ll ok = 0;
    for (ll i = 1; i < n; ++i) {
        if (dp[i][solve]) {
            ok = i;
            break;
        }
    }

    if (need < mx - need) {
        vector <ll> vec;
        while (solve > 0) {
            ll ok1 = dp[ok][solve];
            if (dp[ok][solve] == ok) {
                solve -= rasn[dp[ok][solve]];
                ok = ok1;
                vec.push_back(ok);
            }
            else {
                ok = dp[]
            }
        }
    }

    cout << "No";
    return 0;
}

/**
4 9
0 1 3 5 8 9 10 12

set <ll> possible;

void check () {
    vector <ll> c(15, 0LL);
    for (ll i = 0; i < n; i += 2) {
        if (a[i] > a[i + 1])
            ++c[a[i + 1]], --c[a[i]];
        else
            ++c[a[i]], --c[a[i + 1]];
    }
    ll sum = 0;
    ll cnt = 0;
    for (ll i = 0; i < 15; ++i) {
        sum += c[i];
        if (sum) ++cnt;
    }
    possible.insert(cnt);
}
**/
