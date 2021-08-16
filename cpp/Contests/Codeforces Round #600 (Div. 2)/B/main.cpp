#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n;
vector <ll> a;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    a.resize(n);
    for (ll i = 0; i < n; ++i)
        cin >> a[i];
    vector <ll> ans;
    ll cnt = 0;
    set <ll> was;
    set <ll> is;
    for (ll i = 0; i < n; ++i) {
        ll t = a[i];
        if (was.find(t) != was.end() || was.find(-t) != was.end() || (t < 0 && is.find(-t) == is.end()) || (t > 0 && is.find(t) != is.end())) {
            cout << "-1\n";
            return 0;
        }
        if (t > 0)
            is.insert(t);
        else {
            is.erase(-t);
            was.insert(-t);
        }
        if (is.empty()) {
            ans.push_back(i);
            was.clear();
        }
    }
    if (is.size()) {
        cout << "-1\n";
        return 0;
    }
    cout << ans.size() << '\n';
    for (ll i = 0; i < ans.size(); ++i)
        cout << (i ? ans[i] - ans[i - 1] : ans[i] + 1) << ' ';
    return 0;
}

/**


**/
