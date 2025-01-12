class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 != 0) return false; // Odd-length strings cannot be valid
        
        int openCount = 0, unlockedCount = 0;

        // Pass 1: Left to Right
        for (int i = 0; i < s.size(); ++i) {
            if (locked[i] == '0') {
                unlockedCount++;
            } else if (s[i] == '(') {
                openCount++;
            } else { // s[i] == ')'
                if (openCount > 0) {
                    openCount--;
                } else if (unlockedCount > 0) {
                    unlockedCount--;
                } else {
                    return false;
                }
            }
        }

        // Reset for the second pass
        int closeCount = 0;
        unlockedCount = 0;

        // Pass 2: Right to Left
        for (int i = s.size() - 1; i >= 0; --i) {
            if (locked[i] == '0') {
                unlockedCount++;
            } else if (s[i] == ')') {
                closeCount++;
            } else { // s[i] == '('
                if (closeCount > 0) {
                    closeCount--;
                } else if (unlockedCount > 0) {
                    unlockedCount--;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
