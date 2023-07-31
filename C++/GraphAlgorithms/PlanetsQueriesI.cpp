#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, q;
    std::cin >> n >> q;
    int LOG = 31;
    int dp[200005][31];
    for (int i = 1; i < n+1; i++)
        std::cin >> dp[i][0];

    for (int j = 1; j < LOG; j++)
        for (int i = 1; i < n+1; i++)
            dp[i][j] = dp[ dp[i][j-1] ][j-1];

    int x, k, j;
    for (int i = 0; i < q; i++)
    {
        std::cin >> x >> k;
        j = 0;
        while (k)
        {
            if (1 & k)
                x = dp[x][j];
            k = k >> 1;
            j++;
        }
        std::cout << x << '\n';
    }
}