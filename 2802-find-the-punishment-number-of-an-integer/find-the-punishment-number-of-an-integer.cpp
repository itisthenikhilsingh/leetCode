#include <bits/stdc++.h>
using namespace std;

// Function to check if the square of `root` (i.e. p) can be partitioned
// into contiguous parts whose sum equals `root`.
bool valid(int root, int p) {
    string s = to_string(p);
    // Recursive lambda for exploring partitions.
    auto go = [&](auto&& go, int i, int sum, int curr) -> bool {
        if (i >= s.size())
            return sum == root;
        int x = s[i] - '0';
        // Option 1: Extend the current segment.
        bool option1 = go(go, i + 1, sum - curr + (10 * curr + x), 10 * curr + x);
        // Option 2: Start a new segment with the current digit.
        bool option2 = go(go, i + 1, sum + x, x);
        return option1 || option2;
    };
    return go(go, 0, 0, 0);
}

// Precomputed cumulative punishment array.
int punishment[1001];

// Precomputation block that runs before main() or any instance is created.
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Compute punishment[i] for each i = 1 to 1000.
    for (int i = 1; i <= 1000; i++) {
        if (valid(i, i * i))
            punishment[i] = i * i;
        else
            punishment[i] = 0;
    }
    // Build the cumulative sum array.
    for (int i = 1; i <= 1000; i++) {
        punishment[i] += punishment[i - 1];
    }
    return 0;
}();

class Solution {
public:
    int punishmentNumber(int n) {
        return punishment[n];
    }
};
