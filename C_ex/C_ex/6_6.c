//bool equal(int row, int col, const int** grid, int gridSize) {
//    for (int i = 0; i < gridSize; i++) {
//        if (grid[row][i] != grid[i][col]) {
//            return false;
//        }
//    }
//    return true;
//}
//
//int equalPairs(int** grid, int gridSize, int* gridColSize) {
//    int res = 0;
//    for (int row = 0; row < gridSize; row++) {
//        for (int col = 0; col < gridSize; col++) {
//            if (equal(row, col, grid, gridSize)) {
//                res++;
//            }
//        }
//    }
//    return res;
//}