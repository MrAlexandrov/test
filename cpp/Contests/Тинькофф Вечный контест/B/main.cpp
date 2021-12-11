#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll N;
    cin >> N;
    ll ans = 0;
    for (ll i = 1; i < N; i <<= 1, ans++);
    cout << ans;
    return 0;
}

/**


**/
