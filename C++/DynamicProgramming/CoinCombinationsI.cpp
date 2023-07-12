#include <iostream>
#include <vector>
typedef long long ll;

int main()
{
    int n,x;
    std::cin >> n >> x;
    int mod = 1e9 + 7;
    std::vector<int> coins(n);

    for(int i = 0; i<n; i++)
        std::cin >> coins[i];
     
    std::vector<ll> desired_sum_array(x+1,0);
    desired_sum_array[0] = 1;

    for(int i = 1; i <= x; i++)
    {
        ll num_ways = 0;
        for(int j = 0; j<n; j++)
        {
            if(i - coins[j] >=0)
                num_ways += desired_sum_array[i - coins[j]];
        }
        desired_sum_array[i] = num_ways % mod;     
    }
    std::cout << desired_sum_array[x] << std::endl;
}