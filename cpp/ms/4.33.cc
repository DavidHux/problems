
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class tree_array {
   public:
    vector<int> vec;
    int N;
    tree_array(int n) {
        int len = 0;
        while (n >>= 1) len++;
        N = 1 << (len + 1);
        vec = vector<int>(N, 0);
    }
    inline int lowbit(int t) { return t & (-t); }
    int find(int i) {
        int res = 0;
        while (i > 0) {
            res += vec[i - 1];
            i -= lowbit(i);
        }
        return res;
    }
    void insert(int n) {
        for (int i = n; i <= N; i += lowbit(i)) vec[i - 1]++;
    }
    void pop(int n) {
        for (int i = n; i <= N; i += lowbit(i)) vec[i - 1]--;
    }
    void pop_front() {
        int i = N;
        while (vec[i - 1] > 0) {
            int temp = lowbit(i) >> 1;
            vec[i - 1]--;
            i -= temp;
            if (!vec[i - 1]) i -= temp;
        }
    }
};