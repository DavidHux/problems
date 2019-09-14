#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> dp;
vector<int> m;
int n, k;

int dfs(int i, int k) {
    if (k == 0) return 0;
    if (dp[i][k] != 0)
        return dp[i][k];
    if (n - i == k) {
        dp[i][k] = k;
        return k;
    }
    set<int> s;
    int res = 0;
    if (k == 1) {
        s.insert(m.begin() + i, m.end());
        dp[i][k] = s.size();
        return s.size();
    }
    for (int a = i; a <= n - k; ++a) {
        s.insert(m[a]);
        int r = dfs(a + 1, k - 1);
        res = max(r + int(s.size()), res);
    }
    dp[i][k] = res;
    return res;
}

int main() {
    cin >> n >> k;
    dp = vector<vector<int>>(n, vector<int>(k + 1, 0));
    m = vector<int>(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> m[i];
    cout << dfs(0, k);
    return 0;
}