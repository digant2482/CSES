#include <iostream>
#include <vector>
typedef long long ll;

int main()
{
    int n, max_weight;
    std::cin >> n >> max_weight;
    std::vector<int> persons(n);
    for (int i = 0; i < n; i++)
        std::cin >> persons[i];
    
    int limit = 1 << n;
    std::vector<std::pair<ll,ll>> dp(limit);
    dp[0] = {1,0};
    for (int mask = 1; mask < limit; mask++)
    {
        std::pair<ll,ll> best_result = {1e18, 1e18};
        for (int i = 0; i < n; i++)
        {
            if (((1 << i) & mask) == 0)
                continue;
    
            auto val = dp[(1 << i) ^ mask];
            if (val.second + persons[i] <= max_weight)
                val.second += persons[i];
            else
            {
                val.first++;
                val.second = persons[i];
            }
            best_result = std::min(best_result, val);
        }
        dp[mask] = best_result;
    }
    std::cout << dp[limit-1].first << std::endl;
}