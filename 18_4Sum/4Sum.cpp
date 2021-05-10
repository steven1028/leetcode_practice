#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        vector<vector<int>> fourSum(vector<int> &nums, int target) {
            sort(begin(nums), end(nums));
            return kSum(nums, target, 0, 4);
        };

        vector<vector<int>> kSum(vector<int> &nums, int target, int start, int k) {
            vector<vector<int>> results;
            if (start == nums.size()) {
                return results;
            }
            if (k == 2) {
                return twoSum(nums, target, start);
            }
            for (int i = start; i < nums.size(); ++i) {
                if (i == start || nums[i-1] != nums[i]) {
                    for (auto &set: kSum(nums, target - nums[i], i + 1, k - 1)) {
                        results.push_back({nums[i]});
                        results.back().insert(end(results.back()), begin(set), end(set));
                    }
                }
            }
            return results;
        };

        vector<vector<int>> twoSum(vector<int> &nums, int target, int start) {
            vector<vector<int>> results;
            int lo = start, hi = nums.size() - 1;
            while (lo < hi) {
                int sum = nums[lo] + nums[hi];
                if (sum < target || lo > start && nums[lo] == nums[lo - 1]) {
                    lo++;
                } else if (sum > target || hi < nums.size() - 1 && nums[hi] == nums[hi + 1]) {
                    hi--;
                } else {
                    results.push_back({ nums[lo++], nums[hi--] });
                }
            }
            return results;
        };
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {1,0,-1,0,-2,2};
    Solution solution;
    vector<vector<int>> results = solution.fourSum(nums, 0);
    for (auto i: results){
        for (auto j: i){
            cout << j << ' ';
        }
        cout << endl;
    }
    return 0;
}

