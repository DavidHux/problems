#include <iostream>
#include <vector>

using namespace std;

int lastone(int n, int m) {
    int res = 0;
    for (int i = 2; i <= n; ++i) {
        res = (res + m) % i;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0);
    vector<int> w(n, 0);
    int su = 0, g = 0;
    double res;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> w[i];
    int la = lastone(n, m);
    for (int i = 0; i < n; ++i) {
        su += w[i];
        if (a[(i + la) % n] == 1)
            g += w[i];
    }
    res = (double)g / su;
    printf("%.5f\n", res);
    return 0;
}