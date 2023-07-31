#include <iostream>
#include <vector>

int n, m;
std::vector<std::vector<int>> g;
int mod = 1e9 + 7;
std::vector<int> dp;

int dfs(int node)
{
    if (node == n)
        return 1;
    if (g[node].size() == 0)
        return 0;
    if (dp[node] != -1)
        return dp[node];  

    int total = 0;
    for (int child : g[node])
        total = (total + dfs(child)) % mod;

    dp[node] = total;
    return total;  
}

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> n >> m;
    g.resize(n+1);
    dp.resize(n+1, -1);
    int l1, l2;
    for (int i = 0; i < m; i++)
    {
        std::cin >> l1 >> l2;
        g[l1].push_back(l2);
    }

    dfs(1);
    std::cout << dp[1] << std::endl;
}