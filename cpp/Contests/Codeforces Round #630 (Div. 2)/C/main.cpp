#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (char &i : s) {
        i -= 'a';
    }
    ll ans = n;
    ll block = n / k;
    vector <ll> cnt(26, 0);
    for (ll i = 0; i < k / 2; ++i) {
        ll l = i, r = k - i - 1;
        //cout << "l, r: " << l << ' ' << r << endl;
        for (ll j = 0; j < block; ++j) {
            cnt[s[l]]++, cnt[s[r]]++;
            l += k, r += k;
        }/*
        cout << "cnt: ";
        for (ll j = 0; j < 5; ++j) {
            cout << cnt[j] << ' ';
        }
        cout << endl;//*/
        ans -= *max_element(cnt.begin(), cnt.end());
        fill(cnt.begin(), cnt.end(), 0LL);
    }
    //cout << ans << endl;
    if (k & 1) {
        ll x = k / 2;
        for (ll i = 0; i < block; ++i) {
            cnt[s[x]]++;
            x += k;
        }/*
        cout << "cnt: ";
        for (ll j = 0; j < 5; ++j) {
            cout << cnt[j] << ' ';
        }
        cout << endl;//*/
        ans -= *max_element(cnt.begin(), cnt.end());
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}

/**
1
6 3
abaaba


**/
