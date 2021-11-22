#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve() {
    ll n;
    cin >> n;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <ll> B, R;
    for (ll i = 0; i < n; ++i) {
        char x;
        cin >> x;
        if (x == 'B') {
            B.push_back(a[i]);
        } else {
            R.push_back(a[i]);
        }
    }
    sort(B.begin(), B.end());
    sort(R.begin(), R.end());

    if (!B.empty()) {
        if (B[0] < 1) {
            return false;
        }
        ll d = B[0] - 1;
        for (ll i = 0; i < (int)B.size(); ++i) {
            B[i] -= d;
        }
        for (ll i = 0; i < (int)B.size(); ++i) {
            a[i] = B[i];
        }
    }
    if (!R.empty()) {
        if (R.back() > n) {
            return false;
        }
        ll d = R.back() - n;
        for (ll i = 0; i < (int)R.size)
    }

    if (B[0] < 1 || R.back() > n) {
        return false;
    }
    ll d = B[0] - 1;
    for (ll i = 0; i < (int)B.size(); ++i) {
        B[i] -= d;
    }
    d = R.back() - n;
    for (ll i = 0; i < (int)R.size(); ++i) {
        R[i] -= d;
    }
    for (ll i = 0; i < (int)B.size(); ++i) {
        a[i] = B[i];
    }
    for (ll i = (int)B.size(); i < n; ++i) {
        a[i] = R[i - (int)B.size()];
    }
    sort(a.begin(), a.end());
    for (ll i = 0; i < n; ++i) {
        if (a[i] != i + 1) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll T;
    cin >> T;
    while (T--) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
    return 0;
}

/**


**/
