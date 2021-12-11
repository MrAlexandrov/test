#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << A + (D > B ? (D - B) * C : 0);
    return 0;
}

/**


**/
