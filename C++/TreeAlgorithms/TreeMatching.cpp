#include <bits/stdc++.h>

int n;
std::vector<std::vector<int>> g;
bool visited[200005];
std::vector<int> topo_order;

void dfs(int node)
{
    visited[node] = true;
    for (int child : g[node])
        if (!visited[child])
            dfs(child);
    topo_order.push_back(node);
}

int main()
{
    std::cin >> n;
    if (n == 1)
    {
        std::cout << 0;
        return 0;
    }
    g.resize(n+1);
    int a, b;
    for (int i = 1; i < n+1; i++)
    {
        std::cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);  
    }

    dfs(1);

    int edges = 0;
    memset(visited, false, sizeof(visited));
    for (int num : topo_order)
    {
        if (!visited[num] && g[num].size() != 0)
        {
            visited[num] = true;
            for (int child : g[num])
                if (!visited[child])
                {
                    visited[child] = true;
                    edges++;
                    break;
                }
        }
    }
    std::cout << edges << std::endl;
}