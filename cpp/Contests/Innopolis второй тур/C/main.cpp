#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

bool inter (ll x1, ll y1, ll x2, ll y2) {
    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }
    return (y1 < x2 && x2 < y2);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);

    return 0;
}

/**


**/
