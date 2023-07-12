#include <iostream>
#include <vector>

int main()
{
    int a, b;
    std::cin >> a >> b;
    int upperLimit = std::max(a,b);
    std::vector<std::vector<int>> minMoves(upperLimit+1, std::vector<int>(upperLimit+1, 1e9));
    
    for (int row = 1; row < upperLimit + 1; row++)
        for (int col = 1; col < upperLimit + 1; col++)
        {
            if (row != col)
            {
                for (int i = 1; i < row; i++)
                    minMoves[row][col] = std::min(minMoves[row][col], 1 + minMoves[row-i][col] + minMoves[i][col]);

                for (int i = 1; i < col; i++)
                    minMoves[row][col] = std::min(minMoves[row][col], 1 + minMoves[row][col-i] + minMoves[row][i]);
            }
            else
                minMoves[row][col] = 0;
        }
    std::cout << minMoves[a][b] << std::endl;    
}