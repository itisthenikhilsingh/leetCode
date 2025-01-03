class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        // Store original indices
        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); ++i) {
            indexedNums.push_back({nums[i], i});
        }

        // Sort based on values
        sort(indexedNums.begin(), indexedNums.end());

        int i = 0, j = indexedNums.size() - 1;

        // Two-pointer approach
        while (i < j) {
            int sum = indexedNums[i].first + indexedNums[j].first;
            if (sum == target) {
                return {indexedNums[i].second, indexedNums[j].second};
            } else if (sum < target) {
                ++i;
            } else {
                --j;
            }
        }

        return {-1, -1};
    }
};
