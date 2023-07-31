#include <bits/stdc++.h>
int dp[200005][19];
std::vector<std::vector<int>> tree;
int depth[200005];

void dfs(int node, int par)
{
    for (int child : tree[node])
        if (child != par)
        {
            dp[child][0] = node;
            depth[child] = depth[node] + 1;
            dfs(child, node);
        }
}

int raise(int node, int dist)
{
    if (dist == 0)
        return node;
    while (dist >= 1)
    {
        int pos = log2(dist);
        dist -= (1 << pos);  
        node = dp[node][pos];
    }
    return node;
}

int lca(int a, int b)
{
    if (depth[a] > depth[b])
        std::swap(a,b);
    b = raise(b, depth[b] - depth[a]);
    if (a == b)
        return a;
    else
    {
        int LOG = 18;
        while (LOG >= 0)
        {
            if (dp[a][LOG] != dp[b][LOG])
            {
                a = dp[a][LOG];
                b = dp[b][LOG];
            }
            LOG--;
        } 
        return dp[a][0];
    } 
}

int start[200005]; 
int stop[200005];
int c[200005]; //Node is LCA in a path
int ans[200005];
void dfs2(int node, int par)
{
    for (int child : tree[node])
        if (child != par)
        {
            dfs2(child, node);
            start[node] += start[child];
        }
    ans[node] = start[node] - c[node]; //Remove duplicate paths where LCA is the node itself
    start[node] -= stop[node];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, q;
    std::cin >> n >> q;
    tree.resize(n+1);
    int n1, n2;
    for (int i = 0; i < n-1; i++)
    {
        std::cin >> n1 >> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }

    dfs(1, 0);
    for (int j = 1; j < 19; j++)
        for (int i = 1; i < n+1; i++)
            dp[i][j] = dp[ dp[i][j-1] ][j-1];

    int e1, e2;
    while (q--)
    {
        std::cin >> e1 >> e2;
        int z = lca(e1, e2); 
        start[e1]++, start[e2]++, stop[z]+=2;
        if (e1 != z && e2 != z)
            c[z]++; //z is LCA
        else
        {
            start[z]--;
            stop[z]--;
        }
    }
    dfs2(1, 0);
    for (int i = 1; i < n+1; i++)
        std::cout << ans[i] << " ";

}   