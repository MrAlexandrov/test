#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <long long, long long> pll;

ll q;

bool cmp(pll a, pll b) {
    return b.second < a.second;
}

pll solve () {
    ll n;
    cin >> n;
    map <ll, pll> a;
    for (ll i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        a[x].first++;
        a[x].second += y;
    }
    vector <pll> b;
    for (pair <ll, pll> i : a)
        b.push_back(i.second);
    sort(b.rbegin(), b.rend());
    /*
    for (pll i : b)
        cout << i.first << ' ' << i.second << '\n';
    */
    pll ans = {*b.begin()};
    ll last = (*b.begin()).first;
    n = b.size();
    for (ll i = 1; i < n; ++i) {
        if (b[i].first == last)
            last = b[i].first - 1;
        else {
            if (b[i].first >= last)
                last = last - 1;
            else
                last = b[i].first;
        }
        if (last > 0) {
            ans.first += last;
            ans.second += min(last, b[i].second);
        }
    }
    cout << '\n';
    for (ll i = 0; i < n; ++i)
        cout << b[i].first << ' ' << b[i].second << '\n';
    cout << '\n';
    return ans;
}

int main()
{
    cin >> q;
    while (q--) {
        pll t = solve();
        cout << t.first << ' ' << t.second << '\n';
    }
    return 0;
}
