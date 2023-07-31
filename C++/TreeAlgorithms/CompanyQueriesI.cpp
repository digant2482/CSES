#include <bits/stdc++.h>

int dp[200005][22];

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, q;
    std::cin >> n >> q;
    for (int i = 2; i < n+1; i++)
        std::cin >> dp[i][0];
    
    for (int j = 1; j < 22; j++)
        for (int i = 1; i < n+1; i++)
            dp[i][j] = dp[ dp[i][j-1] ][j-1];

    int employee, levels;
    while (q--)
    {
        std::cin >> employee >> levels;
        int pos = log2(levels);
        levels -= (1 << pos);
        int boss = dp[employee][pos];
        while (levels >= 1)
        {
            pos = log2(levels);
            levels -= (1 << pos);  
            boss = dp[boss][pos];
        }
        if (boss == 0)
            std::cout << -1 << '\n';
        else
            std::cout << boss << '\n';
    }
}