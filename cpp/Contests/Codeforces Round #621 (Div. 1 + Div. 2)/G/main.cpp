#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    vector <ll> cnt(26, 0);
    for (char i : s) {
        cnt[i - 'a']++;
    }
    ll ans = *max_element(cnt.begin(), cnt.end());
    ll n = s.size();
    map <pair <char, char>, ll> a;
    ll q = 0;
    for (ll i = 1; i < n; ++i) {
        for (ll j = 0; j < n - i; ++j) {
            ++q;
            a[{s[j], s[j + i]}]++;
        }
    }
    for (auto i : a) {
        ans = max(ans, i.second);
    }
    cout << ans << endl;
    cout << q << endl;
    return 0;
}

/**


**/
