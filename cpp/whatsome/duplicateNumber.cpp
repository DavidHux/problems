#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() == 0)
            return -1;
        int fast = 0, slow = 0;
        while (true) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (fast == slow)
                break;
        }
        fast = 0;
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};

class TestCase {
   public:
    vector<int> getInput() {
        vector<int> i{1, 3, 4, 2, 2};
        return i;
    }
};
