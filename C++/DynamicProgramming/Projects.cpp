#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct Elements
{
    int start, end, reward;
};

bool cmp(const Elements& a, const Elements& b)
{
    return a.end < b.end;
}

typedef long long ll; 
int main()
{
    int n;
    std::cin >> n;
    std::vector<Elements> array(n);
    for (int i = 0; i < n; i++)
        std::cin >> array[i].start >> array[i].end >> array[i].reward;

    sort(array.begin(), array.end(), cmp);
    std::map<int,ll> end_value_rewards;
    ll max_reward = -1e18;
    for (int i = 0; i < n; i++)  
    {
        ll curr_reward = array[i].reward;
        auto itr = end_value_rewards.lower_bound(array[i].start);
        if (itr != end_value_rewards.begin())
            curr_reward += (*--itr).second;

        max_reward = std::max(max_reward, curr_reward);
        end_value_rewards[array[i].end] = max_reward;
    }
    std::cout << max_reward << std::endl;
}