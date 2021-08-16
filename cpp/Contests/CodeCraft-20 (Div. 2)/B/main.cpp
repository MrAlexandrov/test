#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    set <pair<string, ll>> ans;
    for (ll i = 0; i < n; ++i) {
        string t = s;
        if ((i + n) % 2 == 0) {
            reverse(t.begin(), t.begin() + i);
        }
        reverse(t.begin() + i, t.end());
        reverse(t.begin(), t.end());
        ans.insert({t, i + 1});
    }
    /*
    for (auto i : ans) {
        cout << i.first << ' ' << i.second << endl;
    }
    //*/
    cout << ans.begin() -> first << '\n' << ans.begin() -> second << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/**
lfpbavjsm
1 lfpbavjsm
2 fpbavjsml
3 pbavjsmfl
4 bavjsmlfp
5 avjsmbpfl
6 vjsmlfpba
7 jsmvabpfl
8 smlfpbavj
9 msjvabpfl

0
lfpbavjsm
avjsmbpfl 5
bavjsmlfp 4
fpbavjsml 2
jsmvabpfl 7
lfpbavjsm 1
msjvabpfl 9
pbavjsmfl 3
smlfpbavj 8
vjsmlfpba 6

**/
