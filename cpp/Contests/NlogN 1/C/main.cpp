#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b) {
        if (b == c) {
            cout << 3 << endl;
        } else {
            cout << 2 << endl;
        }
    } else {
        if (b == c) {
            cout << 2 << endl;
        } else if (a == c) {
            cout << 2 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}

/**


**/
