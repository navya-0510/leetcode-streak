class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        //i-last elem of nums1's valid part
        int i = m - 1;
        
        //j-last elem of nums2
        int j = n - 1;
        
        //k-last index of nums1 (total size)
        int k = m + n - 1;

        //traverse both arrays from the end
        while (i >= 0 && j >= 0) {
            
            //place the larger elem at the end
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--; //move nums1 pointer
            } else {
                nums1[k] = nums2[j];
                j--; //move nums2 pointer
            }
            k--; //move position pointer
        }

        //if nums2 still has elem left
        //(nums1 leftover elem are already in correct place)
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};