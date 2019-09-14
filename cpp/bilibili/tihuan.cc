#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> dp;
string a, b;
int h(int i, int j){
    if(i == a.size() && j == b.size())
    return 0;
    if(i == a.size()){
        return b.size() - j;
    }
    if(j == b.size()){
        return a.size() - i;
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int res = 0x7fffffff;
    int t = a[i] == b[j] ? 0:1;
    res = min(h(i+1, j+1)+t, min(h(i, j+1)+1, h(i+1, j)+1));
    dp[i][j] = res;
    return res;
}

int main() {
    cin >> a>>b;
    dp = vector<vector<int>>(a.size(), vector<int>(b.size(), -1));
    cout << h(0, 0) << endl;
    return 0;
}