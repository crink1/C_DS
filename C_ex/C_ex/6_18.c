//bool judge(int** grid, int x, int y, int m, int n)
//{
//    if (x < 0 || y < 0 || x >= m || y >= n)
//    {
//        return false;
//    }
//    if (grid[x][y] != 0)
//    {
//        return true;
//    }
//    grid[x][y] = -1;
//    bool ret1 = judge(grid, x - 1, y, m, n);
//    bool ret2 = judge(grid, x + 1, y, m, n);
//    bool ret3 = judge(grid, x, y - 1, m, n);
//    bool ret4 = judge(grid, x, y + 1, m, n);
//    return ret1 && ret2 && ret3 && ret4;
//}
//
//int closedIsland(int** grid, int gridSize, int* gridColSize) {
//    int count = 0;
//
//    for (int i = 0; i < gridSize; i++)
//    {
//        for (int j = 0; j < gridColSize[0]; j++)
//        {
//            if (grid[i][j] == 0 && judge(grid, i, j, gridSize, gridColSize[0]))
//            {
//                count++;
//            }
//        }
//    }
//    return count;
//}