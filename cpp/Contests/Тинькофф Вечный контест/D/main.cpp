#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector <vector <ll>> a(20);
    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        reverse(x.begin(), x.end());
        for (ll j = 0, m = 1; j < (int)x.size(); ++j, m *= 10) {
            if (x[j] != '9') {
                a[j].push_back(('9' - x[j]) * m);
            }
        }
    }
    for (int i = 0; i < 20; ++i) {
        sort(a[i].rbegin(), a[i].rend());
    }
    ll ans = 0;
    for (int i = 19; k > 0 && i >= 0; --i) {
        for (int j = 0; k > 0 && j < (int)a[i].size(); ++j) {
            ans += a[i][j];
            --k;
        }
    }
    cout << ans;
    return 0;
}

/**
7 0
2
22
343
9329
239
329
99999

**/
