//Kadane's Algorithm
//Time: O(n)
//Space: O(1)
//at each index,choose btw starting new subarr or extending prev

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0]; //assuming first element is starting subarr , handling -ve sub arr correctly
        int maxSum = nums[0]; 

        for(int i = 1; i < nums.size(); i++) { //start from 1 

        //start a new subarr , continue prev subarr and take whichever is larger 
            currentSum = max(nums[i], currentSum + nums[i]);
            
            //updating the global max,track of the best seen sum 
            maxSum = max(maxSum, currentSum); 
        }

        return maxSum;
    }
};