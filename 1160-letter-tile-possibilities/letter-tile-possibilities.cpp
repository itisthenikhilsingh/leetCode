class Solution { 
public:
    void backtrack(unordered_map<char, int>& freq, int& count) {
        for (auto& [ch, f] : freq) {
            if (f > 0) { 
                count++;  // Count current sequence
                f--;  // Use this letter
                backtrack(freq, count);
                f++;  // Backtrack
            }
        }
    }

    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for (char c : tiles) freq[c]++;

        int count = 0;
        backtrack(freq, count);
        return count;
    }
};
