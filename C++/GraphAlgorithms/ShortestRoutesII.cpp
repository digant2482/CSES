#include <iostream>
#include <vector>
typedef long long ll;
int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<std::vector<ll>> dp(n+1, std::vector<ll>(n+1, 1e15));
	for(int i = 1; i <= n; ++i)
		dp[i][i] = 0;
	
    for (int i = 0; i < m; i++)
    {
        int r1, r2;
        ll len;
        std::cin >> r1 >> r2 >> len;
        dp[r1][r2] = dp[r2][r1] = std::min(dp[r1][r2],len);
    }

    for (int k = 1; k < n+1; k++)
        for (int i = 1; i < n+1; i++)
            for (int j = 1; j < n+1; j++)
                dp[i][j] = std::min(dp[i][j],dp[i][k] + dp[k][j]);   

    int c1, c2;
    for (int i = 0; i < q; i++)
    {
        std::cin >> c1 >> c2;
        if (dp[c1][c2] == 1e15)
            std::cout << -1 << '\n';
        else
            std::cout << dp[c1][c2] << '\n';
    }
}