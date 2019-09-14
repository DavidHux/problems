
using namespace std;

class Solution {
   public:
    int fastP(int a, int p) {
        int ret = 1;
        int base = a;
        while (p != 0) {
            if (p & 1) {
                ret *= base;
            }
            base *= base;
            p >>= 1;
        }
        return ret;
    }
    void test() {
        cout << fastP(7, 5);
    }
};