#include <iostream>
#include <vector>
typedef long long ll;

int main()
{
    int n,x;
    std::cin >> n >> x;
    int mod = 1e9 + 7;
    std::vector<int> coins(n);
    for (int i =0; i<n; i++)
        std::cin >> coins[i];

    std::vector<ll> numberOfCombinations(x+1,0);
    numberOfCombinations[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (j - coins[i] >= 0)
                numberOfCombinations[j] = (numberOfCombinations[j] + 
                                            numberOfCombinations[j - coins[i]]) % mod;
        }
    }
    std::cout << numberOfCombinations[x] << std::endl;
}