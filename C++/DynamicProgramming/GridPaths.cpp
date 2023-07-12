#include <iostream>
#include <vector>
typedef long long ll;

int main()
{
    int n;
    std::cin >> n;
    int mod = 1e9 + 7;
    std::vector<std::string> invalidPos(n);
    for (int i = 0; i < n; i++)
        std::cin >> invalidPos[i];

    std::vector<std::vector<ll>> numberOfPaths(n,std::vector<ll>(n,0));
    numberOfPaths[0][0] = (invalidPos[0][0] != '*');
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (invalidPos[i][j] != '*')
            {
                if (i - 1 >= 0 && invalidPos[i-1][j] != '*')
                    numberOfPaths[i][j] = numberOfPaths[i-1][j] % mod;
                if (j - 1 >= 0 && invalidPos[i][j-1] != '*')
                    numberOfPaths[i][j] = (numberOfPaths[i][j] + numberOfPaths[i][j-1]) % mod;
            }   
        }
    }
    std::cout << numberOfPaths[n-1][n-1] << std::endl;    
}