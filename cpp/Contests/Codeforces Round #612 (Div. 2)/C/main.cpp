#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n;
    cin >> n;
    vector <pll> a;
    vector <bool> b(n + 1, true);
    ll x;
    cin >> x;
    a.push_back({x, 1});
    b[x] = false;
    for (ll i = 1; i < n; ++i) {
        cin >> x;
        if (a.back().first != x) {
            a.push_back({x, 1});
            b[x] = false;
        } else {
            ++a.back().second;
        }
    }
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    ll odd = 0, even = 0;
    for (ll i = 1; i < n + 1; ++i) {
        if (b[i]) {
            if (i & 1) {
                ++odd;
            } else {
                ++even;
            }
        }
    }
    ll m = a.size();
    vector <ll> odd_block, even_block;
    ll other = 0;
    ll ans = 0;
    for (ll i = 0; i < m; ++i) {
        if (a[i].first == 0) {
            if (m == 1) {
                ++other;
            } else if (i == 0) {
                /*if (a[i + 1].first & 1) {
                    odd_block.push_back(a[i].second);
                } else {
                    even_block.push_back(a[i].second);
                }*/
                ans += 1;
            } else if (i == m - 1) {
                /*if (a[i - 1].first & 1) {
                    odd_block.push_back(a[i].second);
                } else {
                    even_block.push_back(a[i].second);
                }*/
                ans += 1;
            } else {
                if (a[i - 1].first % 2 == a[i + 1].first % 2) {
                    if (a[i - 1].first & 1) {
                        odd_block.push_back(a[i].second);
                    } else {
                        even_block.push_back(a[i].second);
                    }
                    ans += 2;
                } else {
                    ++other;
                }
            }
        }
    }
    ///cout << odd_block.size() << ' ' << other << ' ' << even_block.size() << endl;
    sort(odd_block.begin(), odd_block.end());
    sort(even_block.begin(), even_block.end());

    ans += other;
    for (ll i = 0; i < m - 1; ++i) {
        if (a[i].first != 0 && a[i + 1].first != 0) {
            if (a[i].first % 2 != a[i + 1].first % 2) {
                ++ans;
            }
        }
    }

    cout << odd << ' ' << even << endl;
    cout << odd_block.size() << ' ' << even_block.size() << endl;

    if (m == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (a[0].first == 0 || a.back().first == 0) {
        if (a.back().first != 0) {
            ll ans1 = 0;
            ///take
            if (a[1].first & 1) {
                if (a[0].second <= odd) {
                    odd -= a[0].second;
                }
            }
        }
    }

    for (ll i : odd_block) {
        if (odd >= i) {
            odd -= i;
            --ans;
        } else {
            break;
        }
    }
    for (ll i : even_block) {
        if (even >= i) {
            even -= i;
            --ans;
        } else {
            break;
        }
    }

    cout << ans << endl;
    return 0;
}

/**
5
0 0 0 0 0

5
0 2 0 4 0

5
1 3 2 0 4

**/
