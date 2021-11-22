#include <iostream>
using namespace std;


int main() {
    int a = 0, b = 0, x;
    int t;
    cin >> t;
    a += t;
    cin >> t;
    a += t;
    cin >> t;
    a += t;

    cin >> t;
    b += t;
    cin >> t;
    b += t;
    cin >> t;
    b += t;

    cin >> x;
    int an = (a + 5 - 1) / 5;
    int bn = (b + 10 - 1) / 10;
    if (an + bn <= x) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

/**


**/
