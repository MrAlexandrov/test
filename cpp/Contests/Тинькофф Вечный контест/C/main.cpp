#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n, t, k;
    cin >> n >> t;
    vector <int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    cin >> k;
    k = a[k - 1];
    int ans = a.back() - a.front();
    if (a.back() - k > t && k - a.front() > t) {
        ans += min(a.back() - k, k - a.front());
    }
    cout << ans;
    return 0;
}

/**


**/
