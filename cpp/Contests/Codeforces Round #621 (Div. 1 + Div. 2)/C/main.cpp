#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 26;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    ll n = s.size();
    vector <ll> one(N, 0);
    vector <vector <ll>> two(N, vector <ll>(N, 0));
    for (ll i = 0; i < n; ++i) {
        ll k = s[i] - 'a';
        for (ll j = 0; j < N; ++j) {
            two[j][k] += one[j];
        }
        ++one[k];
    }
    ll ans = 0;
    ans = max(ans, *max_element(one.begin(), one.end()));
    for (ll i = 0; i < N; ++i) {
        ans = max(ans, *max_element(two[i].begin(), two[i].end()));
    }
    cout << ans << endl;
    return 0;
}

/**


**/
