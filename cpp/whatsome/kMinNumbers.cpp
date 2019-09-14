#include <algorithm>
#include <vector>

using namespace std;

class TestCase {
   public:
    vector<int> getInput() {
        vector<int> i{1, 3, 4, 2, 2};
        return i;
    }
};

class Solution {
   public:
    vector<int> kMinNums(vector<int>& nums, int k) {
        if (nums.size() == 0 || k == 0)
            return nums;
        if (nums.size() <= k)
            return nums;
        vector<int> ret(nums.begin(), nums.begin() + k);
        make_heap(ret.begin(), ret.end());
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] < ret.front()) {
                pop_heap(ret.begin(), ret.end());
                ret.back() = nums[i];
                push_heap(ret.begin(), ret.end());
            }
        }
        return ret;
    }
    void test(){
        TestCase ts;
        auto in = ts.getInput();
        auto ret = kMinNums(in, 3);
        for(auto i:ret){
            cout<<i<<" ";
        }
    }
};

