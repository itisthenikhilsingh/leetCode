class Solution {
public:
    // Helper function: Checks if we can partition the string `s` (which represents i*i)
    // starting from `index`, so that the sum of partitions plus `sum` equals target.
    bool isValidPartition(const string &s, int index, int target, int sum, vector<vector<int>> &memo) {
        // Base case: if we've reached the end of the string,
        // check if we've exactly reached the target sum.
        if (index == s.size())
            return sum == target;
        
        // If we have computed this state before, return the stored result.
        if (memo[index][sum] != -1)
            return memo[index][sum];
        
        long long num = 0;
        bool valid = false;
        // Try every possible partition by extending the current number.
        for (int j = index; j < s.size(); j++) {
            num = num * 10 + (s[j] - '0');
            // Only explore further if adding num does not exceed the target.
            if (sum + num <= target && isValidPartition(s, j + 1, target, sum + num, memo)) {
                valid = true;
                break;  // Found a valid partition, so no need to try further.
            }
        }
        // Memorize the result for current state (index, sum).
        memo[index][sum] = valid;
        return valid;
    }
    
    // For a given integer i, this function checks if i*i can be partitioned into
    // contiguous substrings that sum up exactly to i.
    bool isTrue(int i) {
        // Convert i*i into a string.
        string s = to_string((long long)i * i);
        // Create a memoization table:
        // Dimensions: [s.size()+1] x [target (i) + 1]. 
        // We use -1 to indicate an uncomputed state.
        vector<vector<int>> memo(s.size() + 1, vector<int>(i + 1, -1));
        return isValidPartition(s, 0, i, 0, memo);
    }
    
    // Main function to compute the punishment number for n.
    int punishmentNumber(int n) {
        int ans = 0;
        // For every i from 1 to n, if i passes the partition test,
        // add i*i to the final answer.
        for (int i = 1; i <= n; i++) {
            if (isTrue(i)) {
                ans += i * i;
            }
        }
        return ans;
    }
};
