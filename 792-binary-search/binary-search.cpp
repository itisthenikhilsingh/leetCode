class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st=0;
        int lt=nums.size()-1;
        while(st<=lt)
        {
            int mid= st + (lt-st)/2;

            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                lt = mid-1;
            }
            else st = mid+1;
        }
        return -1;
        
    }
};