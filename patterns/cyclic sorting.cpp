#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            int correctIndex = nums[i] - 1;
            if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[correctIndex]) {
                swap(nums[i], nums[correctIndex]);
            } else {
                i++;
            }
        }

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != j + 1) {
                return j + 1;
            }
        }

        return nums.size() + 1;
    }
};

int main() {
    // You can test with different inputs here
    vector<int> nums = {3, 4, -1, 1};

    cout << "Original array: ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    Solution sol;
    int result = sol.firstMissingPositive(nums);

    cout << "First Missing Positive: " << result << endl;

    return 0;
}
