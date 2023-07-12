#include <iostream>
#include <vector>

void dfs(const int& row, const int& col, int& n, int& m, std::vector<std::vector<bool>>& visited)
{
    visited[row][col] = true;
    if (row+1 < n && !visited[row+1][col])
        dfs(row+1, col, n, m, visited);

    if (row-1 >= 0 && !visited[row-1][col])
        dfs(row-1, col, n, m, visited);
    
    if (col+1 < m && !visited[row][col+1])
        dfs(row, col+1, n, m, visited);

    if (col-1 >= 0 && !visited[row][col-1])
        dfs(row, col-1, n, m, visited);
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<char>> symbols(n,std::vector<char>(m));
    std::vector<std::vector<bool>> visited(n,std::vector<bool>(m, false));
    //Read Inputs
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            std::cin >> symbols[i][j];
            if (symbols[i][j] == '#')
                visited[i][j] = true;            
        }    

    //Visit all the nodes in the grid
    int connected_components = 0;
    for (int row = 0; row < n; row++)
        for (int col = 0; col < m; col++)
        {
            if (!visited[row][col])
            {
                dfs(row, col, n, m, visited);
                connected_components++;
            }
        }
    std::cout << connected_components << std::endl;
}