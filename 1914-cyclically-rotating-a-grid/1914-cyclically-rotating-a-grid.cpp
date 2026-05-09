class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int rowSize = grid.size();
        int colSize = grid[0].size();

        int startRow = 0;
        int startCol = 0;
        int endCol = colSize - 1;
        int endRow = rowSize - 1;

        while (startRow < endRow && startCol < endCol) {

            int perimeter =
                2 * ((endRow - startRow + 1) +
                     (endCol - startCol + 1)) - 4;

            int rotations = k % perimeter;

            while (rotations--) {

                int temp = grid[startRow][endCol];

                // top row
                for (int col = endCol - 1; col >= startCol; col--) {
                    swap(temp, grid[startRow][col]);
                }

                // left column
                for (int row = startRow + 1; row <= endRow; row++) {
                    swap(temp, grid[row][startCol]);
                }

                // bottom row
                for (int col = startCol + 1; col <= endCol; col++) {
                    swap(temp, grid[endRow][col]);
                }

                // right column
                for (int row = endRow - 1; row >= startRow; row--) {
                    swap(temp, grid[row][endCol]);
                }
            }

            startRow++;
            startCol++;
            endRow--;
            endCol--;
        }

        return grid;
    }
};