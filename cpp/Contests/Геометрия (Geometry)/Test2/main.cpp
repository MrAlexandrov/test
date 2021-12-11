#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b) {
    int t;
    while (b != 0) {
        t = a;
        a = b;
        b = t % b;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int a = 5;
    int b = 10;
    cout << gcd(a, b);
    return 0;
}

/**


**/
