#include <iostream>
#include <vector>
typedef long long ll;

int main()
{
    int tests;
    std::cin >> tests;
    int maxHeight = 1e6;
    int mod = 1e9 + 7;
    std::vector<std::vector<ll>> heightsAndStates(maxHeight+1, std::vector<ll>(9,0));
    for (int i = 1; i < 9; i++)
        heightsAndStates[1][i] = 1;

    for (int height = 2; height < maxHeight+1; height++)
    {
        for (int j = 1; j < 9; j++)
        {
            if (j == 2 || j == 7 || j == 8)
            {
                heightsAndStates[height][j] = (heightsAndStates[height-1][3] +
                                               heightsAndStates[height-1][7] +
                                               heightsAndStates[height-1][8]) % mod;

            }
            else
            {
                heightsAndStates[height][j] = (heightsAndStates[height-1][1] +
                                               heightsAndStates[height-1][2] +
                                               heightsAndStates[height-1][4] +
                                               heightsAndStates[height-1][5] +
                                               heightsAndStates[height-1][6]) % mod;
            }
        }
    }
    int num;
    for (int i = 0; i < tests; i++)
    {
        std::cin >> num;
        std::cout << (heightsAndStates[num][3] + heightsAndStates[num][7]) % mod << '\n';
    }
}