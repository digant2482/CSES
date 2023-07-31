#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

int chessboard[9][9];
int x_move[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int y_move[] = {-1,  1, -2,  2,-2, 2,-1, 1};
bool is_valid(int x, int y)
{
    if (x < 1 || y < 1 || x > 8 || y > 8)
        return false;
    if (chessboard[x][y] != 0)
        return false;
    return true;
}

int find_degree(int x, int y)
{
    int d = 0;
    for (int i = 0; i < 8; i++)
    {
        int neighbour_x = x + x_move[i];
        int neighbour_y = y + y_move[i];
        if (is_valid(neighbour_x, neighbour_y))
            d++;
    }
    return d;
}

bool go(int x, int y, int move)
{
    chessboard[x][y] = move;
    if (move == 64)
        return true;
    std::vector<std::tuple<int,int,int>> v;
    for (int i = 0; i < 8; i++)
    {
        int neighbour_x = x + x_move[i];
        int neighbour_y = y + y_move[i];
        if (is_valid(neighbour_x, neighbour_y))
        {
            int d = find_degree(neighbour_x, neighbour_y);
            v.push_back({d, neighbour_x, neighbour_y});
        }
    }
    std::sort(v.begin(), v.end()); //Lowest degree are processed first for faster execution
    for (auto [d,x1,y1]:v)
        if(go(x1,y1,move+1))
            return true;                

    chessboard[x][y] = 0;
    return false;
}

int main()
{
    int x, y;
    std::cin >> y >> x; //Rows and columns are alternated
    go(x,y,1);
    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9; j++)
            std::cout << chessboard[i][j] << " ";
        std::cout << '\n';
    }
}