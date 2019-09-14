#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct tree {
    int l, r, sum;
};

tree node[200002];

void build(vector<int>& a, int i, int l, int r) {
    node[i].l = l;
    node[i].r = r;
    if (l == r) {
        node[i].sum = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(a, i << 1, l, mid);
    build(a, (i << 1) | 1, mid + 1, r);
    node[i].sum = node[i << 1].sum + node[(i << 1) | 1].sum;
}

int sum(int i, int l, int r) {
    if (node[i].l == l && node[i].r == r)
        return node[i].sum;
    int mid = (node[i].l + node[i].r) / 2;
    if (r <= mid)
        return sum(i << 1, l, r);
    else if (l > mid)
        return sum((i << 1) | 1, l, r);
    else
        return sum(i << 1, l, mid) + sum((i << 1) | 1, mid + 1, r);
}

int main() {
    int t, k;
    cin >> t >> k;
    int ma = 0;
    int a, b;
    vector<vector<int>> q;
    for (int i = 0; i < t; ++i) {
        cin >> a >> b;
        ma = max(a, max(ma, b));
        q.push_back({a, b});
    }
    vector<int> dp(100001, 0);
    for (int i = 1; i < k; ++i)
        dp[i] = 1;
    dp[k] = 2;
    for (int i = k + 1; i <= ma; ++i) {
        if (k == 0)
            dp[i] = 2 * dp[i - 1];
        else {
            dp[i] = dp[i - 1] + dp[i - k];
        }
    }
    build(dp, 1, 1, ma);
    for (int i = 0; i < q.size(); ++i) {
        // int su = 0;
        // for(int j = q[i][0];j<=q[i][1];++j)
        //     su += dp[j];

        cout << sum(1, q[i][0], q[i][1]) << endl;
    }
}