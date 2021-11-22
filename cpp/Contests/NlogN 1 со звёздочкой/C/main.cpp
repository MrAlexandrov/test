#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int mn = (n + 1) / 2;
    int ans = (mn + m - 1) / m * m;
    if (ans > n) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}

/**
n / 2 ... n

**/
