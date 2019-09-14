#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;
        if (haystack.size() == 0) return -1;
        vector<int> next = getNext(needle);
        for(auto x:next)
            cout<<x<<' ';
        cout<<endl;
        int i = 0, hs = haystack.size();  // 主串的位置
        int j = 0, ns = needle.size();  // 模式串的位置
        while (i < hs && j < ns) {
            if (j == -1 || haystack[i] == needle[j]) {  // 当j为-1时，要移动的是i，当然j也要归0
                i++;
                j++;
            } else {
                j = next[j];  // j回到指定位置
            }
        }
        if (j == needle.size()) {
            return i - j;
        } else {
            return -1;
        }
        return -1;
    }
    vector<int> getNext(string p) {
        vector<int> next(p.size(), 0);
        next[0] = -1;
        int j = 0;
        int k = -1;
        while (j < p.size() - 1) {
            if (k == -1 || p[j] == p[k]) {
                if (p[++j] == p[++k]) {  // 当两个字符相等时要跳过
                    next[j] = next[k];
                } else {
                    next[j] = k;
                }
            } else {
                k = next[k];
            }
        }
        return next;
    }
};

int main(){
    string a = "ssssssssa";
    string b = "sssssb";
    Solution s;
    cout<<s.strStr(a, b);
}