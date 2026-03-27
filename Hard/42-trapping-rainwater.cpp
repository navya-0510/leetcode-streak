class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;

        //these track the highest wall we hv seen so far
        int leftMax = 0, rightMax = 0;

        int water = 0;

        //process until both pointers meet
        while (left < right) {

            //always move the side with the smaller height
            if (height[left] < height[right]) {

                //if cur bar is taller than leftMax, update it
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } 
                else {
                    //otherwise, water can be trapped here
                    water += leftMax - height[left];
                }

                left++; //move inward
            } 
            else {

                //same logic for the ryt side
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } 
                else {
                    water += rightMax - height[right];
                }

                right--; //move inward
            }
        }

        return water;
    }
};