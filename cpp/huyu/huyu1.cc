#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int a[] = {0, 90, 990, 3590, 6090, 12090, 20840};

int main() {
    int n;
    int i = 0;
    int x;
    double r;
    cin >> n;
    while (i++ < n) {
        cin >> x;
        if (x > 85000) {
            r = double(x - 85000) * 0.45 + a[6];
        } else if (x > 60000) {
            r = double(x - 60000) * 0.35 + a[5];
        } else if (x > 40000) {
            r = double(x - 40000) * 0.3 + a[4];
        } else if (x > 30000) {
            r = double(x - 30000) * 0.25 + a[3];
        } else if (x > 17000) {
            r = double(x - 17000) * 0.2 + a[2];
        } else if (x > 8000) {
            r = double(x - 8000) * 0.1 + a[1];
        } else if (x > 5000) {
            r = double(x - 5000) * 0.03;
        } else {
            r = 0;
        }
        if (r - int(r) >= 0.5)
            r++;
        cout << int(r) << endl;
    }
    return 0;
}