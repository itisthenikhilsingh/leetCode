class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
while (low < high) {
            int mid = low + (high - low) / 2;

            // If the middle element is greater than the last element,
            // the minimum must be in the right half
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            // Otherwise, the minimum is in the left half (including mid)
            else {
                high = mid;
            }
        }
        return nums[low];
        
    }
};