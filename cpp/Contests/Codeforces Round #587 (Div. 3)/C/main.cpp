#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

bool ans (ll x) {
    if (x)
        cout << "YES\n";
    else
        cout << "NO\n";
    exit (0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll x1, y1, x2, y2;
    ll x3, y3, x4, y4;
    ll x5, y5, x6, y6;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;

    if (x3 <= x1 && y3 <= y1 && x4 >= x2 && y4 >= y2)
        ans (0);
    if (x5 <= x1 && y5 <= y1 && x6 >= x2 && y6 >= y2)
        ans (0);

    if ((x3 <= x1 && x2 <= x4) || (y3 <= y1 && y2 <= y4)) {
        if (x3 <= x1 && x2 <= x4 && y3 <= y1)
            y1 = max (y1, y4);
        else if (x3 <= x1 && x2 <= x4 && y2 <= y4)
            y2 = min (y2, y3);
        else if (y3 <= y1 && y2 <= y4 && x3 <= x1)
            x1 = max (x1, x4);
        else if (y3 <= y1 && y2 <= y4 && x2 <= x4)
            x2 = min (x2, x3);
    }

    if (x5 <= x1 && y5 <= y1 && x6 >= x2 && y6 >= y2)
        ans (0);

    ans (1);
    return 0;
}
