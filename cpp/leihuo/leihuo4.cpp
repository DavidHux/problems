
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dpp(vector<vector<int> >& d, int curlife, int pos, vector<int>& x, vector<int>& y, vector<int>& z) {
    // cout<<pos<<endl;
    if (pos == x.size())
        return 0;
    if(d[curlife][pos] != -1)
        return d[curlife][pos];
    int a, b;
    if (curlife - z[pos] <= 0)
        a = 0;
    else 
        a = dpp(d, curlife - z[pos], pos + 1, x, y, z);
    if (curlife - x[pos] <= 0)
        b = y[pos];
    else {
        b = dpp(d, curlife - x[pos], pos + 1, x, y, z) + y[pos];
    }
    int ret = max(a, b);
    d[curlife][pos] = ret;
    return ret;
}

int main() {
    int n, life;
    int xx, yy, zz;
    while (cin >> n) {
        cin >> life;
        vector<int> x, y, z;
        vector<vector<int> > d(life + 1, vector<int>(n, -1));
        for (int i = 0; i < n; ++i) {
            cin >> xx;
            x.push_back(xx);
            cin >> yy;
            y.push_back(yy);
            cin >> zz;
            z.push_back(zz);
        }
        cout << dpp(d, life, 0, x, y, z) << endl;
    }
    return 0;
}