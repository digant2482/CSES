#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> coins(n);
    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> coins[i];
        maxSum += coins[i];
    }
    
    std::vector<std::vector<int>> sums(n+1, std::vector<int>(maxSum+1,0));
    for (int i = 0; i < n+1; i++)
        sums[i][0] = 1;
    
    for (int i = 1; i < n + 1; i++)
        for (int sum = 1; sum < maxSum+1; sum++)
        {
            sums[i][sum] = sums[i-1][sum];
            if (sum - coins[i-1] >= 0 && sums[i-1][sum - coins[i-1]])
                sums[i][sum] = 1;
        }
            
    std::cout << std::accumulate(sums[n].begin(), sums[n].end(),0) - 1<< std::endl;
    for (int i = 1; i < maxSum + 1; i++)
        if (sums[n][i]) 
            std::cout << i << " ";
}