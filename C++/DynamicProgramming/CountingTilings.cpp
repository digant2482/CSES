#include <iostream>
#include <vector>

std::vector<std::vector<int>> dp(1001, std::vector<int>(1<<11, 0));
int mod = 1e9 + 7;

void generate_next_masks(int curr_mask, int i, int next_mask, int n, std::vector<int>& next_masks)
{
    if (i == n+1)
    {
        next_masks.push_back(next_mask);
        return;
    }  

    //Check if position is occupied, if occupied move to next box
    if ((curr_mask & (1 << i)) != 0)
        generate_next_masks(curr_mask, i+1, next_mask, n, next_masks);

    //Vertical tilings
    if (i != n)
        if (((curr_mask & (1 << i)) == 0) && (((curr_mask & 1 << (i+1)) == 0)))
            generate_next_masks(curr_mask, i+2, next_mask, n, next_masks);
    
    //Horizontal tilings
    if ((curr_mask & (1 << i)) == 0)
        generate_next_masks(curr_mask, i+1, next_mask ^ (1 << i), n, next_masks);
}
int count = 0;
int solve(int col, int mask, const int m, const int n)
{
    if (col == m + 1) 
    {
        if (mask == 0)
            return 1;
        return 0;
    }
    
    if (dp[col][mask] != 0)
        return dp[col][mask];

    int answer = 0;
    std::vector<int> next_masks;
    generate_next_masks(mask, 1, 0, n, next_masks);
    for (int next_mask : next_masks)
        answer = (answer + solve(col+1, next_mask, m, n)) % mod;
    
    return dp[col][mask] = answer;
}
int main()
{
    int n, m;
    std::cin >> n >> m;
    if (n % 2 == 1 && m % 2 == 1)
        std::cout << 0 << std::endl;
    else
        std::cout << solve(1, 0, m, n) << std::endl;
}