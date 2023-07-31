#include <bits/stdc++.h>
 
int n;
std::vector<std::vector<int>> g;
int max_distance = 0;
int max_distance_node = 0;
void dfs(int node, int dist, int parent)
{
    if (dist > max_distance)
    {
        max_distance = dist;
        max_distance_node = node;
    }   
    for (int child : g[node])
        if (child != parent)
            dfs(child, dist + 1, node);
}
 
int main()
{
    std::cin >> n;
    if (n == 1)
        {std::cout << 0; return 0;}
    g.resize(n+1);
    int a, b;
    for (int i = 1; i < n+1; i++)
    {
        std::cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    dfs(1, 0, 0);
    dfs(max_distance_node, 0, 0);
    std::cout << max_distance;
}