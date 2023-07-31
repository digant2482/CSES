#include <bits/stdc++.h>
int dp[200005][19];
std::vector<int> tree;
int depth[200005];
bool visited[200005];

int dfs(int node)
{
    if (node == 1)
        return 0;
    visited[node] = true;
    int par = tree[node];
    if (!visited[par])
        depth[node] = dfs(par) + 1;
    else
        depth[node] = depth[par] + 1;
    return depth[node];    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, q;
    std::cin >> n >> q;
    tree.resize(n+1);
    for (int i = 2; i < n+1; i++)
    {
        std::cin >> dp[i][0];
        tree[i] = dp[i][0];
    }

    for (int i = 1; i < n+1; i++)
        if (!visited[i])
            dfs(i);  

    for (int j = 1; j < 19; j++)
        for (int i = 1; i < n+1; i++)
            dp[i][j] = dp[ dp[i][j-1] ][j-1];

    int e1, e2;
    while (q--)
    {
        std::cin >> e1 >> e2;
        if (depth[e1] != depth[e2])
        {
            if (depth[e1] > depth[e2])
                std::swap(e1,e2);
            int levels = depth[e2] - depth[e1];
            int pos = log2(levels);
            levels -= (1 << pos);
            e2 = dp[e2][pos];
            while (levels >= 1)
            {
                pos = log2(levels);
                levels -= (1 << pos);  
                e2 = dp[e2][pos];
            }
        }

        if (e1 == e2)
            std::cout << e2 << '\n';
        else
        {
            int LOG = 18;
            while (LOG >= 0)
            {
                if (dp[e1][LOG] != dp[e2][LOG])
                {
                    e1 = dp[e1][LOG];
                    e2 = dp[e2][LOG];
                }
                LOG--;
            } 
            std::cout << dp[e1][0] << '\n';  
        }
    } 
}