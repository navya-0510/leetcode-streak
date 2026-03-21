class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for(int i = 0; i < nums.size(); i++) {
            //if current index is not reachable
            if(i > maxReach) return false;

            //update the farthest reachable index
            maxReach = max(maxReach, i + nums[i]);

            //if we can reach last index
            if(maxReach >= nums.size() - 1) return true;
        }

        return true;
    }
};