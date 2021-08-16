#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n;
vector <vector <ll>> cnt;
vector <vector <ll>> a;
vector <ll> ans;
vector <bool> used;

bool check (ll x, ll first) {
    for (ll i : cnt[x])
        for (ll j : a[i])
            if (j == first)
                return true;
    return false;
}

ll solve (ll x) {
    map <ll, ll> m;
    for (ll i : cnt[ans[x - 2]])
        for (ll j : a[i])
            ++m[j];
    for (ll i : cnt[ans[x - 1]])
        for (ll j : a[i])
            ++m[j];
    for (auto i : m)
        if (i.second == (2 <= x && x <= n - 2 ? 3 : 2) && !used[i.first]) {
            used[i.first] = true;
            return i.first;
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    cnt.resize (n + 8);
    used.resize (n + 8, false);
    for (ll i = 0; i < n - 2; ++i) {
        vector <ll> x (3);
        for (ll j = 0; j < 3; ++j) {
            cin >> x[j];
            cnt[x[j]].push_back(i);
        }
        a.push_back(x);
    }
    ll first, second;
    ans.resize(n);
    for (ll i = 1; i <= n; ++i) {
        if (cnt[i].size() == 1) {
            first = i;
            break;
        }
    }
    for (ll i = 1; i <= n; ++i) {
        if (cnt[i].size() == 2 && check (i, first)) {
            second = i;
            break;
        }
    }
    ans[0] = first, ans[1] = second;
    used[first] = used[second] = true;
    for (ll i = 2; i < n; ++i)
        ans[i] = solve (i);
    for (ll i : ans)
        cout << i << ' ';
    return 0;
}

/**


**/
