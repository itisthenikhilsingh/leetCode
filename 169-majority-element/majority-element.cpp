class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj=nums[0];
        int frq=1;

        for(int i = 1; i < nums.size(); i++)
        {
            if(frq==0) 
            { 
                maj=nums[i]; 
                frq++;
            }
            else if(nums[i]==maj)
            {
                frq++;
            }
            else frq--;
        }
        return maj;
        
        
    }
};