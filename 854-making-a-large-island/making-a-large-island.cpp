class Solution {
public:
    /**
     * @brief Finds the size of the largest island after changing at most one 0
     * to 1.
     *
     * @param grid A 2D vector representing the binary matrix.
     * @return int The size of the largest island.
     */
    int largestIsland(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        int maxSize = 0;
        vector<int> sizes{0, 0}; // Initialize sizes with two zeros

        // Paint each island with a unique id and store their sizes
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    sizes.push_back(paint(grid, i, j, sizes.size()));
                }
            }
        }

        // Check each cell to find the maximum island size by changing one 0 to
        // 1
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    const unordered_set<int> neighborIds{
                        getId(grid, i + 1, j), getId(grid, i - 1, j),
                        getId(grid, i, j + 1), getId(grid, i, j - 1)};
                    maxSize = max(maxSize, 1 + getSize(neighborIds, sizes));
                }
            }
        }

        return maxSize == 0 ? m * n : maxSize;
    }

private:
    /**
     * @brief Paints the island with a unique id and returns its size.
     *
     * @param grid A reference to the binary matrix.
     * @param i The row index.
     * @param j The column index.
     * @param id The unique id to paint the island with.
     * @return int The size of the painted island.
     */
    int paint(vector<vector<int>>& grid, int i, int j, int id) {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() ||
            grid[i][j] != 1)
            return 0;
        grid[i][j] = id;
        return 1 + paint(grid, i + 1, j, id) + paint(grid, i - 1, j, id) +
               paint(grid, i, j + 1, id) + paint(grid, i, j - 1, id);
    }

    /**
     * @brief Gets the id of the cell at (i, j).
     *
     * @param grid A reference to the binary matrix.
     * @param i The row index.
     * @param j The column index.
     * @return int The id of the cell or 0 if out of bounds.
     */
    int getId(const vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
            return 0;
        return grid[i][j];
    }

    /**
     * @brief Calculates the total size of islands connected to a set of
     * neighbor ids.
     *
     * @param neighborIds A set of neighboring island ids.
     * @param sizes A vector containing sizes of islands indexed by their ids.
     * @return int The total size of connected islands.
     */
    int getSize(const unordered_set<int>& neighborIds,
                const vector<int>& sizes) {
        int size = 0;
        for (const int neighborId : neighborIds)
            size += sizes[neighborId];
        return size;
    }
};