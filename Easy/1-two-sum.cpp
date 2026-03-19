#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) { 
        //nums is the list of numbers and target is the number we want the sum to become

        // Loop through each number
        for (int i = 0; i < nums.size(); i++) {

            // Check it with every number after it
            for (int j = i + 1; j < nums.size(); j++) {

                // If sum matches target, return indices
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
