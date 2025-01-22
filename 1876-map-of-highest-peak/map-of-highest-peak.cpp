class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row = isWater.size();
        int col = isWater[0].size();
        vector<vector<int>> ans(row, vector<int>(col, -1)); // Initialize all cells as unvisited (-1)
        queue<pair<int, int>> q;

        // Initialize the queue with all water cells and set their height to 0
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Directions for moving up, down, left, and right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // BFS to propagate heights
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;

                // Check if the neighbor is within bounds and unvisited
                if (nx >= 0 && ny >= 0 && nx < row && ny < col && ans[nx][ny] == -1) {
                    ans[nx][ny] = ans[x][y] + 1; // Set height as one more than the current cell
                    q.push({nx, ny}); // Add to the queue for further processing
                }
            }
        }

        return ans;
    }
};
