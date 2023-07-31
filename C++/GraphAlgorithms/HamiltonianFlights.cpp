#include <iostream>
#include <vector>
#include <cstring>
typedef long long ll;

int n, m;
int mod = 1e9 + 7;
std::vector<std::vector<int>> g;
ll dp[21][2000005];

ll dfs(int node, int mask)
{
    if (node == n)
    {
        if (mask == ((1 << n) - 1))
            return 1;
        else    
            return 0;
    }
    if (dp[node][mask] != -1)
        return dp[node][mask];

    ll answer = 0;
    for (int child : g[node])
    {
        if (mask & (1 << (child-1)))
            continue;
        answer += dfs(child, (mask | (1 << (child-1))));
    }
    answer %= mod;
    return dp[node][mask] = answer;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> n >> m;
    g.resize(n+1);
    int c1, c2;
    for (int i = 0; i < m; i++)
    {
        std::cin >> c1 >> c2;
        g[c1].push_back(c2);
    }

    std::memset(dp, -1, sizeof(dp));
    int answer = dfs(1, 1);
    std::cout << answer << std::endl;
}