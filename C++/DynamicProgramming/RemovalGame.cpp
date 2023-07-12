#include <iostream>
#include <vector>
typedef long long ll;

int main()
{
    int n;
    std::cin >> n;
    std::vector<ll> values(n);
    std::vector<std::vector<ll>> max_difference_for_interval(n, std::vector<ll>(n));
    ll sum_of_all_values = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> values[i];
        max_difference_for_interval[i][i] = values[i];
        sum_of_all_values += values[i];
    } 

    for (int left = n-1; left >= 0; left--)
    {
        for (int right = left+1; right < n; right++)
        {
            max_difference_for_interval[left][right] = std::max(values[left]-(max_difference_for_interval[left+1][right]), 
                                                            values[right] - max_difference_for_interval[left][right-1]);         
        }
    }  
    std::cout <<  (max_difference_for_interval[0][n-1] + sum_of_all_values)/2 << std::endl;
}