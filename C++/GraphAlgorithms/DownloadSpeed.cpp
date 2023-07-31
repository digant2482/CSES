#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>

int n, m;
int delta = 1;
std::vector<std::vector<std::tuple<int, int, int>>> g;
bool visited[505];

int dfs(int node, int flow)
{
    if (node == n)
        return flow;
    visited[node] = true;
    for (auto &[to, remaining_cap, residual_idx] : g[node])
    {
        if (remaining_cap >= delta && !visited[to])
        {
            int bottle_neck = dfs(to, std::min(flow, remaining_cap));
            if (bottle_neck > 0)
            {
                remaining_cap -= bottle_neck;
                std::get<1>(g[to][residual_idx]) += bottle_neck;
                return bottle_neck;
            }
        } 
    }
    return 0;
}

int main()
{
    std::cin >> n >> m;
    g.resize(n+1);
    int max_speed = 0;
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        std::cin >> a >> b >> c;
        int b_size = g[b].size();
        int a_size = g[a].size();
        g[a].push_back({b, c, b_size}); //to, max_weight, idx_residul
        g[b].push_back({a, 0, a_size}); //Residual edge
        max_speed = std::max(max_speed, c);
    }

    //To increase speed of DFS only takes path with greater max_speed first
    while (delta*2 < max_speed)
        delta *= 2;

    long long ans = 0;
    while (delta)
    {
        int f = -1;
        while(1)
        {
            memset(visited, false, sizeof(visited));
            int f = dfs(1, 2e9);
            ans += f;  
            if (f == 0)
                break;
        }
        delta = delta >> 1;

    }
    std::cout << ans << std::endl;
}