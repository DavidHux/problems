
#include <iostream>

using namespace std;

int main() {
    int x, y;
    int z;
    while (cin >> x >> y) {
        if (x > -y && x >= y)
            z = (2 * x - 1) * (2 * x - 1) + y - 1 + x;
        else if (x > y && x <= -y)
            z = (-2 * y + 1) * (-2 * y + 1) - 1 + y + x;
        else if (x < y && x >= -y)
            z = 4 * y * y - x - y;
        else
            z = 4 * x * x - x - y;
        cout<<z<<endl;
    }
    return 0;
}