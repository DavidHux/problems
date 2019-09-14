#include <iostream>
// #include <vector>
// #include <string>

using namespace std;

int main() {
    int a;
    cin >> a;
    int temp = 0;
    int res = 0;
    for (int i = 1; i <= a; ++i) {
        temp += i;
        if (temp > a)
            break;
        if ((a - temp) % i == 0)
            res++;
    }
    cout << res << endl;
    return 0;
}