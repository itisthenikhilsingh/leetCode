class Solution {
public:
    // Recursive helper to check if valid partition exists.
    bool isValidPartition(string s, int index, int target, int sum) {
        if (index == s.size()) 
            return sum == target;
        
        int num = 0;
        for (int j = index; j < s.size(); j++) {
            num = num * 10 + (s[j] - '0');
            if (num + sum <= target && isValidPartition(s, j + 1, target, sum + num))
                return true;
        }
        return false;
    }

    // Check if i*i can be partitioned into pieces that sum to i.
    bool isTrue(int i) {
        string sqrStr = to_string(i * i);
        return isValidPartition(sqrStr, 0, i, 0);
    }

 
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (isTrue(i)) {
                ans += (i * i);
            }
        }
        return ans;
    }
};
