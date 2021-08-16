#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n, m;

void ins() {
    cout << "inside ?" << endl;
}

void bord() {
    cout << "border ?" << endl;
}

void end() {
    cout << "End of program" << endl;
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> m;
    ll x, y;
    cin >> x >> y;
    ins();
    while (true) {
        char s;
        cin >> s;
        if (s == 'R') {
            ++y;
        } else if (s == 'U') {
            --x;
        } else if (s == 'L') {
            --y;
        } else if (s == 'D') {
            ++x;
        }
        if (x < 1LL || y < 1LL || n < x || m < y) {
            end();
        } else if (1LL < x && x < n && 1LL < y && y < m) {
            ins();
        } else {
            bord();
        }
    }
    return 0;
}

/**


**/
