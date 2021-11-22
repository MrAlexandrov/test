#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << n - 1 << endl;
    } else {
        cout << n << endl;
    }
    return 0;
}

/**
2 - 1
3 - 3

1 > 2
2 > 3
3 > 1

4
1 > 2
1 > 4
2 > 3
2 > 4
3 > 1
3 > 4


**/
