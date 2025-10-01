class Result
{
    public static int dfs(int i, int j, int rows, int col, List<List<int>> matrix)
    {

        if (i < 0 || i >= rows || j < 0 || j >= col || matrix[i][j] == 0) return 0;

        int[] x_neib = { -1, -1, -1, 0, 0, 1, 1, 1 };
        int[] y_neib = { -1, 0, 1, -1, 1, -1, 0, 1 };

        matrix[i][j] = 0;
        int area_count = 1;

        for (int k = 0; k < 8; k++)
        {
            area_count += dfs(i + x_neib[k], j + y_neib[k], rows, col, matrix);
        }

        return area_count;
    }

    public static int connectedCell(List<List<int>> matrix)
    {

        int rows = matrix.Count;
        int columns = matrix[0].Count;

        int larg_area = 0;
        int curr_area = 0;

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
            {
                if (matrix[i][j] == 1)
                {
                    curr_area = dfs(i, j, rows, columns, matrix);
                    if (curr_area > larg_area) larg_area = curr_area;
                }
            }
        return larg_area;
    }
}