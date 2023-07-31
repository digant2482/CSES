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

void dfs2(int node)
{
    if (visited[node])
        return;
    visited[node] = true;
    for (auto [i, w, j] : g[node])
        if (w>0)
            dfs2(i);
}

int main()
{
    std::cin >> n >> m;
    g.resize(n+1);
    int max_speed = 0;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        std::cin >> a >> b;
        int b_size = g[b].size();
        int a_size = g[a].size();
        g[a].push_back({b, 1, b_size}); //to, max_weight, idx_residul
        g[b].push_back({a, 1, a_size}); //Residual edge
        max_speed = std::max(max_speed, 1);
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
    std::cout << ans << '\n';
    memset(visited, false, sizeof(visited));
    dfs2(1);
    visited[n] = false;
    for (int i = 1; i < n+1; i++)
        if (visited[i])
            for (auto [ii, ww, jj] : g[i])
                if (!visited[ii])
                    std::cout << i << " " << ii << " ";  
}