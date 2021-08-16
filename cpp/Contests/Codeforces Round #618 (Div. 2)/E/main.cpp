#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

bool comp(const pair <ld, ll> &a, const pair <ld, ll> &b) {
    return a.first * b.second > b.first * a.second;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    vector <pair <ld, ll>> a;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a.emplace_back(x, 1);
        while (a.size() > 1 && comp(a[a.size() - 2], a.back())) {
            auto t = a.back();
            a.pop_back();
            a.back().first += t.first;
            a.back().second += t.second;
        }
    }
    cout.precision(20);
    for (auto i : a) {
        for (ll j = 0; j < i.second; ++j) {
            cout << (ld)i.first / i.second << '\n';
        }
    }
    return 0;
}

/**


**/
