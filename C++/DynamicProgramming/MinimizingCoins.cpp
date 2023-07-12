#include <iostream>
#include <vector>

typedef long long ll;

int main()
{
    int n, x;
    std::cin >> n >> x;
    std::vector<int> coins(n);
    for (int i = 0; i < n; i++)
        std::cin >> coins[i]; 

    std::vector<int> num_of_coins(x+1, 1e9);
    num_of_coins[0] = 0;    
    for (int value = 1; value <= x; value++)
    {
        for (int j = 0; j < n; j++)
        {
            if (value - coins[j] >= 0) 
                num_of_coins[value] = std::min(num_of_coins[value], num_of_coins[value - coins[j]] + 1); 
        }
    }
    std::cout << (num_of_coins[x] != 1e9 ? num_of_coins[x] : -1) << std::endl;
}