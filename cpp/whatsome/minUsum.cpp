#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
	 *	正数数组中的最小不可组成和
	 *	输入：正数数组arr
	 *	返回：正数数组中的最小不可组成和
	 */
    int getFirstUnFormedNum(vector<int> arr, int len) {
        sort(arr.begin(), arr.end());
        vector<pair<int, int>> v;
        v.push_back({arr[0], arr[0]});
        for (int i = 1; i < arr.size(); ++i) {
            for (int i = 0; i < v.size(); ++i) {
                cout << v[i].first << ' ' << v[i].second<<' ';
            }
            cout << endl;
            if (arr[i] > v[0].second + 1)
                return v[0].second + 1;
            vector<pair<int, int>> v2;
            v2.push_back({arr[i], arr[i]});
            for (int j = 0; j < v.size(); j++) {
                v2.push_back({v[j].first + arr[i], v[j].second + arr[i]});
            }
            for (int j = 0; j < v2.size(); j++) {
                for (int k = 0; k < v.size(); k++) {
                    if (v2[j].first <= v[k].second + 1 && v2[j].second >= v[k].first - 1) {
                        v[k].first = min(v2[j].first, v[k].first);
                        v[k].second = max(v2[j].second, v[k].second);
                        for (int aa = k + 1; aa < v.size(); aa++) {
                            if (v[aa].first <= v[aa - 1].second + 1) {
                                v[aa - 1].second = max(v[aa].second, v[aa - 1].second);
                                v.erase(v.begin() + aa);
                                --aa;
                            }
                        }
                        goto l1;
                    }
                }
                v.push_back(v2[j]);
            l1:;
            }
        }
        return v[0].second + 1;
    }
};
int main() {
    Solution s;
    vector<int> inp = {8, 10, 2, 10, 4, 8, 6, 3, 5, 7, 10};
    int ret = s.getFirstUnFormedNum(inp, 11);
    cout << ret << endl;
    return 0;
}