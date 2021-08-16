#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 5e2 + 8;

ll n;
ll ans[N][N];

void no() {
    cout << "-1\n";
    exit(0);
}

ll ans3[3][3] = {
    {9, 1, 5},
    {6, 2, 3},
    {7, 8, 4}
};

ll ex[4][4] = {
    {1, 2, 3, 4},
    {10, 14, 13, 5},
    {11, 12, 6, 15},
    {16, 7, 9, 8}
};

ll paint(ll x, ll y, ll col) {
    ll k = x + y + 1;
    if (x == 0) {
        while (x < k) {
            ans[x][y] = col++;
            ++x;
        }
        --x;
        --col;
        while (y >= 0) {
            ans[x][y] = col++;
            --y;
        }
    } else {
        while (y < k) {
            ans[x][y] = col++;
            ++y;
        }
        --y;
        --col;
        while (x >= 0) {
            ans[x][y] = col++;
            --x;
        }
    }
    return col;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    if (n < 3) {
        no();
    }
    if (n == 3) {
        for (ll i = 0; i < 3; ++i) {
            for (ll j = 0; j < 3; ++j) {
                cout << ans3[i][j] << ' ';
            }
            cout << '\n';
        }
        return 0;
    }
    ll rasn = n * n - 16;
    for (ll i = 0; i < 4; ++i) {
        for (ll j = 0; j < 4; ++j) {
            ans[i][j] = ex[i][j] + rasn;
        }
    }
    bool x = true;
    ll col = 1;
    for (ll i = n - 1; i >= 4; --i) {
        if (x) {
            col = paint(i, 0, col);
        } else {
            col = paint(0, i, col);
        }
        x = !x;
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

/**


**/
